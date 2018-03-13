#pragma once

/*#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include <OgreCamera.h>
#include <OgreEntity.h>
#include "OgreSceneNode.h"
#include <OgreConfig.h>
#include "OgreConfigFile.h"

#include <OgreTextureManager.h>
#include <OgreWindowEventUtilities.h>
#include <OgreException.h>
*/
#include "Componente.h"
#include "Estado.h"
class Estado;

class GComponent : public Componente {
public:
	GComponent(Entidad* pEnt);
	virtual void Update(float deltaTime, Mensaje const & msj);

private:
	Ogre::SceneNode * node;
	Ogre::Entity * ent;

};