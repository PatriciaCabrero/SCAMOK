#pragma once
#include "Componente.h"
#include "Estado.h"
class Estado;

class GComponent : public Componente {
public:
	GComponent(Entidad* pEnt, std::string name = "ogrehead");
	virtual ~GComponent();

	virtual void Update(float deltaTime, Mensaje const & msj);
	virtual void destroy();

	void rota(float angle, Ogre::Vector3 eje);
	void translate(float x, float y, float z);
	void scale(float x, float y, float z);
	
protected:
	Ogre::SceneNode * node, *groupNode, *nodeCh;
	Ogre::Entity * ent;
	bool firstMsg;
};