#pragma once
#include "EstadoMenu.h"   
#include "Juego.h"
#include "FactoryBalas.h"

EstadoMenu::EstadoMenu(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys, Juego* game, std::string type) : Estado(mng, mWindow, sys, game) {
	type_ = type;
	initCEGUI();
	factoria = new FactoryBalas();
	
}

EstadoMenu::~EstadoMenu()
{
	//m_gui.destroy();;
	for each  ( CEGUI::PushButton* var in botones)
	{
		var->removeAllEvents();
	}
	/*m_gui.getRoot()->disable();
	//m_gui.getRoot()->destroyChild(guiRoot);*/
}



bool EstadoMenu::initCEGUI() {
	Estado::initCEGUI();

	if (type_ == "pause") {
		initMenuPause();
	}
	else if (type_ == "ppal") {
		initPpal();
	}
	else if (type_ == "creditos") {
		initCreditos();
	}
	else if (type_ == "GameOver") {
		initGameOver();
	}



	m_gui.setMouseCursor("TaharezLook/MouseArrow");
	m_gui.showMouseCursor();
	return true;
}

void EstadoMenu::opciones()
{

}

void EstadoMenu::estadoAnt()
{
	game_->quitaEstado();
}

void EstadoMenu::level1()
{

	//destroy();
	//game_->quitaEstado();
	Mensaje playM(Tipo::Audio, "Stop/wii.mp3", SubTipo::Musica);
	mensajes.push(playM);
	update(0.17);

	EstadoJuego* estado = new EstadoJuego(scnMgr, mWin, system,game_);
	game_->cambiaEstado(estado, true);
}

void EstadoMenu::salir()
{
	game_->exitGame();

}

void EstadoMenu::restart()
{
	game_->restart();
	salir();
}

void EstadoMenu::creditos()
{
	EstadoMenu* estado = new EstadoMenu(scnMgr, mWin, system, game_, "creditos");
	game_->cambiaEstado(estado);
}

bool EstadoMenu::update(float delta)
{
	if (mensajes.size() > 0) {
		Mensaje aux = mensajes.top();
		mensajes.pop();
		for (std::pair<std::string, Entidad*> ent : entidades) {
			ent.second->Update(delta, aux);
		}
	}
	return true;
}

void EstadoMenu::initMenuPause()
{
	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("Custom.layout");
	m_gui.getRoot()->addChild(guiRoot);

	CEGUI::PushButton* opciones_ = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Opciones"));
	opciones_->subscribeEvent(CEGUI::PushButton::EventMouseButtonUp, CEGUI::Event::Subscriber(&EstadoMenu::opciones, this));
	botones.push_back(opciones_);

	CEGUI::PushButton* jugar_ = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Reanudar"));
	jugar_->subscribeEvent(CEGUI::PushButton::EventMouseButtonUp, CEGUI::Event::Subscriber(&EstadoMenu::estadoAnt, this));
	botones.push_back(jugar_);

	CEGUI::PushButton* salir_ = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Salir"));
	salir_->subscribeEvent(CEGUI::PushButton::EventMouseButtonUp, CEGUI::Event::Subscriber(&EstadoMenu::salir, this));
	botones.push_back(salir_);
}

void EstadoMenu::initCreditos()
{
	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("creditos.layout");
	m_gui.getRoot()->addChild(guiRoot);

	CEGUI::PushButton* volver = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Volver"));
	volver->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::estadoAnt, this));

}

void EstadoMenu::initOpciones()
{
}

void EstadoMenu::initPpal()
{
	Entidad* aux3 = new Entidad(this); aux3->añadeComponenteSM("SoundManager", system);
	entidades.insert(std::make_pair("SoundManager", aux3));
	Mensaje playM(Tipo::Audio, "Play/ppal.mp3", SubTipo::Musica);
	mensajes.push(playM);

	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("menuPrincipal.layout");
	m_gui.getRoot()->addChild(guiRoot);

	CEGUI::PushButton* jugar = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Jugar"));
	jugar->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::level1, this));

	CEGUI::PushButton* creditos = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Creditos"));
	creditos->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::creditos, this));

}
void EstadoMenu::initGameOver()
{
	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("GameOver.layout");
	m_gui.getRoot()->addChild(guiRoot);

	CEGUI::PushButton* restart = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Reiniciar"));
	restart->subscribeEvent(CEGUI::PushButton::EventMouseButtonUp, CEGUI::Event::Subscriber(&EstadoMenu::restart, this));
	botones.push_back(restart);

	CEGUI::PushButton* salir_ = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Salir"));
	salir_->subscribeEvent(CEGUI::PushButton::EventMouseButtonUp, CEGUI::Event::Subscriber(&EstadoMenu::salir, this));
	botones.push_back(salir_);
}
void EstadoMenu::joystickMoved(float x, float y, int js) {
	if (abs(x) >= 0.2 || abs(y) >= 0.2) {
		m_gui.moveJoystick(x*(-10), y*(-10));
	}
}

void EstadoMenu::keyPressed(std::string key)
{
	if (key != "")
		m_gui.downButton(key);
}

void EstadoMenu::keyReleased(std::string key)
{
	if (key != "" && !callback)
		m_gui.upButton(key);
}

bool EstadoMenu::mousePressed(const OIS::MouseEvent & me, OIS::MouseButtonID id)
{
	if (!callback) {
		m_gui.downMouse(id);
		//callback = true;
	}
	return false;
}

bool EstadoMenu::mouseReleased(const OIS::MouseEvent & me, OIS::MouseButtonID id)
{
	m_gui.upMouse(id);

	return false;
}