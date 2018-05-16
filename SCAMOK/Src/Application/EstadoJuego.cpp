#pragma once
#include "EstadoJuego.h"
#include "FactoryBalas.h"
EstadoJuego::EstadoJuego(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys): Estado(mng, mWindow, sys)
{
	
	noInput = true; contInput = 0;
	cargaGui();
	
}
void EstadoJuego::init() {
#pragma region InitOgre 
	factoria = new FactoryBalas();
	scnMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	scnMgr->setSkyDome(true, "Examples/CloudySky", 5, 8);


	scnMgr->setShadowFarDistance(200);


	entidades.insert(std::make_pair("sinbad", new Entidad(this, "sinbad")));
	entidades.insert(std::make_pair("camera", new Entidad(this, "camera")));


	Mensaje msg(Tipo::Fisica, "0/30/0", SubTipo::Reposicionar);
	msg.setMsgInfo(entidades.at("sinbad"), entidades.at("sinbad"));
	mensajes.push(msg);

	Entidad *aux = new Entidad(this); aux->añadeComponenteGrafico("arena","arena");
	aux->añadeComponenteFisico(0, 0, 0, true);
	entidades.insert(std::make_pair("arena", aux));


	Entidad *aux2 = new Entidad(this);
	aux2->añadeComponenteGrafico("compcube","compcube");
	aux2->añadeComponenteFisico(0, 0, 0, false);
	entidades.insert(std::make_pair("MetalBox", aux2));
	Mensaje ms1(Tipo::Fisica, "0/15/10", SubTipo::Reposicionar);
	ms1.setMsgInfo(entidades.at("MetalBox"), entidades.at("MetalBox"));
	mensajes.push(ms1);

	Entidad* aux1 = new Entidad(this);
	aux1->añadeComponenteGrafico("stone","stone");
	aux1->añadeComponenteFisico(0, 0, 0, false, tipoFisica::Dinamico, 1);
	entidades.insert(std::make_pair("stone", aux1));
	Mensaje ms(Tipo::Fisica, "0/150/0", SubTipo::Reposicionar);
	ms.setMsgInfo(entidades.at("stone"), entidades.at("stone"));
	mensajes.push(ms);


	Entidad* aux3 = new Entidad(this); aux3->añadeComponenteSM("SoundManager", system);
	entidades.insert(std::make_pair("SoundManager", aux3));
	Mensaje playM(Tipo::Audio, "Play/wii.mp3", SubTipo::Musica);
	mensajes.push(playM);


	// Luz por defecto
	scnMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));

	light = scnMgr->createLight("MainLight");
	light->setPosition(20, 50, 50);




#pragma endregion InitOgre
	destroy();
	initCEGUI();
}
void EstadoJuego::cargaGui()
{
	Estado::initCEGUI();
	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("loadScreen.layout");
	m_gui.getRoot()->addChild(guiRoot);

}
bool EstadoJuego::initCEGUI() {
	//Estado::initCEGUI();

	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("Hud.layout");
	m_gui.getRoot()->addChild(guiRoot);
	
	return true;
}
bool EstadoJuego::update(float delta) {
	CEGUI::System::getSingleton().injectTimePulse(1.0f/delta);
	//CEGUI::System::getSingleton().injectTimePulse(0.016f);
	this->getFisicManager()->getDynamicsWorld()->stepSimulation(1.0f /delta);
	for (size_t i = 0; i < borrar.size(); i++)
	{
		entidades.at(borrar[i])->destruyeComponenteGrafico();
		entidades.erase(borrar[i]);
	}
	borrar.clear();

	if (mensajes.size() > 0) {
		Mensaje aux = mensajes.top();
		mensajes.pop();
		for (std::pair<std::string, Entidad*> ent : entidades) {
			ent.second->Update(delta, aux);
		}
	}
	else {
		for (std::pair<std::string, Entidad*> ent : entidades)
			ent.second->Update(delta, Mensaje(Tipo::Fisica, " ", SubTipo::Nulo));
		if (contInput == 30) {
			entidades.at("sinbad")->setAnim("IdleTop", true, true, true);
			entidades.at("sinbad")->setAnim("IdleBase", true, true, true);
			contInput = 0;
		}

	}
	contInput++;
	m_gui.draw();
	swapMsgBufer();

	return true;
}

void EstadoJuego::joystickMoved(float x, float y, int js) {

	std::string sx, sy; sx = std::to_string(x); sy = std::to_string(y);
	std::string s = sx + "/" + "0/" + sy;


	if (js == 0) {
		Mensaje msgI(Tipo::Input, s, SubTipo::Mover);
		mensajes.push(msgI);
		Mensaje msgR(Tipo::Render, s, SubTipo::Orientar); //Look at de la camara
		msgR.setMsgInfo(entidades.at("sinbad"), entidades.at("sinbad"));
		mensajes.push(msgR);
		entidades.at("sinbad")->setAnim("RunTop", true);
		entidades.at("sinbad")->setAnim("RunBase", true);
		contInput = 0;

	}
	else {
		Mensaje msgI(Tipo::Input, s, SubTipo::OrientaCamara);
		msgI.setMsgInfo(entidades.at("camera"), entidades.at("camera"));
		mensajes.push(msgI);
	}

}

void EstadoJuego::keyPressed(std::string s) {
	if (s == "0" || s == "salto") {
		Mensaje msg(Tipo::Fisica, "", SubTipo::Salto);
		msg.setMsgInfo(entidades.at("sinbad"), entidades.at("sinbad"));
		mensajes.push(msg);
		entidades.at("sinbad")->setAnim("JumpLoop");
	}
	else if (s == "1") {
		entidades.at("sinbad")->setAnim("SliceHorizontal");

	}
	else if (s == "2") {
		entidades.at("sinbad")->setAnim("Dance");
	}
	else if (s == "3") {
		entidades.at("sinbad")->setAnim("SliceVertical");
	}
	else if (s == "5") {
		Entidad* aux1 = new Entidad(this);
		string auxBala = factoria->create("Greymon");
		aux1->setNombreNodo(auxBala);
		aux1->añadeComponenteGrafico("Greymon", auxBala);
		aux1->añadeComponenteFisico(0, 0, 0, false, tipoFisica::Dinamico, 1);
		aux1->añadeComponenteLogico("BalaComponent");
		entidades.insert(std::make_pair(auxBala, aux1));
	}

}
void EstadoJuego::keyReleased(std::string s) {


}