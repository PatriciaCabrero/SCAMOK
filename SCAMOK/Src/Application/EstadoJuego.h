#pragma once
#include "Estado.h"
#include "Factory.h"
class EstadoJuego: public Estado
{
public:
	EstadoJuego(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys, Juego* pJuego = nullptr);
	//virtual ~EstadoJuego() {};

	virtual bool update(float delta);
	virtual void keyPressed(std::string key);
	virtual void keyReleased(std::string key);
	virtual void joystickMoved(float x, float y, int js = 0);
	virtual bool initCEGUI();
	virtual void init();
	void cargaGui();
	void restaPower();
	void resuelveCol();

private:
	
	int maxPower;
	int contDescartes;

	float RandomNumber(float Min, float Max)
	{
		float result = (((float)rand() / float(RAND_MAX)) * (Max - Min)) + Min;
		return result;
	}

};

