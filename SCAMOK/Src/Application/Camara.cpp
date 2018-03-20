#pragma once 
#include "Camara.h"

using namespace Ogre;
Camara::Camara(Entidad * pEnt) : Componente(pEnt)
{
	cam = pEnt->getPEstado()->getScnManager()->createCamera("MainCamera");
	cam->setPosition(0, 20, -50);
	cam->lookAt(0, 0, 0);
	cam->setNearClipDistance(5);

	//set viewport
	vp = pEnt->getPEstado()->getWin()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));

	cam->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) /
		Ogre::Real(vp->getActualHeight()));


	pEntidad->getPEstado()->getScnManager()->getSceneNode("sinbad")->attachObject(cam);
	//cam->rotate(Quaternion(Degree(180), Vector3::UNIT_Y));
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
		if (msg.getSubTipo() == SubTipo::Mover) {
			int pos = msg.getMsg().find("/");
			std::string sz = msg.getMsg().substr(0, pos);
			std::string sx = msg.getMsg().substr(pos + 1);

			float x = -1 * std::stof(sx);
			float z = std::stof(sz);

			cam->rotate(Ogre::Quaternion(Ogre::Degree(x), Ogre::Vector3::UNIT_Y));
			cam->rotate(Ogre::Quaternion(Ogre::Degree(z), Ogre::Vector3::UNIT_X));
		}
	}

		else if (msg.getSubTipo() == SubTipo::Rotar) {
			//angle/int-> 0 = x, 1 = y, 2 = z
			int pos = msg.getMsg().find("/");
			std::string anguloS = msg.getMsg().substr(0, pos);
			std::string ejeS = msg.getMsg().substr(pos + 1);

			int eje = std::stoi(ejeS);
			float angulo = std::stof(anguloS);

			switch (eje)
			{
			case 0: cam->rotate(Ogre::Quaternion(Degree(angulo), Vector3::UNIT_X));
				break;
			case 1: cam->rotate(Quaternion(Degree(angulo), Vector3::UNIT_Y));
				break;
			case 2: cam->rotate(Quaternion(Degree(angulo), Vector3::UNIT_Z));
				break;
			default:
				break;
			}
	}
}