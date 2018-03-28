#include "FComponent.h"  
 
FComponent::FComponent(Entidad* pEnt, float altoCaj, float anchoCaj, float profCaj, bool suelo, tipoFisica type, int masa):Componente(pEnt),masa(masa),altoCaja(altoCaj),anchoCaja(anchoCaj), profCaja(profCaj) {
	tipo = type;
	if (suelo) {
		///////////////////DIMENSIONES DEL SUELO//////////////////////
		anchoCaja = 50;
		altoCaja = 0;
		profCaja = 50;
	}
} 

FComponent::~FComponent() { 
	delete body;
	delete motionState;
	delete shape;
} 

void FComponent::initBody() {
	//Aquí ajustamos la masa
	if (tipo == tipoFisica::Dinamico)
		mass = masa;
	else
		mass = 0;
	//La inercia inicial doy por supuesto que siempre es 0
	btVector3 localInertia(0, 0, 0);

	//Aquí hacemos la forma de la caja
	shape = new btBoxShape(btVector3(btScalar(anchoCaja), btScalar(altoCaja), btScalar(profCaja)));

	//Aquí se inicializa el cuerpo en base a sus parámetros anteriores
	motionState = new btDefaultMotionState(pTransform);
	shape->calculateLocalInertia(mass, localInertia);
	//La siguiente linea no sé si es necesaria para el suelo
	pEntidad->getPEstado()->getFisicManager()->getCollisionShapes().push_back(shape);
	btRigidBody::btRigidBodyConstructionInfo RBInfo(mass, motionState, shape, localInertia);
	body = new btRigidBody(RBInfo);
	//La siguiente linea no sé si es necesaria para el suelo
	body->setRestitution(1);
	pEntidad->getPEstado()->getFisicManager()->getDynamicsWorld()->addRigidBody(body);
	//La siguiente linea no sé si es necesaria para el suelo
	//physicsEngine->trackRigidBodyWithName(body, physicsCubeName);
}

void FComponent::Update(float deltaTime, Mensaje const & msj) {
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);

	//Esto es lo que hace en el primer update de todos, para colocar el cuerpo en su lugar
	//y setear su alto, ancho y profundidad, masa, etc
	if (msg.getTipo() == Tipo::Fisica) {
		if (msg.getSubTipo() == SubTipo::InitFis) {
			int pos = msg.getMsg().find("/");
			std::string xS = msg.getMsg().substr(0, pos);
			std::string subcad = msg.getMsg().substr(pos + 1);
			pos = subcad.find("/");
			std::string yS = subcad.substr(0, pos);
			std::string zS = subcad.substr(pos + 1);
			//Aquí le asignamos el transform que debería tener la entidad
			pTransform.setIdentity();
			pTransform.setOrigin(btVector3(std::stof(xS), std::stof(yS), std::stof(zS)));
			initBody();
		}
	}
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
			pTransform.setOrigin(btVector3(std::stof(xS), std::stof(yS), std::stof(zS)));
			body->setWorldTransform(t);
		}
	}
	std::string ms = "";
	Mensaje * m;
	switch (tipo)
	{
	case Dinamico:
		 ms += std::to_string(body->getWorldTransform().getOrigin().getX()) + "/"
			+ std::to_string(body->getWorldTransform().getOrigin().getY()) + "/"
			+ std::to_string(body->getWorldTransform().getOrigin().getZ());
		m = new Mensaje(Tipo::Logica, ms, SubTipo::Mover);
		m->setMsgInfo(pEntidad, pEntidad);
		pEntidad->getPEstado()->addMsg(*m);
		break;
	case Estatico:
		break;
	case Kinematico:
		if (msg.getTipo() == Tipo::Fisica) {
			if (msg.getSubTipo() == SubTipo::Mover) {
				//Aquí lo movemos con la info procedente del transform
				int pos = msg.getMsg().find("/");
				std::string xS = msg.getMsg().substr(0, pos);
				std::string subcad = msg.getMsg().substr(pos + 1);
				pos = subcad.find("/");
				std::string yS = subcad.substr(0, pos);
				std::string zS = subcad.substr(pos + 1);
				btTransform t;
				t.setIdentity();
				pTransform.setOrigin(btVector3(std::stof(xS), std::stof(yS), std::stof(zS)));
				body->setWorldTransform(t);
			}
		}
		break;
	}
}