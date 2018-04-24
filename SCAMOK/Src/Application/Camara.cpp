#pragma once 
#include "Camara.h"

using namespace Ogre;
Camara::Camara(Entidad * pEnt) : Componente(pEnt)
{
	altura = 0;
	cam = pEntidad->getPEstado()->getScnManager()->createCamera("MainCamera");
	cam->setPosition(0, 20, -75);
	cam->lookAt(0, 0, 0);
	cam->setNearClipDistance(5);
	node = pEntidad->getPEstado()->getScnManager()->getSceneNode("GNodesinbad")->createChildSceneNode("NodoCamera");
	node->attachObject(cam);

	//set viewport
	vp = pEntidad->getPEstado()->getWin()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(0, 150, 150));

	cam->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) /
		Ogre::Real(vp->getActualHeight()));
	
	
}

Camara::~Camara()
{
	
}
void Camara::attach(Ogre::SceneNode* node) {
	node->attachObject(cam);
}
void Camara::Update(float deltaTime, Mensaje const & msj) {
	Mensaje msg = msj;

	if (msg.getTipo() == Input && msg.getReceptor() == pEntidad) {
		
		if (msg.getSubTipo() == SubTipo::OrientaCamara) {
			int pos = msg.getMsg().find("/");
			std::string xS = msg.getMsg().substr(0, pos);
			std::string subcad = msg.getMsg().substr(pos + 1);
			pos = subcad.find("/");
			std::string yS = subcad.substr(0, pos);
			std::string zS = subcad.substr(pos + 1);

			//ROTACION LATERAL
			float x = std::stof(xS);
			node->yaw(Ogre::Degree(x*2), Node::TS_WORLD);

			//ROTACION VERTICAL
			float z = -1* std::stof(zS);
			/*//if(altura >= 0 && altura <= 10)
			//	altura += z;

			node->translate(Vector3(0, z, 0));*/
			
			//node->pitch(Ogre::Degree(altura));
			//Ogre::Real a = node->getOrientation().
			if (node->getOrientation().getPitch().valueDegrees() < 0 && z > 0) {
				node->pitch(Ogre::Degree(z * 2),Node::TS_LOCAL);
			}else if (node->getOrientation().getPitch().valueDegrees() > 10 && z < 0) {
				node->pitch(Ogre::Degree(z * 2), Node::TS_LOCAL);
			}else if(node->getOrientation().getPitch().valueDegrees() >= 0 && node->getOrientation().getPitch().valueDegrees() < 10)
				node->pitch(Ogre::Degree(z * 2),Node::TS_LOCAL);


		}
	}
}