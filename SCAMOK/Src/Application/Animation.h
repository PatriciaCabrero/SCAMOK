#pragma once
#include "Componente.h"
#include "Estado.h"

struct Anim {
	Ogre::Animation *anim;
	Ogre::AnimationState *animState;
};
class Animation :
	public Componente
{
public:
	Animation(Entidad* pEnt);
	virtual ~Animation();
	virtual void Update(float deltaTime, Mensaje const & msj);


	std::map < std::string, Anim> animaciones;
};


