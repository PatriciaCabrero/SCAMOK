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
}

bool Juego::init(){
	
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
	// pretend the user used some other mechanism to select the // OpenGL renderer String rName("OpenGL Rendering Subsystem"); RenderSystemList *rList = root->getAvailableRenderers(); RenderSystemList::iterator it = rList->begin(); RenderSystem *rSys = 0;
	Ogre::RenderSystemList rList = root->getAvailableRenderers(); 
	Ogre::RenderSystemList::iterator it = rList.begin();
	Ogre::RenderSystem* rSys = 0;
	while (it != rList.end()) {
		// Ogre strings are typedefs of std::string RenderSystem *rSys = *(it++); if (rSys->getName().find("OpenGL")) {
		// set the OpenGL render system for use root->setRenderSystem(rSys); break;
		rSys = *(it++); 
		if (rSys->getName() == "OpenGL Rendering Subsystem") {
			// set the OpenGL render system for use 
			root->setRenderSystem(rSys); 
			break;
		}
	}
		if (root->getRenderSystem() == NULL) {
			delete root; 
			return false;
		}
	
	
//	root->setRenderSystem()
	 root->initialise(false);
	 mWindow = root->createRenderWindow("Manual Ogre Window",  // window name 
		 800,  
															   // window width, in pixels 
		 600,    
															   // window height, in pixels 
		 false,           
															   // fullscreen or not 
		 0);               
															   // use defaults for all other values

	
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
	scnMgr = root->createSceneManager(Ogre::ST_GENERIC, "MySceneManager");



	return true;
}

bool Juego::run(){

	Estado * pEstado = new Estado(scnMgr, mWindow);
	pEstados.push(pEstado);

	while (true)
	{

		pEstados.top()->update(12.0f);

		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		

		//comprobar si la ventana está abierta
		if (mWindow->isClosed())return false;
		if (!root->renderOneFrame())return false;
	}
}

Juego::~Juego()
{
}
