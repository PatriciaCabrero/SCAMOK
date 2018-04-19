#include "GUI.h"

CEGUI::OgreRenderer* GUI::renderer_ = nullptr;

void GUI::init(const std::string& resourcesDirectory)
{
	if (renderer_ == nullptr) {
		renderer_ = &CEGUI::OgreRenderer::bootstrapSystem();  //Crea objetos especificos e inicializa para Ogre;

		CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
		rp->setResourceGroupDirectory("imagesets", resourcesDirectory + "/imagesets/"); //dentro de imagesets podemos crear nuestros propios sets
		rp->setResourceGroupDirectory("schemes", resourcesDirectory + "/schemes/"); //Schemes: tipos de botones, etc.
		rp->setResourceGroupDirectory("fonts", resourcesDirectory + "/fonts/"); //Fuentes de texto;
		rp->setResourceGroupDirectory("layouts", resourcesDirectory + "/layouts/");
		rp->setResourceGroupDirectory("looknfeels", resourcesDirectory + "/looknfeels/");
		rp->setResourceGroupDirectory("lua_scripts", resourcesDirectory + "/lua_scripts/");


		CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
		CEGUI::Scheme::setDefaultResourceGroup("schemes");
		CEGUI::Font::setDefaultResourceGroup("fonts");
		CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
		CEGUI::WindowManager::setDefaultResourceGroup("layouts");
		CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");
	}
}

void GUI::destroy()
{
}
