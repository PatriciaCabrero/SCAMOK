#include "Fisic.h" 
 
Fisic::Fisic() { 
	collisionConfig = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfig);
	overlappingPairCache = new btDbvtBroadphase();
	ghost = new btGhostPairCallback();
	overlappingPairCache->getOverlappingPairCache()->setInternalGhostPairCallback(ghost);
	solver = new btSequentialImpulseConstraintSolver();
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfig);
}

Fisic::~Fisic() { 
	/*for each (auto var in physicsAccessors)
	{
		dynamicsWorld->removeRigidBody(var.second);
	}*/
	delete dynamicsWorld;
	delete solver;
	delete ghost;
	delete overlappingPairCache;
	delete dispatcher;
	delete collisionConfig;

	for each (auto var in collisionShapes)
	{
		delete var;
	}
} 