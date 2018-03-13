#pragma once
#include <stdio.h>

#include <string>
#include <stack>
#include <iostream>
#include "Estado.h"

class Juego
{
public:
	Juego();
	~Juego();
	
	bool run();
	std::stack<Estado*>pEstados;

private:

	bool init();

	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;

};

