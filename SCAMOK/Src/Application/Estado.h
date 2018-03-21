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
#include <fmod.hpp>


class Estado
{
public:
	Estado(Ogre::SceneManager * mng, FMOD::System* sys, Ogre::RenderWindow* mWindow);
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

	//Audio-----------------------------------------

	void reproduceFx(std::string fx, float x, float y, float z, float wet);
	void reproduceAmbM(std::string amb, float wet, bool fade);
	void paraAmb(int ch, bool fade);

	//Ogre------------------------------------------
	Ogre::RenderWindow* getWin() { return mWin; }

private:
	std::map<std::string, Entidad*> entidades;
	Ogre::SceneManager * scnMgr;
	Ogre::Camera* cam;
	Ogre::Viewport* vp;
	Ogre::Light* light;
	Ogre::RenderWindow* mWin;

	std::priority_queue<Mensaje*> mensajes, bufer;
	
	// Fmod settings
	FMOD::ChannelGroup* reverbGroup;
	FMOD::ChannelGroup* mainGroup;
	FMOD::DSP* reverbUnit;
	FMOD::DSP* channelHead;
	int cMusic;
	int cAmb;
	FMOD::System* system;

	std::vector<FMOD::DSPConnection*> reverbConnectionfx;
	std::vector<FMOD::Channel*> cFx;
	std::vector<FMOD::Channel*> cMA;
	std::vector<FMOD::DSPConnection*> reverbConnectionAmbM;
	std::map<std::string, FMOD::Sound*> vfx;
	std::map<std::string, FMOD::Sound*> vmusic;

	void cargaAudio(std::string irPath);
	void cargarAssetsAudio();

};
