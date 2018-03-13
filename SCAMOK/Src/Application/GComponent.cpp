
#include "GComponent.h"

GComponent::GComponent(Entidad* pEnt) : Componente (pEnt){
	
	ent = pEnt->getPEstado()->getScnManager()->createEntity("ogrehead.mesh");
	node = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
}
void GComponent::Update(float deltaTime,  Mensaje const & msj) { 
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);
	if (msg.getTipo() == Tipo::Render){
		if (msg.getMsg() == "yaw"){
			node->roll(Ogre::Radian(45));
			Mensaje * m = new Mensaje(Tipo::Render, "pitch");
			pEntidad->getPEstado()->addMsg(*m);
		}
		else if (msg.getMsg() == "pitch")
			node->pitch(Ogre::Radian(12));

	}
}