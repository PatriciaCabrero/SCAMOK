#include "FComponent.h"  
#include <iostream>
 
FComponent::FComponent(Entidad* pEnt, float altoCaj, float anchoCaj, float profCaj, std::string nombreNodo, bool suelo, tipoFisica type, btScalar masa):Componente(pEnt),mass(masa),altoCaja(altoCaj),anchoCaja(anchoCaj), profCaja(profCaj) {
	tipo = type;
	_suelo = suelo;
	
	trigger = nullptr;
	//Si est� vinculado a un componente gr�fico
	if (nombreNodo != " ") {

		//Muestra la caja en Ogre
		//pEntidad->getPEstado()->getScnManager()->getSceneNode(nombreNodo)->showBoundingBox(true);
		pEntidad->getPEstado()->getScnManager()->getSceneNode(nombreNodo)->_update(true, true);

		//Le pone al cuerpo coordenadas, orientaci�n y volumen (sacado del componente gr�fico)
		Ogre::Vector3 posN = pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode"+nombreNodo)->getPosition();
		Ogre::AxisAlignedBox bbox = pEntidad->getPEstado()->getScnManager()->getSceneNode(nombreNodo)->_getWorldAABB();
		Ogre::Vector3  v = bbox.getSize();
		altoCaja = v.y; 
		profCaja = v.z;
		anchoCaja = v.x;
		pTransform.setIdentity();
		pTransform.setOrigin(btVector3(posN.x, posN.y, posN.z));
		
		
		Ogre::Quaternion quat = pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode" + nombreNodo)->getOrientation();
		pTransform.setRotation(btQuaternion(quat.x, quat.y, quat.z, quat.w));//Tener en cuenta que en ogre el primer valor es w, mientras que en bullet va �ltimo.
		initBody();

		//Vincula el nodo gr�fico al f�sico
		if (trigger)
			trigger->setUserPointer(pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode" + nombreNodo));
		else
			body->setUserPointer(pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode"+nombreNodo));

		//Para poder acceder desde Fisic a los rigidbodies
		if (tipo != tipoFisica::Trigger)
			pEntidad->getPEstado()->getFisicManager()->addBodyToMap(nombreNodo, body);
		
	}

	//Si no est� vinculado a un componente gr�fico se crea por defecto en el 0,0,0 se puede reposicionar con un mensaje
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
	delete trigger;
} 

void FComponent::initBody() {
	//Aqu� ajustamos la masa
	if (tipo == tipoFisica::Estatico || tipo == tipoFisica::Trigger)
		mass = 0;

	//La inercia inicial siempre es 0
	btVector3 localInertia(0, 0, 0);

	//Aqu� hacemos la forma de la caja
	motionState = new btDefaultMotionState(pTransform);

	if (!_suelo) {
		if (tipo != tipoFisica::Trigger)
			shape = new btBoxShape(btVector3(btScalar(anchoCaja / 2), btScalar(altoCaja / 2), btScalar(profCaja / 2)));
		else {

			trigger = new btGhostObject();
			shape = new btBoxShape(btVector3(btScalar(anchoCaja / 2), btScalar(3), btScalar(profCaja / 2)));
			trigger->setCollisionShape(shape);

		}
	}
	else {
		shape = new btBoxShape(btVector3(btScalar(anchoCaja / 2), btScalar(3), btScalar(profCaja / 2)));

	}
	
	//Aqu� se inicializa el cuerpo en base a sus par�metros anteriores
	shape->calculateLocalInertia(mass, localInertia);
	pEntidad->getPEstado()->getFisicManager()->getCollisionShapes().push_back(shape);
	btRigidBody::btRigidBodyConstructionInfo RBInfo(mass, motionState, shape, localInertia);
	body = new btRigidBody(RBInfo);

	//Elasticidad del material
	body->setRestitution(0);
	
	//Para que sinbad no rote
	if (tipo == tipoFisica::Kinematico || tipo == tipoFisica::Trigger) {
		body->setAngularFactor(btVector3(0, 1, 0));
	}

	pEntidad->getPEstado()->getFisicManager()->getDynamicsWorld()->addRigidBody(body);
	if (trigger)
		pEntidad->getPEstado()->getFisicManager()->getDynamicsWorld()->addCollisionObject(trigger);

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
			//Aqu� le asignamos el transform que deber�a tener la entidad
			btTransform t;
			t.setIdentity();
			t.setOrigin(btVector3(std::stof(xS), std::stof(yS), std::stof(zS)));
			body->setWorldTransform(t);
		}
	}

	
	switch (tipo)
	{
	case Dinamico:
		break;

	//Este ser�a el caso kinematico concreto de la ni�a
	//Para los enemigos habr�a que hacer otro
	case Kinematico:
		if (msg.getTipo() == Tipo::Fisica) {
			if (msg.getSubTipo() == SubTipo::Mover) {
				body->activate(true);
				//Aqu� lo movemos con la info procedente del input
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
		
				btVector3 vel = body->getLinearVelocity();
				vel = vel + btVector3(valores.x*30,0,valores.z*30);
				body->setLinearVelocity(vel);
			}
			else if (msg.getSubTipo() == SubTipo::Salto) {
				if ((int)body->getLinearVelocity().getY() == 0) {
					std::string pos = std::to_string(body->getWorldTransform().getOrigin().getX()) + "/0/" + std::to_string(body->getWorldTransform().getOrigin().getZ());
					Mensaje msEfect(Tipo::Audio, "Play/jump.mp3/" + pos, SubTipo::Effect);
					pEntidad->getPEstado()->addMsg(msEfect);
					body->activate(true);
					body->applyCentralImpulse(btVector3(0, 2000, 0));
				}
				
			}
			else if (msg.getSubTipo() == SubTipo::Nulo) {
				btVector3 vel = body->getLinearVelocity();
				vel = vel * btVector3(0, 1, 0);
				body->setLinearVelocity(vel);
			}
		}
		break;
	}
	actualizaNodo();

	
}

//Actualiza el nodo gr�fico en base a los cambios del f�sico
void FComponent:: actualizaNodo() {

	userPointer = body->getUserPointer();

	if (userPointer) {
		btQuaternion orientation = body->getOrientation();
		btVector3 position = body->getWorldTransform().getOrigin();
		Ogre::SceneNode *sceneNode = static_cast<Ogre::SceneNode *>(userPointer);
		sceneNode->setPosition(Ogre::Vector3(position.getX() , position.getY(), position.getZ()));	
	}
}