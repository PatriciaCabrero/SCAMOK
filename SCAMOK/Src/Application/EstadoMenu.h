#pragma once 
#include "Estado.h"
#include "EstadoJuego.h"
class EstadoMenu: public Estado 
{ 
public: 
	EstadoMenu(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys, Juego* game = nullptr, std::string type = "ppal");
	virtual ~EstadoMenu(); 

	virtual bool initCEGUI();
	
	void opciones();
	void estadoAnt();
	void level1();
	void salir();
	void creditos();
	virtual bool update(float delta);
	virtual void joystickMoved(float x, float y, int js = 0);
	virtual void keyPressed(std::string key);
	virtual void keyReleased(std::string key);

private:
		std::string type_;
		void initMenuPause();
		void initCreditos();
		void initOpciones();
		void initPpal();
}; 
