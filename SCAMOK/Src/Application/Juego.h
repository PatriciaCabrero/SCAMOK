#pragma once
#include <stdio.h>

#include <string>
#include <stack>
#include <iostream>
#include "Estado.h"
#include "InputManager.h"


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

	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;

	//Ois-------------------
	InputManager * mInputMgr;
	
	void handleInput();
	virtual bool keyPressed(const OIS::KeyEvent& ke);
	virtual bool keyReleased(const OIS::KeyEvent& ke);

	virtual bool mouseMoved(const OIS::MouseEvent& me) { return true; };
	virtual bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id) { return true; };
	virtual bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id) { return true; };
	
	
	virtual bool axisMoved(const OIS::JoyStickEvent & arg, int axis);// { return true; }
	virtual bool buttonPressed(const OIS::JoyStickEvent & arg, int button);// { return true; }
	virtual bool buttonReleased(const OIS::JoyStickEvent & arg, int buton) { return true; }
	virtual bool sliderMoved(const OIS::JoyStickEvent & arg, int index) { return true; }
	virtual bool vector3Moved(const OIS::JoyStickEvent & arg, int index) { return true; }
	virtual bool povMoved(const OIS::JoyStickEvent & arg, int index);// { return true; }
	

	int contJoystick;
	bool exit = false;
};

