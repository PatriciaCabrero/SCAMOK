#pragma once
#include "GComponent.h"
#include "Estado.h"
#include "OgreRenderTargetListener.h"

struct Anim {
	Ogre::Animation *anim;
	Ogre::AnimationState *animState;
};
class Animation :
	public GComponent//, public Ogre::RenderTargetListener
{
public:
	Animation(Entidad* pEnt, std:: string mesh);
	virtual ~Animation();
	virtual void Update(float deltaTime, Mensaje const & msj);
	std::map < std::string, Anim> animaciones;
	Ogre::AnimationState* baseAnim;
	Ogre::AnimationState* topAnim;

private: 
	//virtual void frameRendered(const Ogre::FrameEvent &  evt);
};


