#include "BalaComponent.h"  
#include <ctime>
#include <iostream>
 
BalaComponent::BalaComponent(Entidad* pEntidad) : Componente(pEntidad) {

	Ogre::Vector3 valores = { 1,0,1 };
	Ogre::Matrix3 matriz = pEntidad->getPEstado()->getScnManager()->getSceneNode("Alaia")->getLocalAxes();
	valores = matriz * valores;
	btVector3 pos1 = { valores.x ,0, valores.z };
	btVector3 posAux = pos1.rotate(btVector3(0, 1, 0), -3.141596 / 4);
	string posOgro = to_string(posAux.getX() * 6 + pEntidad->getPEstado()->getFisicManager()->getRigidBody("Alaia")->getWorldTransform().getOrigin().getX()) + "/" +
		to_string(pEntidad->getPEstado()->getFisicManager()->getRigidBody("Alaia")->getWorldTransform().getOrigin().getY()) + "/" +
		to_string(posAux.getZ() * 6 + pEntidad->getPEstado()->getFisicManager()->getRigidBody("Alaia")->getWorldTransform().getOrigin().getZ());

	Mensaje ms(Tipo::Fisica, posOgro, SubTipo::Reposicionar);
	Mensaje ms1(Tipo::Fisica, "10", SubTipo::Dispara);
	ms.setMsgInfo(pEntidad, pEntidad);
	ms1.setMsgInfo(pEntidad, pEntidad);
	pEntidad->getPEstado()->addMsg(ms);
	pEntidad->getPEstado()->addMsg(ms1);


	tiempoInicio = std::clock()* 1000;
	std::cout << "CREADOOO\n";
	

} 
BalaComponent::~BalaComponent() { 
}

void BalaComponent::Update(float deltaTime, Mensaje const & msj)
{
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);

	if (msg.getTipo() == Tipo::Fisica) {
		if (msg.getSubTipo() == SubTipo::Dispara) {
			Ogre::Real escala = std::stof(msg.getMsg());

			btRigidBody* alaia = pEntidad->getPEstado()->getFisicManager()->getRigidBody("Alaia");
			btVector3 start = alaia->getWorldTransform().getOrigin();

			Ogre::Vector3 valores = { escala,0,escala };
			Ogre::Matrix3 matriz = pEntidad->getPEstado()->getScnManager()->getSceneNode("Alaia")->getLocalAxes();

			valores = matriz * valores;

			btVector3 vel = { valores.x ,0, valores.z };
			btVector3 velAux = vel.rotate(btVector3(0, 1, 0), -3.141596 / 4);

			btVector3 auxx(velAux.getX(), velAux.getY(), velAux.getZ() + 1000);

			btCollisionWorld::ClosestRayResultCallback RayCallback(start, auxx);
			pEntidad->getPEstado()->getFisicManager()->getDynamicsWorld()->rayTest(start, auxx, RayCallback);

			if (RayCallback.hasHit()) {
				auxx = RayCallback.m_hitPointWorld;
				std::cout << "EYY";
			}

			pEntidad->getPEstado()->getFisicManager()->getRigidBody(pEntidad->getNombreNodo())->setLinearFactor({ 1, 0, 1 });
			pEntidad->getPEstado()->getFisicManager()->getRigidBody(pEntidad->getNombreNodo())->applyImpulse(velAux * 10, start);


		}
		if (tiempoInicio + /*5000000*/1000000  < std::clock() * 1000) {
			pEntidad->Sleep();
			pEntidad->getPEstado()->destroy(pEntidad->getNombreNodo());
			std::cout << "MUERE\n";
		}
	}

}
