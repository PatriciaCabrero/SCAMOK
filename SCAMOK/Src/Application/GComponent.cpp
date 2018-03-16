
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
		if (msg.getMsg() == "der")
		node->translate(1, 0, 0);
		else if (msg.getMsg() == "izq")
			node->translate(-1, 0, 0);
		else if (msg.getMsg() == "arr")
			node->translate(0, 0, -1);
		else if (msg.getMsg() == "aba")
			node->translate(0, 0, 1);

	}
}