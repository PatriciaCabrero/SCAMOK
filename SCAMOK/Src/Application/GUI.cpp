#include "GUI.h"

CEGUI::OgreRenderer*  GUI::m_renderer = nullptr;

void  GUI::init(const std::string& resourceDirectory) {
	// Check if the renderer and system were not already initialized
	if (m_renderer == nullptr) {
		m_renderer = &CEGUI::OgreRenderer::create();
		CEGUI::System::create(*m_renderer);
		//m_renderer = &CEGUI::OgreRenderer::bootstrapSystem();

		CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
		rp->setResourceGroupDirectory("imagesets", resourceDirectory + "/imagesets");
		rp->setResourceGroupDirectory("schemes", resourceDirectory + "/schemes");
		rp->setResourceGroupDirectory("fonts", resourceDirectory + "/fonts");
		rp->setResourceGroupDirectory("layouts", resourceDirectory + "/layouts/");
		rp->setResourceGroupDirectory("looknfeels", resourceDirectory + "/looknfeel/");
		//rp->setResourceGroupDirectory("lua_scripts", resourceDirectory + "/lua_scripts/");

		CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
		CEGUI::Font::setDefaultResourceGroup("fonts");
		CEGUI::Scheme::setDefaultResourceGroup("schemes");
		CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
		CEGUI::WindowManager::setDefaultResourceGroup("layouts");
		
	}

	m_context = &CEGUI::System::getSingleton().createGUIContext(m_renderer->getDefaultRenderTarget());
	m_root = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "root");
	m_context->setRootWindow(m_root);
}

void  GUI::destroy() {
	CEGUI::System::destroy();
	CEGUI::OgreRenderer::destroy(static_cast<CEGUI::OgreRenderer&>(*m_renderer));
//	CEGUI::System::getSingleton().destroyGUIContext(*m_context);
}

void  GUI::draw() {
	//CEGUI::System::getSingleton().renderAllGUIContexts();
	m_renderer->beginRendering();
	m_context->draw();
	m_renderer->endRendering();
}

void GUI::moveMouse(int x, int y) {
	m_context->injectMousePosition(x, y);
}
void GUI::clickMouse() {
	m_context->injectMouseButtonClick(CEGUI::MouseButton::LeftButton);
}
void GUI::setMouseCursor(const std::string&imageFile) {
	m_context->getMouseCursor().setDefaultImage(imageFile);
}
void GUI::showMouseCursor() {
	m_context->getMouseCursor().show();
}
void GUI::hideMouseCursor() {
	m_context->getMouseCursor().hide();
}
void  GUI::loadScheme(const std::string& schemeFile) {
	CEGUI::SchemeManager::getSingleton().createFromFile(schemeFile);
}

CEGUI::Window*  GUI::createWidget(const std::string& type, const glm::vec4& destRectPerc, const glm::vec4& destRectPix, const std::string& name /*= ""*/) {
	CEGUI::Window* newWindow = CEGUI::WindowManager::getSingleton().createWindow(type, name);
	m_root->addChild(newWindow);
	setWidgetDestRect(newWindow, destRectPerc, destRectPix);
	return newWindow;
}

void  GUI::setWidgetDestRect(CEGUI::Window* widget, const glm::vec4& destRectPerc, const glm::vec4& destRectPix) {
	widget->setPosition(CEGUI::UVector2(CEGUI::UDim(destRectPerc.x, destRectPix.x), CEGUI::UDim(destRectPerc.y, destRectPix.y)));
	widget->setSize(CEGUI::USize(CEGUI::UDim(destRectPerc.z, destRectPix.z), CEGUI::UDim(destRectPerc.w, destRectPix.w)));
}

void  GUI::setFont(const std::string& fontFile) {
	CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
	m_context->setDefaultFont(fontFile);
}