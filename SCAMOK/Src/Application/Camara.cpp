#pragma once 
#include "Camara.h"

using namespace Ogre;
Camara::Camara(Entidad * pEnt) : Componente(pEnt)
{
	cam = pEnt->getPEstado()->getScnManager()->createCamera("camera");
	cam->setPosition(0, 35, -100);
	cam->lookAt(0, 0, 0);
	cam->setNearClipDistance(5);
	node = pEnt->getPEstado()->getScnManager()->getSceneNode("GNodesinbad")->createChildSceneNode("NodoCamera");
	node->attachObject(cam);

	//set viewport
	vp = pEnt->getPEstado()->getWin()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(0, 150, 150));

	cam->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) /
		Ogre::Real(vp->getActualHeight()));
	velX = 0;
	cont = 0;
	
	
}

Camara::~Camara()
{
	
}
void Camara::attach(Ogre::SceneNode* node) {
	node->attachObject(cam);
}
void Camara::Update(float deltaTime, Mensaje const & msj) {
	Mensaje msg = msj;
	cont++;
	if (msg.getTipo() == Input && msg.getReceptor() == pEntidad) {
		
		if (msg.getSubTipo() == SubTipo::OrientaCamara) {
			int pos = msg.getMsg().find("/");
			std::string xS = msg.getMsg().substr(0, pos);
			std::string subcad = msg.getMsg().substr(pos + 1);
			pos = subcad.find("/");
			std::string yS = subcad.substr(0, pos);
			std::string zS = subcad.substr(pos + 1);

			velX = std::stof(xS)*deltaTime/4;
			float z = std::stof(zS);

			
		}

	}
	else if (cont >= 4) {
		cont = 0;
		velX *= 0.9*0.9*0.9*0.9;
		if (abs(velX) < 0.01)
			velX = 0;
	}

	node->rotate(Ogre::Quaternion(Ogre::Degree(velX), Ogre::Vector3::UNIT_Y));
}