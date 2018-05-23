#include "Fisic.h" 
 
Fisic::Fisic() { 
	collisionConfig = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfig);
	overlappingPairCache = new btDbvtBroadphase();
	btCallback = new btGhostPairCallback();
	overlappingPairCache->getOverlappingPairCache()->setInternalGhostPairCallback(btCallback);
	solver = new btSequentialImpulseConstraintSolver();
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfig);
}

Fisic::~Fisic() {
	
	for each (auto var in physicsAccessors)
	{
		dynamicsWorld->removeRigidBody(var.second);
	}
	delete dynamicsWorld;
	delete solver;
	delete btCallback;
	delete overlappingPairCache;
	delete dispatcher;
	delete collisionConfig;

	for each (auto var in collisionShapes)
	{
		delete var;
	}
} 