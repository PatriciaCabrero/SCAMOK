
#include "GComponent.h"

GComponent::GComponent(Entidad* pEnt, std::string s) : Componente (pEnt){
	
	ent = pEnt->getPEstado()->getScnManager()->createEntity(s);
	node = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
}
void GComponent::Update(float deltaTime,  Mensaje const & msj) { 
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);
	if (msg.getTipo() == Tipo::Render ){
		
		int pos = msg.getMsg().find("/");
		std::string sx = msg.getMsg().substr(0, pos);
		std::string sy = msg.getMsg().substr(pos + 1);

		float x = std::stof(sx);
		float z = std::stof(sy);

		node->translate(x,0,z);

	}
}