#include "FComponent.h"  
#include <iostream>
 
FComponent::FComponent(Entidad* pEnt, float altoCaj, float anchoCaj, float profCaj, std::string nombreNodo, bool suelo, tipoFisica type, int masa):Componente(pEnt),masa(masa),altoCaja(altoCaj),anchoCaja(anchoCaj), profCaja(profCaj) {
	tipo = type;
	
	Ogre::AxisAlignedBox bbox;
	//Si está vinculado a un componente gráfico
	if (nombreNodo != " ") {
		//Muestra la caja en Ogre
		pEntidad->getPEstado()->getScnManager()->getSceneNode(nombreNodo)->showBoundingBox(true);
		pEntidad->getPEstado()->getScnManager()->getSceneNode(nombreNodo)->_update(true, true);

		//Le pone al cuerpo coordenadas, orientación y volumen (sacado del componente gráfico)
		Ogre::Vector3 posN = pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode"+nombreNodo)->getPosition();
		bbox = pEntidad->getPEstado()->getScnManager()->getSceneNode(nombreNodo)->_getWorldAABB();
		Ogre::Vector3  v = bbox.getSize();
		altoCaja = v.y;
		profCaja = v.z;
		anchoCaja = v.x;
		pTransform.setIdentity();
		pTransform.setOrigin(btVector3(posN.x, posN.y, posN.z));
		Ogre::Quaternion quat = pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode" + nombreNodo)->getOrientation();
		pTransform.setRotation(btQuaternion(quat.x, quat.y, quat.z, quat.w));//Tener en cuenta que en ogre el primer valor es w, mientras que en bullet va último.
		initBody();

		//Vincula el nodo gráfico al físico
		body->setUserPointer(pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode"+nombreNodo));

		//Para poder acceder desde Fisic a los rigidbodies
		pEntidad->getPEstado()->getFisicManager()->addBodyToMap(nombreNodo, body);
	}

	//Si no está vinculado a un componente gráfico se crea por defecto en el 0,0,0 se puede reposicionar con un mensaje
	else {
		tipo = tipoFisica::Estatico;
		pTransform.setIdentity();
		pTransform.setOrigin(btVector3(0.0, 0.0, 0.0));
		initBody();
	}
	actualizaNodo();
} 

FComponent::~FComponent() { 
	delete body;
	delete motionState;
	delete shape;
} 

void FComponent::initBody() {
	//Aquí ajustamos la masa
	if (tipo != tipoFisica::Estatico)
		mass = masa;
	else
		mass = 0;
	//La inercia inicial siempre es 0
	btVector3 localInertia(0, 0, 0);

	//Aquí hacemos la forma de la caja
	shape = new btBoxShape(btVector3(btScalar(anchoCaja/2), btScalar(altoCaja/2), btScalar(profCaja/2)));

	//Aquí se inicializa el cuerpo en base a sus parámetros anteriores
	motionState = new btDefaultMotionState(pTransform);
	shape->calculateLocalInertia(mass, localInertia);
	pEntidad->getPEstado()->getFisicManager()->getCollisionShapes().push_back(shape);
	btRigidBody::btRigidBodyConstructionInfo RBInfo(mass, motionState, shape, localInertia);
	body = new btRigidBody(RBInfo);

	//Elasticidad del material
	body->setRestitution(0);

	pEntidad->getPEstado()->getFisicManager()->getDynamicsWorld()->addRigidBody(body);

}

void FComponent::Update(float deltaTime, Mensaje const & msj) {
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);

	if (msg.getTipo() == Tipo::Fisica) {
		if (msg.getSubTipo() == SubTipo::Reposicionar) {
			int pos = msg.getMsg().find("/");
			std::string xS = msg.getMsg().substr(0, pos);
			std::string subcad = msg.getMsg().substr(pos + 1);
			pos = subcad.find("/");
			std::string yS = subcad.substr(0, pos);
			std::string zS = subcad.substr(pos + 1);
			//Aquí le asignamos el transform que debería tener la entidad
			btTransform t;
			t.setIdentity();
			t.setOrigin(btVector3(std::stof(xS), std::stof(yS), std::stof(zS)));
			body->setWorldTransform(t);
		}
	}
	std::string ms = "";
	
	switch (tipo)
	{
	case Dinamico:
		break;

	//Este sería el caso kinematico concrero de la niña
	//Para los enemigos habría que haacer otro
	case Kinematico:
		btVector3 vel;
		if (msg.getTipo() == Tipo::Fisica) {
			if (msg.getSubTipo() == SubTipo::Mover) {
				body->activate(true);
				//Aquí lo movemos con la info procedente del input
				int pos = msg.getMsg().find("/");
				std::string xS = msg.getMsg().substr(0, pos);
				std::string subcad = msg.getMsg().substr(pos + 1);
				pos = subcad.find("/");
				std::string yS = subcad.substr(0, pos);
				std::string zS = subcad.substr(pos + 1);
				float xF= std::stof(xS);
				float zF = std::stof(zS);
				Ogre::Vector3 valores = { xF,0,zF };
				Ogre::Matrix3 matriz = pEntidad->getPEstado()->getScnManager()->getSceneNode("NodoCamera")->getLocalAxes();

				 valores = matriz * valores;
		
				vel = body->getLinearVelocity();
				vel = vel + btVector3(valores.x*30,0,valores.z*30);

				body->setLinearVelocity(vel);
			}
			else if (msg.getSubTipo() == SubTipo::Salto) {
				if ((int)body->getLinearVelocity().getY() == 0) {
					std::string pos = std::to_string(body->getWorldTransform().getOrigin().getX()) + "/0/" + std::to_string(body->getWorldTransform().getOrigin().getZ());
					Mensaje msEfect(Tipo::Audio, "Play/jump.mp3/" + pos, SubTipo::Effect);
					pEntidad->getPEstado()->addMsg(msEfect);
					body->activate(true);
					body->applyCentralImpulse(btVector3(0, 1500, 0));
				}
				
			}
			else if (msg.getSubTipo() == SubTipo::Nulo) {
				vel = body->getLinearVelocity();
				vel = vel * btVector3(0, 1, 0);
				body->setLinearVelocity(vel);

			}
			
		}
		
		break;
	}
	actualizaNodo();

	
}

//Actualiza el nodo gráfico en base a los cambios del físico
void FComponent:: actualizaNodo() {
	userPointer = body->getUserPointer();
	if (userPointer) {
		btQuaternion orientation = body->getOrientation();
		btVector3 position = body->getWorldTransform().getOrigin();
		Ogre::SceneNode *sceneNode = static_cast<Ogre::SceneNode *>(userPointer);
		sceneNode->setPosition(Ogre::Vector3(position.getX() , position.getY(), position.getZ()));
		
	}
}