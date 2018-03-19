
#include "GComponent.h"
using namespace Ogre;
GComponent::GComponent(Entidad* pEnt, std::string s) : Componente (pEnt){
	
	ent = pEnt->getPEstado()->getScnManager()->createEntity(s);
	node = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
	node->rotate(Quaternion(Degree(180), Vector3::UNIT_Y));
}
void GComponent::Update(float deltaTime,  Mensaje const & msj) { 
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);
	if (msg.getTipo() == Tipo::Render ){
		
		int pos = msg.getMsg().find("/");
		std::string sz = msg.getMsg().substr(0, pos);
		std::string sx = msg.getMsg().substr(pos + 1);

		float x = std::stof(sx);
		float z = std::stof(sz);

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