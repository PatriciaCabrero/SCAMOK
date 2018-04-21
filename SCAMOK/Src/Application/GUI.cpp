#include "GUI.h"

CEGUI::OpenGL3Renderer* GUI::renderer_ = nullptr;

void GUI::init(const std::string& resourcesDirectory)
{
	if (renderer_ == nullptr) {
		renderer_ = &CEGUI::OpenGL3Renderer::bootstrapSystem();  //Crea objetos especificos e inicializa para Ogre;

		CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
		rp->setResourceGroupDirectory("imagesets", resourcesDirectory + "/imagesets/"); //dentro de imagesets podemos crear nuestros propios sets
		rp->setResourceGroupDirectory("schemes", resourcesDirectory + "/schemes/"); //Schemes: tipos de botones, etc.
		rp->setResourceGroupDirectory("fonts", resourcesDirectory + "/fonts/"); //Fuentes de texto;
		rp->setResourceGroupDirectory("layouts", resourcesDirectory + "/layouts/");
		rp->setResourceGroupDirectory("looknfeels", resourcesDirectory + "/looknfeels/");
		rp->setResourceGroupDirectory("lua_scripts", resourcesDirectory + "/lua_scripts/");


		CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
		CEGUI::Scheme::setDefaultResourceGroup("schemes"); //Cada esquema tiene widgets, están en la carpeta media
		CEGUI::Font::setDefaultResourceGroup("fonts");
		CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
		CEGUI::WindowManager::setDefaultResourceGroup("layouts");
		CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");
	}

	context_ = &CEGUI::System::getSingleton().createGUIContext(renderer_->getDefaultRenderTarget());
	root_ = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "root"); //Podemos añadir diferentes widgets a este root
	context_->setRootWindow(root_);
}

void GUI::destroy()
{
	CEGUI::System::getSingleton().destroyGUIContext(*context_);
}

void GUI::draw()
{
	renderer_->beginRendering();
	context_->draw(); //Dibuja todo lo del contexto
	renderer_->endRendering();
	glDisable(GL_SCISSOR_TEST);
}

void GUI::loadScheme(const std::string & schemeFile)
{
	CEGUI::SchemeManager::getSingleton().createFromFile(schemeFile);
}

void GUI::setFont(const std::string & fontFile)
{
	CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
	context_->setDefaultFont(fontFile);
}

CEGUI::Window * GUI::createWidget(const std::string & scheme, const Ogre::Vector4& destRectPerc, const Ogre::Vector4& destRectPix, const std::string & name)
{
	//widgets son ventanas
	CEGUI::Window* newWindow = CEGUI::WindowManager::getSingleton().createWindow(scheme, name);
	root_->addChild(newWindow);
	setWidgetDestRect(newWindow, destRectPerc, destRectPix);
	return newWindow;
}

void GUI::setWidgetDestRect(CEGUI::Window * widget, const Ogre::Vector4 & destRectPerc, const Ogre::Vector4 & destRectPix)
{
	widget->setPosition(CEGUI::UVector2(CEGUI::UDim(destRectPerc.x, destRectPix.x), CEGUI::UDim(destRectPerc.y, destRectPix.y)));
	widget->setSize(CEGUI::USize(CEGUI::UDim(destRectPerc.z, destRectPix.z), CEGUI::UDim(destRectPerc.w, destRectPix.w)));
}
