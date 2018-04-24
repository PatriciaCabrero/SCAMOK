#pragma once
#include <CEGUI\CEGUI.h>
#include <CEGUI\RendererModules\Ogre\Renderer.h>
#include <OgreVector4.h>

class GUI
{
public:
	/*GUI() {};
	~GUI() {};*/
	 void init(const std::string& resourcesDirectory);
	void destroy();


	void draw();

	void loadScheme(const std::string& schemeFile);

	void setFont(const std::string& fontFile);

	CEGUI::Window* createWidget(const std::string& scheme, const Ogre::Vector4& destRectPerc, const Ogre::Vector4& destRectPix, const std::string& name = "");
	static void setWidgetDestRect(CEGUI::Window* widget, const Ogre::Vector4& destRectPerc, const Ogre::Vector4& destRectPix);

	static CEGUI::OgreRenderer* getRenderer() {
		return renderer_;
	}

	const CEGUI::GUIContext* getContext() {
		return context_;
	}
private:
	 static CEGUI::OgreRenderer* renderer_;
	 CEGUI::GUIContext* context_ = nullptr;
	 CEGUI::Window* root_ = nullptr;
};