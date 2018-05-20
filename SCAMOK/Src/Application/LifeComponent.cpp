#include "LifeComponent.h"  
 
LifeComponent::LifeComponent(Entidad* pEnt): Componente(pEnt) {
	
} 
LifeComponent::~LifeComponent() { 
}
void LifeComponent::Update(float deltaTime, Mensaje const & msj)
{
	Mensaje msg = msj;
	if (msg.getTipo() == Tipo::Gui) {
		if (msg.getSubTipo() == SubTipo::InitGui) {
			life = static_cast<CEGUI::ProgressBar*>(pEntidad->getPEstado()->getGUIRoot()->getChild("Life"));
			maxLife = life->getWidth().d_offset;
		}
		else if (msg.getSubTipo() == SubTipo::CambiaVida) {
			if (msg.getMsg() == "+") {
				CEGUI::UDim dim = life->getWidth();
				if (dim.d_offset < maxLife) {
					dim += {0, 0.01f};
					life->setWidth(dim);
				}
			}
			else if (msg.getMsg() == "-") {
				CEGUI::UDim dim = life->getWidth();
				if (dim.d_offset > 1) {
					dim -= {0, 25};
					life->setWidth(dim);
				}
			}
		}
	}
}

