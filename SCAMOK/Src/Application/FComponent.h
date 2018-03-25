#pragma once 

#include "Componente.h"
#include "Estado.h"
enum tipoFisica { Dinamico, Estatico, Kinematico};

class FComponent  : public Componente { 
public: 
	FComponent(Entidad* pEnt, tipoFisica type = tipoFisica::Estatico, int masa  = 0/*inamovible*/, bool suelo = false);
	~FComponent(); 
	virtual void Update(float deltaTime, Mensaje const & msj);
	virtual void destroy();

protected:
	btTransform pTransform;
	tipoFisica tipo;
	int masa;
	btScalar mass;
	btCollisionShape* shape;
	btDefaultMotionState *motionState;
	btRigidBody* body;
	//Ogre::SceneNode * node, *groupNode;
	//Ogre::Entity * ent;
}; 
