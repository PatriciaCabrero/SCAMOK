#pragma once 

#include "Componente.h"
#include "Estado.h"
//enum tipoFisica { Dinamico, Estatico, Kinematico};

class FComponent  : public Componente { 
public: 
	FComponent(Entidad* pEnt, float altoCaja, float anchoCaja, float profCaja, bool suelo, tipoFisica type = tipoFisica::Estatico, int masa = 0/*inamovible*/);
	~FComponent(); 
	virtual void Update(float deltaTime, Mensaje const & msj);//A rellenar con el cuenta steps
	virtual void destroy() {};
	void initBody();

protected:
	float altoCaja, anchoCaja, profCaja;
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
