#pragma once
#include "EstadoMenu.h"  
 
EstadoMenu::EstadoMenu(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys): Estado(mng, mWindow, sys) {
	initCEGUI();
}

EstadoMenu::~EstadoMenu() { 
} 
bool EstadoMenu::initCEGUI() {
	Estado::initCEGUI();

	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("VanillaWindows.layout");
	m_gui.getRoot()->addChild(guiRoot);
	
	//CEGUI::PushButton* aux = static_cast<CEGUI::PushButton*>(guiRoot->getChild("StaticImage")->getChild("button"));
	//aux->setText("Suavisado");
	//aux->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&Juego::exitGame, this));
	//TaharezLook/Button/disableButton
	//aux->activate();
	
	/*CEGUI::PushButton* testButton = static_cast<CEGUI::PushButton*>(m_gui.createWidget("TaharezLook/Button", glm::vec4(0.5f, 0.5f, 0.1f, 0.05f), glm::vec4(0.0f), "TestButton"));
	testButton->setText("Hello GUI!");*/
	
	//testButton->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&Juego::exitGame, this));

	m_gui.setMouseCursor("TaharezLook/MouseArrow");
	m_gui.showMouseCursor();
	return true;
}