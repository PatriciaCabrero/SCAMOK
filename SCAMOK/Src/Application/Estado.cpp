#include "Estado.h"

Estado::Estado(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow){

	#pragma region InitOgre 
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
	entidades.insert(std::make_pair("Ogro", new Entidad(this, "sinbad")));
	Entidad * aux = new Entidad(this); aux->añadeComponenteGrafico("sinbad.mesh");
	entidades.insert(std::make_pair("OgroSinMovimiento", aux));


	// Luz por defecto
	scnMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));

	light = scnMgr->createLight("MainLight");
	light->setPosition(20, 80, 50);

	#pragma endregion InitOgre

}

Estado::~Estado(){
	scnMgr->clearScene();
	scnMgr->~SceneManager();
}

bool Estado::update(float delta){

	
	if (mensajes.size() > 0){
		Mensaje* aux = mensajes.top();
		mensajes.pop();
		for (std::pair<std::string, Entidad*> ent : entidades){
			ent.second->Update(delta, *aux);
		}
	}
	swapMsgBufer();

	return true;
}

void Estado::keyPressed(std::string s) {
	if (s == "der" || s == "izq" || s == "arr" || s == "aba") {
		Mensaje* msg = new Mensaje(Tipo::Input, s);
		mensajes.push(msg);
	}
	
}
void Estado::keyReleased(std::string s) {
	
}