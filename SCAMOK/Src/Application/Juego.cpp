#include "Juego.h"
#include "Estado.h"

Juego::Juego()
{

#ifdef _DEBUG
	plugins = "OgreD/plugins_d.cfg";
	recursos = "OgreD/resources_d.cfg";
#else
	plugins = "Ogre/plugins.cfg";
	recursos = "Ogre/resources.cfg";
#endif
	
	init();
	initFmod();
	initCEGUI();
}

bool Juego::init(){
	if (initOgre()){
		if (initOis())
#ifdef _DEBUG || !_WIN32
			std::cout << "\n\n\n\n\nDebug\n\n\n\n";
#else
			std::cout << "\n\n\n\n\nRelease\n\n\n\n";
#endif
			return true;
	}
	else return false;
}

bool Juego::initCEGUI() {
	m_gui.init("../Media/GUI");
	m_gui.loadScheme("TaharezLook.scheme");
	//m_gui.loadScheme("HUDDemo.scheme");

	m_gui.loadScheme("Generic.scheme");
	m_gui.setFont("DejaVuSans-10");
	
	CEGUI::Window *guiRoot = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("TaharezLookOverview.layout");
	m_gui.getRoot()->addChild(guiRoot);
	CEGUI::PushButton* aux = static_cast<CEGUI::PushButton*>(guiRoot->getChild("StaticImage")->getChild("button"));
	aux->setText("Suavisado");
	aux->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&Juego::exitGame, this));
	//TaharezLook/Button/disableButton
	//aux->activate();
		CEGUI::PushButton* testButton = static_cast<CEGUI::PushButton*>(m_gui.createWidget("TaharezLook/Button", glm::vec4(0.5f, 0.5f, 0.1f, 0.05f), glm::vec4(0.0f), "TestButton"));
	testButton->setText("Hello GUI!");
	testButton->subscribeEvent(CEGUI::PushButton::EventMouseButtonDown, CEGUI::Event::Subscriber(&Juego::exitGame, this));

	m_gui.setMouseCursor("TaharezLook/MouseArrow");
	m_gui.showMouseCursor();


	//m_gui getRootWindow()->addChild(BloodScreen);

	return true;
}
bool Juego::initOis(){
	
	//mInputMgr = new InputManager(*mInputMgr);
	mInputMgr = InputManager::getSingletonPtr();
	mInputMgr->initialise(mWindow);
	mInputMgr->addKeyListener(this, "KeyListener");
	mInputMgr->addMouseListener(this, "MouseListener");
	mInputMgr->addJoystickListener(this, "JoystickListener");
	//mMouse = static_cast<OIS::Mouse*>(mInputMgr->createInputObject(OIS::OISMouse, true));

	mInputMgr->getKeyboard()->setEventCallback(this);
	mInputMgr->getMouse()->setEventCallback(this);


	return true;
}
bool Juego::initOgre(){
	root = new Ogre::Root(plugins);

	//------------------------------------------------------------------------------------------------------
	//Setting UP Resources 

	//Parsing the config file into the system.

	try{
		cf.load(recursos);
	}
	catch (Ogre::Exception e){
		std::cout << "\n" << e.getFile();
	}

	//name: Path to resources in disk,
	//loctype: defines what kind of location the element is (e.g. Filesystem, zip..)
	Ogre::String name, locType;

	//We now iterate through rach section in the resources.cfg.
	//Sections are signaled as [NAME]
	Ogre::ConfigFile::SectionIterator secIt = cf.getSectionIterator();
	while (secIt.hasMoreElements())
	{
		Ogre::ConfigFile::SettingsMultiMap* settings = secIt.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator it;

		//Now we are iterating INSIDE the section [secIt]
		for (it = settings->begin(); it != settings->end(); ++it)
		{
			locType = it->first;
			name = it->second;

			//We now know the type of the element and its path.
			//We add it as a location to the Resource Group Manager
			try {
				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
				std::cout << "inserting:\n";
				std::cout << name << locType << std::endl;
			}
			catch (Ogre::Exception e)
			{

			}
		}
	}
	//------------------------------------------------------------------------------------------------------
	// Render System Config

	//If there is no previous Ogre.cfg, this displays the config dialog
	if (!(root->restoreConfig() || root->showConfigDialog()))
		return false;

	//------------------------------------------------------------------------------------------------------
	//Render Window Creation
	mWindow = root->initialise(true, "Behind the rainbow");

	//------------------------------------------------------------------------------------------------------
	//Resources Init

	//We are only going to use 5 mimpams at a time. Mipmaps are efficent ways to save a texture.
	//Taking only 1/3 more of space, we can have several sizes of the texture to choose from.
	Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

	//Now we init every resource previously added
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	//------------------------------------------------------------------------------------------------------
	//SceneManager Set Up

	//we generate the default sceneManager. (more SceneManagers in Ogre::ST_....)
	scnMgr = root->createSceneManager(Ogre::ST_GENERIC);

	return true;
}
bool Juego::initFmod() {
	unsigned int      version;
	result = FMOD::System_Create(&system);
	result = system->getVersion(&version);

	if (version < FMOD_VERSION)
	{
		std::cout << ("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}
	system->init(100, FMOD_INIT_NORMAL, NULL);
	return true;
}
bool Juego::run(){

	Estado * pEstado = new Estado(scnMgr, mWindow, system);
	pEstados.push(pEstado);
	
	int cont = 0;
	std::cout << "\n\n\n";
	contJoystick = 0;
	bool rend = false;
	
	while (!exit)
	{
		
		mInputMgr->capture();		
		CEGUI::System::getSingleton().injectTimePulse(0.016f);

		if (cont == 4) {
			handleInput();
			cont = 0;
		}
		else cont++;
		
		pEstados.top()->update(12.0f);
		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		

		//comprobar si la ventana está abierta
		if (mWindow->isClosed())return false;
		if ( cont%2 != 0 && !root->renderOneFrame())return false;
		m_gui.draw();
	}
	delete pEstado;
	return true;
}
bool Juego::povMoved(const OIS::JoyStickEvent & arg, int index) {
	std::cout << arg.state.mPOV->direction << "\n";
	return true;
}
bool Juego::exitGame(const CEGUI::EventArgs &e)
{
	std::cout << "kek\n";
	exit = true;
	return true;
}
bool Juego::axisMoved(const OIS::JoyStickEvent & arg, int index) {
	contJoystick++;

	
	return true;
}
bool Juego::buttonPressed(const OIS::JoyStickEvent & arg, int buton) {
	std::cout << buton << "\n";
	pEstados.top()->keyPressed(std::to_string(buton));
	return true;
}
bool Juego::keyPressed(const OIS::KeyEvent& ke)
{
	
	
	std::string key = "";
	switch (ke.key)
	{
	case OIS::KC_ESCAPE: exit = true;
		break;
	case OIS::KC_RETURN: key = "return";
		break;
	case OIS::KC_RIGHT: key = "der";
		break;
	case OIS::KC_LEFT: key = "izq";
		break;
	case OIS::KC_UP: key = "arr";
		break;
	case OIS::KC_DOWN: key = "aba";
		break;
	case OIS::KC_SPACE: key = "salto";
	default:
		break;
	}
	
	pEstados.top()->keyPressed(key);
	return true;
}

//Este método habría que llamarlo para que el movimiento sea continuo y se capturen las teclas pulsadas.
//Para esto hay que tener en cuenta el tiempo para que no se llene de mensajes.
void Juego::handleInput() {
	OIS::Keyboard * keyboard = mInputMgr->getKeyboard();

	if (keyboard != NULL) {
		//DIAGONALES
		if (keyboard->isKeyDown(OIS::KeyCode::KC_LEFT)&& keyboard->isKeyDown(OIS::KeyCode::KC_UP)) {
			pEstados.top()->joystickMoved(1, 1);
		}else if (keyboard->isKeyDown(OIS::KeyCode::KC_LEFT)&& keyboard->isKeyDown(OIS::KeyCode::KC_DOWN)) {
			pEstados.top()->joystickMoved(1, -1);
		}else if (keyboard->isKeyDown(OIS::KeyCode::KC_RIGHT)&&keyboard->isKeyDown(OIS::KeyCode::KC_UP)) {
			pEstados.top()->joystickMoved(-1, 1);
		}else if (keyboard->isKeyDown(OIS::KeyCode::KC_RIGHT)&& keyboard->isKeyDown(OIS::KeyCode::KC_DOWN)) {
			pEstados.top()->joystickMoved(-1, -1);
		}
		//Direcciones normales
		else if (keyboard->isKeyDown(OIS::KeyCode::KC_LEFT)) {
			pEstados.top()->joystickMoved(1, 0);
		}
		else if (keyboard->isKeyDown(OIS::KeyCode::KC_RIGHT)) {
			pEstados.top()->joystickMoved(-1, 0);
		}
		else if (keyboard->isKeyDown(OIS::KeyCode::KC_UP)) {
			pEstados.top()->joystickMoved(0, 1);
		}
		else if (keyboard->isKeyDown(OIS::KeyCode::KC_DOWN)) {
			pEstados.top()->joystickMoved(0, -1);
		}
	}

	OIS::JoyStick * js = mInputMgr->getJoystick(0);
	if (js != NULL) {
		if (js->getJoyStickState().mAxes[0].abs != 0 || js->getJoyStickState().mAxes[1].abs != 0) {

			float x = js->getJoyStickState().mAxes[1].abs / 32768.0f;
			float y = js->getJoyStickState().mAxes[0].abs / 32768.0f;

			if (abs(x) >= 0.2 || abs(y) >= 0.2)
				pEstados.top()->joystickMoved(-x, -y);
		}
		if (js->getJoyStickState().mAxes[2].abs != 0 || js->getJoyStickState().mAxes[3].abs != 0) {

			float x = js->getJoyStickState().mAxes[3].abs / 32768.0f;
			float y = js->getJoyStickState().mAxes[2].abs / 32768.0f;

			if (abs(x) >= 0.2 || abs(y) >= 0.2)
				pEstados.top()->joystickMoved(-x, -y, 1);
		}
	}
}
bool Juego::keyReleased(const OIS::KeyEvent& ke)
{
	std::string key = "";
	switch (ke.key)
	{
	case OIS::KC_ESCAPE: exit = true;
		break;
	case OIS::KC_RETURN: key = "return";
		break;
	case OIS::KC_RIGHT: key = "der";
		break;
	case OIS::KC_LEFT: key = "izq";
		break;
	case OIS::KC_UP: key = "arr";
		break;
	case OIS::KC_DOWN: key = "aba";
		break;
	default:
		break;
	}

	pEstados.top()->keyReleased(key);
	return true;
}

//MOUSE
bool Juego::mouseMoved(const OIS::MouseEvent& me) {
	//std::cout<<me.state.X.rel<<" , "<<me.state.Y.rel<< std::endl;
	m_gui.moveMouse(me.state.X.abs, me.state.Y.abs);
	return true;
}
bool Juego::mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id) {
	m_gui.downMouse(id);
	return true;
}
bool Juego::mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id) {
	m_gui.upMouse(id);
	return true;
}
Juego::~Juego()
{
	delete mInputMgr;
	delete root;
}
