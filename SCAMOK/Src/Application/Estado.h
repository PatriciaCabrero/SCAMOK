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


class Estado
{
public:
	Estado(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow);
	~Estado();

	void addViewPort();
	Ogre::SceneManager* getScnManager(){ return scnMgr; };

	bool update(float delta);
	void keyPressed(std::string key);
	void keyReleased(std::string key);
	void joystickMoved(float x, float y, int js = 0);

	//mensajes-------------------------------------
	bool addMsg(Mensaje & msg){ 
		bufer.push(&msg); 
		return true; }
	void swapMsgBufer(){
		mensajes.swap(bufer);
	}
	Ogre::RenderWindow* getWin() { return mWin; }
private:
	std::map<std::string, Entidad*> entidades;
	Ogre::SceneManager * scnMgr;
	Ogre::Camera* cam;
	Ogre::Viewport* vp;
	Ogre::Light* light;
	Ogre::RenderWindow* mWin;

	std::priority_queue<Mensaje*> mensajes, bufer;
	

};
