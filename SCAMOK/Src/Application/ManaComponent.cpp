#include "ManaComponent.h"  
#include "OgreParticleSystem.h"

ManaComponent::ManaComponent(Entidad* pEnt) : Componente(pEnt) 
{
} 
ManaComponent::~ManaComponent() { 
} 
void ManaComponent::Update(float deltaTime, Mensaje const & msj)
{
	Mensaje msg = msj;
	if (msg.getTipo() == Tipo::Gui) {
		if (msg.getSubTipo() == SubTipo::InitGui) {
			mana = static_cast<CEGUI::ProgressBar*>(pEntidad->getPEstado()->getGUIRoot()->getChild("Power"));
			maxMana = mana->getWidth().d_offset;
		}
		else if (msg.getSubTipo() == SubTipo::CambiaMana && mana != nullptr) {
			if (msg.getMsg()[0] == '+') {
				std::string s;
				s = msg.getMsg().substr(1, msg.getMsg().size());
				CEGUI::UDim dim = mana->getWidth();
				if (dim.d_offset < maxMana) {
					dim += {0, std::stof(s)};
					mana->setWidth(dim);
				}
			}
			else if (msg.getMsg()[0] == '-') {
				std::string s;
				s = msg.getMsg().substr(1, msg.getMsg().size());
				CEGUI::UDim dim = mana->getWidth();
					dim -= {0, std::stof(s)};
					mana->setWidth(dim);
			}
		}
	}
	if (msg.getTipo() == Tipo::Mana) {
		if (msg.getSubTipo() == SubTipo::DoPower && mana != nullptr) {

			if (mana->getWidth().d_offset >= 24) {
				Entidad* aux1 = new Entidad(pEntidad->getPEstado());

				string auxBala = pEntidad->getPEstado()->getFactory()->create("triangulo");
				aux1->setNombreNodo(auxBala);

				aux1->añadeComponenteGrafico("triangulo", auxBala);
				aux1->añadeComponenteFisico(0, 0, 0, false, tipoFisica::Dinamico, 1);
				aux1->añadeComponenteLogico("BalaComponent");
				pEntidad->getPEstado()->addEntidad(auxBala, aux1);
				restaPower();
				// create a particle system named explosions using the explosionTemplate
				Ogre::ParticleSystem* particleSystem = pEntidad->getPEstado()->getScnManager()->createParticleSystem(auxBala + "PFX", "Smoke");
				pEntidad->getPEstado()->getScnManager()->getSceneNode(auxBala)->attachObject(particleSystem);
				particleSystem->setEmitting(true);
			}
		}
	}
}

void ManaComponent::restaPower()
{
	Mensaje ms(Tipo::Gui, "-25", SubTipo::CambiaMana);
	ms.setMsgInfo(pEntidad, pEntidad);
	pEntidad->getPEstado()->addMsg(ms, true);
}
