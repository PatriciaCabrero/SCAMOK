
#include "GComponent.h"
using namespace Ogre;
GComponent::GComponent(Entidad* pEnt, std::string name) : Componente (pEnt){
	
	std::string mesh = name + ".mesh";
	ent = pEnt->getPEstado()->getScnManager()->createEntity(mesh);
	node = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode(name);
	node->attachObject(ent);
	
}
void GComponent::Update(float deltaTime,  Mensaje const & msj) { 
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);
	if (msg.getTipo() == Tipo::Render ){
		
		int pos = msg.getMsg().find("/");
		std::string sz = msg.getMsg().substr(0, pos);
		std::string sx = msg.getMsg().substr(pos + 1);

		float x = -1* std::stof(sx);
		float z = -1 *std::stof(sz);

		node->translate(x,0,z);

	}
}
void GComponent::destroy() {
	node->removeAndDestroyAllChildren();
	pEntidad->getPEstado()->getScnManager()->getRootSceneNode()->detachObject(ent);
	delete node;
	delete ent;
}
GComponent::~GComponent() {
	
}