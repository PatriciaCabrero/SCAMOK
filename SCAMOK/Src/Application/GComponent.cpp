
#include "GComponent.h"

GComponent::GComponent(Entidad* pEnt) : Componente (pEnt){
	
	Ogre::Entity * ent = pEnt->getPEstado()->getScnManager()->createEntity("ogrehead.mesh");
	Ogre::SceneNode * node = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
}
void GComponent::Update(float deltaTime, Mensaje& msj) { 
	Componente::Update(deltaTime, msj);

}