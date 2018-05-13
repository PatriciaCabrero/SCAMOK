#include "Animation.h"



Animation::Animation(Entidad * pEnt, std::string mesh, std::string anim): GComponent (pEnt, pEnt->cont,mesh)
{
	if (anim != "") addAnimationState(anim);
}


Animation::~Animation()
{

}

void Animation::Update(float deltaTime, Mensaje const & msj) {

	GComponent::Update(deltaTime, msj);
	std::vector<std::string> borrar;
	for (std::pair<std::string, Ogre::AnimationState*> pS : animStates) {
		pS.second->addTime(deltaTime*0.001f);
		if (pS.second->hasEnded() && !pS.second->getLoop()) {
			borrar.push_back(pS.first);
			pS.second->setEnabled(false);
		}
	}

	for (std::string s : borrar)
		animStates.erase(s);
}
void Animation:: addAnimationState(std::string name, bool loop, bool enabled, bool idle) {
	
	if (idle) {
		if (animStates.find("RunTop") != animStates.end()) {
			animStates.at("RunTop")->setEnabled(false);
			animStates.erase("RunTop");
		}
		if (animStates.find("RunBase") != animStates.end()) {
			animStates.at("RunBase")->setEnabled(false);
			animStates.erase("RunBase");
		}
	}
	if (idle && animStates.size() != 0) 
		return;

	if (animStates.find(name) == animStates.end()) {
		Ogre::AnimationState* newState;
		///ent->
		newState = ent->getAnimationState(name);
		
		newState->setTimePosition(0);
		newState->setEnabled(enabled);
		newState->setLoop(loop);
		
		animStates.insert(std::make_pair(name, newState));
	}
}