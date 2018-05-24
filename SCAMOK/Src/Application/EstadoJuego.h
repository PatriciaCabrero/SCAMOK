#pragma once
#include "Estado.h"
#include "Factory.h"
#include <iostream>
class EstadoJuego: public Estado
{
public:
	EstadoJuego(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys, Juego* pJuego = nullptr);
	//virtual ~EstadoJuego() ;

	virtual bool update(float delta);
	virtual void keyPressed(std::string key);
	virtual void keyReleased(std::string key);
	virtual void joystickMoved(float x, float y, int js = 0);
	virtual bool initCEGUI();
	virtual void init();
	void cargaGui();
	void restaPower();
	void resuelveCol();
	virtual void cambiaEstado(std::string const & estado);
	void creaEnemigos();

private:
	
	CEGUI::DefaultWindow* lluviaW, *simpleW;
	int habilidad; //0-> simple, 1-> lluvia.
	void changeHabilidad();
	
	int maxPower;
	int contDescartes;


	int RandomNumber(float max, float min) {
		float result = min + rand() / (RAND_MAX / (max - min));
		std::cout << (int)result <<"\n";
		return int(result);
	}

};

