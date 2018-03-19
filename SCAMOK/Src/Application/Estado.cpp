#include "Estado.h"

Estado::Estado(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow){

	#pragma region InitOgre 
	mWin = mWindow;
	scnMgr = mng;
	

	entidades.insert(std::make_pair("Ogro", new Entidad(this, "sinbad")));
	entidades.insert(std::make_pair("MainCamera", new Entidad(this, "camera")));
	Entidad * aux = new Entidad(this); aux->añadeComponenteGrafico("Greymon");
	entidades.insert(std::make_pair("Arbol", aux));


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

void Estado::joystickMoved(float x, float y, int js) {

	std::string sx, sy; sx = std::to_string(x); sy = std::to_string(y);
	std::string s = sx + "/"+ sy;

	Mensaje* msg;
		msg = new Mensaje(Tipo::Input, s);
	if (js == 0) {
		mensajes.push(msg);
	}
	else {
		msg->setMsgInfo(entidades.at("MainCamera"), entidades.at("MainCamera"));
		mensajes.push(msg);
	}

}
void Estado::keyPressed(std::string s) {
	if (s == "der" || s == "izq" || s == "arr" || s == "aba") {
		Mensaje* msg = new Mensaje(Tipo::Input, s);
		mensajes.push(msg);
	}
	
}
void Estado::keyReleased(std::string s) {
	
}