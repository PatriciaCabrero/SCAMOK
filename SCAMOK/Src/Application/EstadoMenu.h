#pragma once 
#include "Estado.h"
class EstadoMenu: public Estado 
{ 
public: 
	EstadoMenu(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys, Juego* game = nullptr);
	virtual ~EstadoMenu(); 

	virtual bool initCEGUI();
	
	void opciones();
	void jugar();
	void salir();
}; 
