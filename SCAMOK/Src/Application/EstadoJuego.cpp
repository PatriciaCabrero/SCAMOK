#pragma once
#include "EstadoJuego.h"
#include "FactoryBalas.h"
#include <iostream>
#include "OgreParticleSystem.h"
EstadoJuego::EstadoJuego(Ogre::SceneManager * mng, Ogre::RenderWindow* mWindow, FMOD::System* sys): Estado(mng, mWindow, sys)
{
	//gContactAddedCallback = callbackFunc;
	noInput = true; contInput = 0;
	cargaGui();
	
}

bool callbackFunc(btManifoldPoint& cp, const btCollisionObject* ob1, int id1,int index1, const btCollisionObject* ob2, int id2, int index2) {
	std::cout << "collision\n";
	return false;
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
void EstadoJuego::restaPower()
{
	CEGUI::UDim dim = power->getWidth();
	dim -= {0, 25};
	power->setWidth(dim);
}
bool EstadoJuego::initCEGUI() {
	//Estado::initCEGUI();

	guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("Hud.layout");
	m_gui.getRoot()->addChild(guiRoot);

	life = static_cast<CEGUI::ProgressBar*>(guiRoot->getChild("Life"));
	power = static_cast<CEGUI::ProgressBar*>(guiRoot->getChild("Power"));
	maxPower = power->getWidth().d_offset;
	
	return true;
}
bool EstadoJuego::update(float delta) {
	CEGUI::System::getSingleton().injectTimePulse(1.0f / delta);
	//CEGUI::System::getSingleton().injectTimePulse(0.016f);
	this->getFisicManager()->getDynamicsWorld()->stepSimulation(1.0f / delta);


	///////////////////////////////
	//Los Manifolds son las colisiones (de pares de objetos) que existen en cada momento en el mundo físico
	int numManifolds = getFisicManager()->getDynamicsWorld()->getDispatcher()->getNumManifolds();
	for (int i = 0; i < numManifolds; i++)
	{
		//
		btPersistentManifold* contactManifold = getFisicManager()->getDynamicsWorld()->getDispatcher()->getManifoldByIndexInternal(i);
		//obA y obB son los pares de objetos que están colisionando
		const btCollisionObject* obA = contactManifold->getBody0();
		const btCollisionObject* obB = contactManifold->getBody1();
		void* userPointer = obA->getUserPointer();
		if (userPointer) {
			Ogre::SceneNode *sceneNode = static_cast<Ogre::SceneNode *>(userPointer);
			std::string nombre = sceneNode->getName();
			nombre = nombre.substr(0, 9);
			if (nombre == "triangulo") {
				//El cuerpo A es una bala
				std::cout << "HEADSHOT";
			}
			else {
				userPointer = obB->getUserPointer();
				if (userPointer) {
					Ogre::SceneNode *sceneNode = static_cast<Ogre::SceneNode *>(userPointer);
					std::string nombre = sceneNode->getName();
					nombre = nombre.substr(0, 9);
					if (nombre == "triangulo") {
						//El cuerpo b es una bala
						std::cout << "HEADSHOT";
					}
				}
			
			}
			
		
		}
		//int numContacts = contactManifold->getNumContacts();
		//std::cout << numContacts << "\n";
		/*for (int j = 0; j < numContacts; j++)
		{
			btManifoldPoint& pt = contactManifold->getContactPoint(j);
			if (pt.getDistance() < 0.f)
			{
				const btVector3& ptA = pt.getPositionWorldOnA();
				const btVector3& ptB = pt.getPositionWorldOnB();
				const btVector3& normalOnB = pt.m_normalWorldOnB;
			}
		}*/
	}




	for (size_t i = 0; i < borrar.size(); i++)
	{
		entidades.at(borrar[i])->destruyeComponenteGrafico();
		btRigidBody* b = getFisicManager()->getRigidBody(borrar[i]);
		getFisicManager()->getDynamicsWorld()->removeRigidBody(b);
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

	if (power != nullptr) {
		CEGUI::UDim dim = power->getWidth();
		if (dim.d_offset < maxPower) {
			dim += {0, 0.01f};
			power->setWidth(dim);
		}
	}
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
	else if (s == "5" || s == "disparo") {
		if (power->getWidth().d_offset >= 24) {
			Entidad* aux1 = new Entidad(this);

			string auxBala = factoria->create("triangulo");
			aux1->setNombreNodo(auxBala);
			
			aux1->añadeComponenteGrafico("triangulo", auxBala);
			aux1->añadeComponenteFisico(0, 0, 0, false, tipoFisica::Dinamico, 1);
			aux1->añadeComponenteLogico("BalaComponent");
			entidades.insert(std::make_pair(auxBala, aux1));
			//restaPower();
			// create a particle system named explosions using the explosionTemplate
			Ogre::ParticleSystem* particleSystem = scnMgr->createParticleSystem(auxBala+"PFX","Smoke");
			scnMgr->getSceneNode(auxBala)->attachObject(particleSystem);
			particleSystem->setEmitting(true);
		}
	}

}
void EstadoJuego::keyReleased(std::string s) {


}