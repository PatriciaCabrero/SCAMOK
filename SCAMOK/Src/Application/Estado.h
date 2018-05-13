#pragma once
#include "Entidad.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include <OgreCamera.h>
#include <OgreEntity.h>
#include "OgreSceneNode.h"
#include <OgreConfig.h>
#include "OgreConfigFile.h"

#include <OgreTextureManager.h>
#include <OgreWindowEventUtilities.h>
#include <OgreException.h>
#include "Fisic.h"
#include <fmod.hpp>

#include "Factory.h"


class Estado
{
public:
	Estado(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys);
	~Estado();

	void addViewPort();
	Ogre::SceneManager* getScnManager(){ return scnMgr; };
	Fisic* getFisicManager() { return fisicaManager; };

	bool update(float delta);
	void keyPressed(std::string key);
	void keyReleased(std::string key);
	void joystickMoved(float x, float y, int js = 0);
	Entidad* getEntidad(std::string s);
	void destroy(std::string b) { borrar.push_back(b); }

	//mensajes-------------------------------------
	bool addMsg(Mensaje & msg, bool needNow = false){ 
		if(!needNow)bufer.push(msg); 
		else mensajes.push(msg);
		return true; }
	void swapMsgBufer(){
		mensajes.swap(bufer);
	}

	//Audio-----------------------------------------

	/*void reproduceFx(std::string fx, float x, float y, float z, float wet);
	void reproduceAmbM(std::string amb, float wet, bool fade);
	void paraAmb(int ch, bool fade);*/

	//Ogre------------------------------------------
	Ogre::RenderWindow* getWin() { return mWin; }

private:
	std::vector<std::string> borrar;
	std::map<std::string, Entidad*> entidades;
	Ogre::SceneManager * scnMgr;
	Ogre::Camera* cam;
	Ogre::Viewport* vp;
	Ogre::Light* light;
	Ogre::RenderWindow* mWin;
	
	std::priority_queue < Mensaje > mensajes, bufer;
	Fisic* fisicaManager;
	FMOD::System* system;
	bool noInput; int  contInput;

	Factory* factoria;
};
