#pragma once
#include <CEGUI\CEGUI.h>
#include <CEGUI\RendererModules\Ogre\Renderer.h>



class GUI
{
public:
	/*GUI();
	~GUI();*/
	static void init(const std::string& resourcesDirectory);
	void destroy();

private:
	static CEGUI::OgreRenderer* renderer_;
};

