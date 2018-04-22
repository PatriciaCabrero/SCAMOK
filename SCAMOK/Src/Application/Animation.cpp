#include "Animation.h"



Animation::Animation(Entidad * pEnt, std::string mesh, std::string anim): GComponent (pEnt, mesh)
{
	if (anim != "") addAnimationState(anim);
}


Animation::~Animation()
{
	/*delete baseAnim;
	delete topAnim;*/
}

void Animation::Update(float deltaTime, Mensaje const & msj) {

	GComponent::Update(deltaTime, msj);
	for (Ogre::AnimationState* pS : animStates)
		pS->addTime(0.017f);	
}
void Animation:: addAnimationState(std::string name, bool enabled, bool loop) {
	
	Ogre::AnimationState* newState;
	newState = ent->getAnimationState(name);
	newState->setEnabled(enabled);
	newState->setLoop(loop);

	animStates.push_back(newState);
}