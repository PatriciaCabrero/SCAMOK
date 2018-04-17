#pragma once 
#include "Camara.h"


using namespace Ogre;
Camara::Camara(Entidad * pEnt) : Componente(pEnt)
{
	cam = pEnt->getPEstado()->getScnManager()->createCamera("MainCamera");
	cam->setPosition(0, 20, -50);
	cam->lookAt(0, 0, 0);
	cam->setNearClipDistance(5);
	node = pEnt->getPEstado()->getScnManager()->getSceneNode("GNodesinbad")->createChildSceneNode("NodoCamera");
	node->attachObject(cam);

	//set viewport
	vp = pEnt->getPEstado()->getWin()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));

	cam->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) /
		Ogre::Real(vp->getActualHeight()));
	
	//pEntidad->getPEstado()->getScnManager()->getSceneNode("GNodesinbad")->attachObject(node);
}

Camara::~Camara()
{
}
void Camara::attach(Ogre::SceneNode* node) {
	node->attachObject(cam);
}
void Camara::Update(float deltaTime, Mensaje const & msj) {
	Mensaje msg = msj;

	//if (msg.getTipo() == Input && msg.getReceptor() == pEntidad) {
		
		if (msg.getSubTipo() == SubTipo::Rotar) {
			int pos = msg.getMsg().find("/");
			std::string xS = msg.getMsg().substr(0, pos);
			std::string subcad = msg.getMsg().substr(pos + 1);
			pos = subcad.find("/");
			std::string yS = subcad.substr(0, pos);
			std::string zS = subcad.substr(pos + 1);

			float x = std::stof(xS);
			float z = -1* std::stof(zS);

			node->rotate(Ogre::Quaternion(Ogre::Degree(-x*2), Ogre::Vector3::UNIT_Y));
			//node->rotate(Ogre::Quaternion(Ogre::Degree(z), Ogre::Vector3::UNIT_X));
		//}
	}
}