#include "Estado.h"

Estado::Estado(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow){
	scnMgr = mng;
	//set Camera
	cam = scnMgr->createCamera("MainCam");
	cam->setPosition(0, 0, 80);
	cam->lookAt(0, 0, -300);
	cam->setNearClipDistance(5);

	//set viewport
	vp = mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));

	cam->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) /
		Ogre::Real(vp->getActualHeight()));

	// Mesh de cabeza ogro
	entidades.insert(std::make_pair("Ogro", new Entidad(this)));


	// Luz por defecto
	scnMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));

	light = scnMgr->createLight("MainLight");
	light->setPosition(20, 80, 50);
}

Estado::~Estado(){
	scnMgr->clearScene();
	scnMgr->~SceneManager();
}