#include "FComponent.h"  
 
FComponent::FComponent(Entidad* pEnt, tipoFisica type, int masa, bool suelo):Componente(pEnt),masa(masa) {
	tipo = type;

	//Aquí le asignamos el transform que debería tener la entidad
	pTransform.setIdentity();
	int x, y, z;
	if(pEntidad->getEntityTransform(x, y, z))
		pTransform.setOrigin(btVector3(x,y,z));
	else 
		pTransform.setOrigin(btVector3(0, 0, 0));

	//Aquí ajustamos la masa
	if (tipo == tipoFisica::Dinamico)
		mass=masa;
	else
		mass=0;
	//La inercia inicial doy por supuesto que siempre es 0
	//pero se puede cambiar
	btVector3 localInertia(0, 0, 0);

	//Si hay que hacer un plano para el suelo
	if (suelo)
		//////////////OJO 50 y 50 DEBERIAN SER LAS MEDIDAS DEL MAPA////////////////
		shape = new btBoxShape(btVector3(btScalar(50.), btScalar(0.), btScalar(50.)));
	//Si no es el suelo, en lugar de un plano, hacemos una caja 
	/*Aquí hay que meter la altura, anchura y profundidad*/else shape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));
	
	
	motionState = new btDefaultMotionState(pTransform);
	shape->calculateLocalInertia(mass, localInertia);
	btRigidBody::btRigidBodyConstructionInfo RBInfo(mass, motionState, shape, localInertia);
	body = new btRigidBody(RBInfo);
	pEnt->getPEstado()->getFisicManager()->getDynamicsWorld()->addRigidBody(body);

} 
FComponent::~FComponent() { 
	delete body;
	delete motionState;
	delete shape;
} 
