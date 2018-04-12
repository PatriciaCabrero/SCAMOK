#include "Estado.h"

Estado::Estado(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow){

	//Aqui montamos el mundo físico
	fisicaManager = new Fisic();

	#pragma region InitOgre 
	mWin = mWindow;
	scnMgr = mng;
	
	scnMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	scnMgr->setShadowFarDistance(200);


	entidades.insert(std::make_pair("Ogro", new Entidad(this, "sinbad")));
	entidades.insert(std::make_pair("MainCamera", new Entidad(this, "camera")));

	//Este mensaje debería ser de transform y configurarlo para que cambie sus referencias locales

	Mensaje * msg =  new Mensaje(Tipo::Render, "0/100/0", SubTipo::Mover);
	msg->setMsgInfo(entidades.at("Ogro"), entidades.at("Ogro"));
	//mensajes.push(msg);

		
	//Aquí va la parte gráfica del suelo
	std::vector<int> auxV = {0,0,0};
	
	Entidad * aux = new Entidad(this); aux->añadeComponenteGrafico("Arena_draft.lwo", auxV );
	//Aquí le meto la base física al suelo
	aux->añadeComponenteFisico(0, 0, 0, true);
	entidades.insert(std::make_pair("Arena", aux));

	/*//Aquí meto un greymon dinámico para colisionar y hacer pruebas
	Entidad* aux1 = new Entidad(this); aux->añadeComponenteGrafico("Greymon");
	//aux->añadeComponenteFisico(1, 1, 1, false, tipoFisica::Dinamico, 1);
	entidades.insert(std::make_pair("Greymon", aux1));
	Mensaje * ms = new Mensaje(Tipo::Logica, "10/10/10", SubTipo::Reposicionar);
	ms->setMsgInfo(entidades.at("Greymon"), entidades.at("Greymon"));
	mensajes.push(ms);
	*/

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

	this->getFisicManager()->getDynamicsWorld()->stepSimulation(1.0f / 60.0f);
	if (mensajes.size() > 0){
		Mensaje* aux = mensajes.top();
		mensajes.pop();
		for (std::pair<std::string, Entidad*> ent : entidades){
			ent.second->Update(delta, *aux);
		}
	}
	else {
		for (std::pair<std::string, Entidad*> ent : entidades) 
			ent.second->Update(delta, *(new Mensaje(Tipo::Fisica, " ")));
	}
	swapMsgBufer();

	return true;
}

void Estado::joystickMoved(float x, float y, int js) {

	std::string sx, sy; sx = std::to_string(x); sy = std::to_string(y);
	std::string s = sx + "/"+ "0/" + sy ;

	Mensaje* msg;
	if (js == 0) {
		msg = new Mensaje(Tipo::Input, s);
		mensajes.push(msg);
	}
	else {
		msg = new Mensaje(Tipo::Input, s, SubTipo::Rotar);
		msg->setMsgInfo(entidades.at("MainCamera"), entidades.at("MainCamera"));
		mensajes.push(msg);
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