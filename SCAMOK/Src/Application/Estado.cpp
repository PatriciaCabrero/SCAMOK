#include "Estado.h"

Estado::Estado(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow){

	#pragma region InitOgre 
	mWin = mWindow;
	scnMgr = mng;
	
	scnMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	scnMgr->setShadowFarDistance(200);


	entidades.insert(std::make_pair("Ogro", new Entidad(this, "sinbad")));
	entidades.insert(std::make_pair("MainCamera", new Entidad(this, "camera")));

	//Este mensaje debería ser de transform y configurarlo para que cambie sus referencias locales

	Mensaje msg (Tipo::Render, "0/5/0", SubTipo::Mover);
	msg.setMsgInfo(entidades.at("Ogro"), entidades.at("Ogro"));
	mensajes.push(msg);

		
	 
	Entidad *aux = new Entidad(this); aux->añadeComponenteGrafico("Arena_draft.lwo");
	entidades.insert(std::make_pair("Arena", aux));
	//delete aux;



	// Luz por defecto
	scnMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));

	light = scnMgr->createLight("MainLight");
	light->setPosition(20, 80, 50);

	#pragma endregion InitOgre

}

Estado::~Estado(){
	/*scnMgr->clearScene();
	scnMgr->~SceneManager();
	scnMgr->destroyAllEntities();
	scnMgr->destroyAllLights();
	scnMgr->destroyAllCameras();*/
	//delete scnMgr;
	//delete cam;
	//delete mWin;
	//delete vp;
	for (std::pair<std::string,Entidad*> n : entidades) {
		delete n.second;
	}
}

bool Estado::update(float delta){

	
	if (mensajes.size() > 0){
		Mensaje aux = mensajes.top();
		mensajes.pop();
		for (std::pair<std::string, Entidad*> ent : entidades){
			ent.second->Update(delta, aux);
		}
	}
	swapMsgBufer();

	return true;
}

void Estado::joystickMoved(float x, float y, int js) {

	std::string sx, sy; sx = std::to_string(x); sy = std::to_string(y);
	std::string s = sx + "/"+ "0/" + sy ;

	
	if (js == 0) {
		Mensaje msgI (Tipo::Input, s);
		mensajes.push(msgI);
		Mensaje msgR(Tipo::Render, s, SubTipo::Mover);
		msgR.setMsgInfo(entidades.at("Ogro"), entidades.at("Ogro"));
		mensajes.push(msgR);
	}
	else {
		Mensaje msgI(Tipo::Input, s, SubTipo::Rotar);
		msgI.setMsgInfo(entidades.at("MainCamera"), entidades.at("MainCamera"));
		mensajes.push(msgI);
		Mensaje msgR(Tipo::Render, s, SubTipo::Rotar);
		msgR.setMsgInfo(entidades.at("Ogro"), entidades.at("Ogro"));
		mensajes.push(msgR);

	}

}
void Estado::keyPressed(std::string s) {
	/*if (s == "der" || s == "izq" || s == "arr" || s == "aba") {
		Mensaje* msg = new Mensaje(Tipo::Input, s, SubTipo::Mover);
		msg->setMsgInfo(entidades.at("MainCamera"), entidades.at("MainCamera"));
		mensajes.push(msg);
	}*/
	
}
void Estado::keyReleased(std::string s) {
	
}
Entidad* Estado::getEntidad(std::string s) {
	auto flag = entidades.find(s);
	if (flag != entidades.end()) return entidades.at(s);
	
	return nullptr;
}