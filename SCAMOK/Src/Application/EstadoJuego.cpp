#pragma once
#include "EstadoJuego.h"
#include "FactoryBalas.h"
#include <iostream>
#include "OgreParticleSystem.h"
#include "Juego.h"
#include "EstadoMenu.h"
EstadoJuego::EstadoJuego(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys, Juego* pJuego): Estado(mng, mWindow, sys, pJuego)
{
	
	noInput = true; contInput = contDescartes=0;
	cargaGui();
	
}
void EstadoJuego::init() {
#pragma region InitOgre 
	factoria = new FactoryBalas();
	scnMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	scnMgr->setSkyDome(true, "Examples/CloudySky", 5, 8);


	scnMgr->setShadowFarDistance(200);


	entidades.insert(std::make_pair("Alaia", new Entidad(this, "Alaia")));
	entidades.insert(std::make_pair("camera", new Entidad(this, "camera")));


	Mensaje msg(Tipo::Fisica, "80/30/0", SubTipo::Reposicionar,8);
	msg.setMsgInfo(entidades.at("Alaia"), entidades.at("Alaia"));
	mensajes.push(msg);

	Entidad *aux = new Entidad(this); aux->añadeComponenteGrafico("arena","arena");
	aux->añadeComponenteFisico(0, 0, 0, true);
	entidades.insert(std::make_pair("arena", aux));


	Entidad *aux2 = new Entidad(this);
	aux2->añadeComponenteGrafico("compcube","compcube");
	aux2->añadeComponenteFisico(0, 0, 0, false);
	entidades.insert(std::make_pair("MetalBox", aux2));
	Mensaje ms1(Tipo::Fisica, "0/15/10", SubTipo::Reposicionar,8);
	ms1.setMsgInfo(entidades.at("MetalBox"), entidades.at("MetalBox"));
	mensajes.push(ms1);

	Entidad* aux1 = new Entidad(this);
	aux1->añadeComponenteGrafico("stone","stone");
	aux1->añadeComponenteFisico(0, 0, 0, false, tipoFisica::Kinematico, 1);
	aux1->añadeComponenteLogico("IABola");
	entidades.insert(std::make_pair("stone", aux1));
	Mensaje ms(Tipo::Fisica, "20/150/0", SubTipo::Reposicionar,8);
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
void EstadoJuego::restaPower()
{
	Mensaje ms(Tipo::Gui, "-0.25", SubTipo::CambiaMana);
	ms.setMsgInfo(entidades.at("Alaia"), entidades.at("Alaia"));
	mensajes.push(ms);
}
bool EstadoJuego::initCEGUI() {
	//Estado::initCEGUI();

	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("Hud.layout");
	m_gui.getRoot()->addChild(guiRoot);

	//life = static_cast<CEGUI::ProgressBar*>(guiRoot->getChild("Life"));
	//power = static_cast<CEGUI::ProgressBar*>(guiRoot->getChild("Power"));
	


	Mensaje ms(Tipo::Gui, " ", SubTipo::InitGui);
	ms.setMsgInfo(entidades.at("Alaia"), entidades.at("Alaia"));
	mensajes.push(ms);
	
	return true;
}
bool EstadoJuego::update(float delta) {
	CEGUI::System::getSingleton().injectTimePulse(1.0f / delta);
	//CEGUI::System::getSingleton().injectTimePulse(0.016f);
	this->getFisicManager()->getDynamicsWorld()->stepSimulation(1.0f / delta);
	
	for (size_t i = 0; i < borrar.size(); i++)
	{
		entidades.at(borrar[i])->destruyeComponenteGrafico();
		entidades.erase(borrar[i]);
	}
	borrar.clear();

	while (mensajes.size() > 0) {
		Mensaje aux = mensajes.top();
		mensajes.pop();
		
		for (std::pair<std::string, Entidad*> ent : entidades) {
			ent.second->Update(delta, aux);
		}
	}
	if (contInput >= 30) {
		entidades.at("Alaia")->setAnim("Idle", true, true, true);
		//entidades.at("Alaia")->setAnim("IdleBase", true, true, true);
		contInput = 0;
	}

	for (std::pair<std::string, Entidad*> ent : entidades) {
		ent.second->Update(delta, Mensaje(Tipo::AnimationM, " ", SubTipo::Nulo));
		ent.second->Update(delta, Mensaje(Tipo::IA, " ", SubTipo::Nulo));
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
		msgR.setMsgInfo(entidades.at("Alaia"), entidades.at("Alaia"));
		mensajes.push(msgR);
		entidades.at("Alaia")->setAnim("Run", true);
		//entidades.at("Alaia")->setAnim("RunBase", true);
		contInput = 0;

	}
	else if (js == 1) {
		Mensaje msgI(Tipo::Input, s, SubTipo::OrientaCamara);
		msgI.setMsgInfo(entidades.at("camera"), entidades.at("camera"));
		mensajes.push(msgI);
	}
	else {
		Mensaje msgF(Tipo::Fisica, s, SubTipo::Nulo);
		mensajes.push(msgF);
	}

}

void EstadoJuego::keyPressed(std::string s) {
	if (s == "0" || s == "salto") {
		Mensaje msg(Tipo::Fisica, "", SubTipo::Salto);
		msg.setMsgInfo(entidades.at("Alaia"), entidades.at("Alaia"));
		mensajes.push(msg);
		entidades.at("Alaia")->setAnim("Jump");
	}
	else if (s == "1") {
		entidades.at("Alaia")->setAnim("AirUp");

	}
	else if (s == "2") {

	entidades.at("Alaia")->setAnim("AirDown");
		Mensaje msg(Tipo::Mana, "carga", SubTipo::GetPower);
		msg.setMsgInfo(entidades.at("Alaia"), entidades.at("Alaia"));
		mensajes.push(msg);
	}
	else if (s == "3") {
		
			for (std::pair<std::string, Entidad*> ent : entidades)
				ent.second->Update(0.12, Mensaje(Tipo::IA, " ", SubTipo::Musica));
	}
	else if (s == "5") {
		Mensaje msg(Tipo::Mana, "", SubTipo::DoPower);
		msg.setMsgInfo(entidades.at("Alaia"), entidades.at("Alaia"));
		mensajes.push(msg);

	}
	else if (s == "7") {
			EstadoMenu * pEstado;
			pEstado = new EstadoMenu(scnMgr, mWin, system, game_, "pause");
			game_->cambiaEstado(pEstado);
	}

}
void EstadoJuego::keyReleased(std::string s) {
	if (s == "2") {
		
		Mensaje msg(Tipo::Mana, " ", SubTipo::GetPower);
		msg.setMsgInfo(entidades.at("Alaia"), entidades.at("Alaia"));
		mensajes.push(msg);
	}

}