#pragma once
#include "Estado.h"

class EstadoJuego: public Estado
{
public:
	EstadoJuego(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys);
	virtual ~EstadoJuego() {};

	virtual bool update(float delta);
	virtual void keyPressed(std::string key);
	virtual void keyReleased(std::string key);
	virtual void joystickMoved(float x, float y, int js = 0);
	virtual bool initCEGUI();
	virtual void init();
	void cargaGui();
private:

};

