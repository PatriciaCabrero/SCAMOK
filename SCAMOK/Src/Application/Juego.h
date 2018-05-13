#pragma once
#include <stdio.h>

#include <string>
#include <stack>
#include <iostream>
#include "Estado.h"
#include "InputManager.h"
#include "GUI.h"


class Juego: public OIS::KeyListener, OIS::MouseListener, OIS::JoyStickListener
{
public:
	Juego();
	~Juego();
	
	bool run();
	std::stack<Estado*>pEstados;

private:

	bool init();
	bool initOgre();
	bool initOis();
	bool initFmod();
	bool initCEGUI();

	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;

	//Fmod------------------

	FMOD::System     *system;
	FMOD_RESULT       result;

	//Ois-------------------
	InputManager * mInputMgr;
	
	

	//CEGUI----------------
	GUI m_gui;
	void handleInput();
	virtual bool keyPressed(const OIS::KeyEvent& ke);
	virtual bool keyReleased(const OIS::KeyEvent& ke);

	virtual bool mouseMoved(const OIS::MouseEvent& me);
	virtual bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	
	
	virtual bool axisMoved(const OIS::JoyStickEvent & arg, int axis);
	virtual bool buttonPressed(const OIS::JoyStickEvent & arg, int button);
	virtual bool buttonReleased(const OIS::JoyStickEvent & arg, int buton) { return true; }
	virtual bool sliderMoved(const OIS::JoyStickEvent & arg, int index) { return true; }
	virtual bool vector3Moved(const OIS::JoyStickEvent & arg, int index) { return true; }
	virtual bool povMoved(const OIS::JoyStickEvent & arg, int index);
	

	int contJoystick;
	bool exit = false;
};

