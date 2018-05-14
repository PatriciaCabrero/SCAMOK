#pragma once
#include "EstadoMenu.h"   
#include "Juego.h"

EstadoMenu::EstadoMenu(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys, Juego* game, std::string type ): Estado(mng, mWindow, sys, game) {
	type_ = type;
	initCEGUI();
}

EstadoMenu::~EstadoMenu() { 
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

	//aux->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&Juego::exitGame, this));
	//TaharezLook/Button/disableButton
	//aux->activate();
	
	/*CEGUI::PushButton* testButton = static_cast<CEGUI::PushButton*>(m_gui.createWidget("TaharezLook/Button", glm::vec4(0.5f, 0.5f, 0.1f, 0.05f), glm::vec4(0.0f), "TestButton"));
	testButton->setText("Hello GUI!");*/
	

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
	EstadoJuego* estado = new EstadoJuego(scnMgr, mWin, system);
	game_->cambiaEstado(estado, true);
}

void EstadoMenu::salir()
{
	game_->exitGame();
	
}

void EstadoMenu::creditos()
{
	EstadoMenu* estado = new EstadoMenu(scnMgr, mWin, system, game_, "creditos");
	game_->cambiaEstado(estado);
}

void EstadoMenu::initMenuPause()
{
	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("Custom.layout");
	m_gui.getRoot()->addChild(guiRoot);

	CEGUI::PushButton* opciones = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Opciones"));
	opciones->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::opciones, this));

	CEGUI::PushButton* jugar = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Reanudar"));
	jugar->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::estadoAnt, this));

	CEGUI::PushButton* salir = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Salir"));
	salir->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::salir, this));
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
	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("menuPrincipal.layout");
	m_gui.getRoot()->addChild(guiRoot);

	CEGUI::PushButton* jugar = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Jugar"));
	jugar->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::level1, this));

	CEGUI::PushButton* creditos = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Creditos"));
	creditos->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::creditos, this));

}
