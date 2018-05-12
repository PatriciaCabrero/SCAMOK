#pragma once 
#include "Estado.h"
class EstadoMenu: public Estado 
{ 
public: 
	EstadoMenu(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys);
	virtual ~EstadoMenu(); 

	virtual bool initCEGUI();
	
}; 
