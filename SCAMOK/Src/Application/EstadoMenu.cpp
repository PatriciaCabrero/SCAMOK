#pragma once
#include "EstadoMenu.h"   
#include "Juego.h"

EstadoMenu::EstadoMenu(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys, Juego* game ): Estado(mng, mWindow, sys, game) {
	initCEGUI();
}

EstadoMenu::~EstadoMenu() { 
} 
bool EstadoMenu::initCEGUI() {
	Estado::initCEGUI();

	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("Custom.layout");
	m_gui.getRoot()->addChild(guiRoot);
	
	CEGUI::PushButton* opciones = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Opciones"));
	opciones->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::opciones, this));
	
	CEGUI::PushButton* jugar = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Reanudar"));
	jugar->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::jugar, this));
	
	CEGUI::PushButton* salir = static_cast<CEGUI::PushButton*>(guiRoot->getChild("Salir"));
	salir->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&EstadoMenu::salir, this));

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

void EstadoMenu::jugar()
{
	game_->quitaEstado();
}

void EstadoMenu::salir()
{
	game_->exitGame();
	
}
