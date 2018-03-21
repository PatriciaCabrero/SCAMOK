#pragma once 
#include "Camara.h"

using namespace Ogre;
Camara::Camara(Entidad * pEnt) : Componente(pEnt)
{
	cam = pEnt->getPEstado()->getScnManager()->createCamera("MainCamera");
	cam->setPosition(0, 20, -50);
	cam->lookAt(0, 0, 0);
	cam->setNearClipDistance(5);
	node = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode("NodoCamera");
	node->attachObject(cam);

	//set viewport
	vp = pEnt->getPEstado()->getWin()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));

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
		
		if (msg.getSubTipo() == SubTipo::Mover) {
			
			Ogre::Vector3 pos = pEntidad->getPEstado()->getScnManager()->getSceneNode("sinbad")->getPosition();
			int x = 0; int z = 0;

			if (!(node->getPosition().x == (int)pos.x && node->getPosition().z == (int)pos.z)) {
				if (abs(node->getPosition().x) > (int)pos.x) x = -1;
				else if (node->getPosition().x < (int) pos.x) x = 1;

				if (node->getPosition().z > (int) pos.z - 50) z = 1;
				else if (node->getPosition().z < (int)pos.z - 50) {
					z = -1;
				}

				node->translate(x, 0, z);
				Mensaje* m = new Mensaje(Tipo::Input, "", SubTipo::Mover);
				m->setMsgInfo(pEntidad, pEntidad);
				pEntidad->getPEstado()->addMsg(*m);
			}
			
			//node->lookAt(Ogre::Vector3(node->getPosition().x + std::stof(zS), node->getPosition().y, node->getPosition().z - std::stof(xS)), Node::Node::TS_WORLD, Vector3::UNIT_X);
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