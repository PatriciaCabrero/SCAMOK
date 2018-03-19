#include "Animation.h"



Animation::Animation(Entidad * pEnt, std::string mesh): GComponent (pEnt, mesh)
{
	baseAnim = ent->getAnimationState("RunBase");
	topAnim = ent->getAnimationState("RunTop");
	
	baseAnim->setEnabled(true);
	topAnim->setEnabled(true);
	baseAnim->setLoop(true);
	topAnim->setLoop(true);
	
	
	
}


Animation::~Animation()
{
	
}

void Animation::Update(float deltaTime, Mensaje const & msj) {

	topAnim->addTime(0.017f);
	baseAnim->addTime(0.017f);
	GComponent::Update(deltaTime, msj);
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);
	if (msg.getTipo() == Tipo::AnimationM ) {
		
		
	}
}
/*void Animation::frameRendered(const Ogre::FrameEvent &  evt)
{
	topAnim->addTime(10.2f);//evt.timeSinceLastFrame);
	baseAnim->addTime(10.0f);//evt.timeSinceLastFrame);
}*/
