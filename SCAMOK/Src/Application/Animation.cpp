#include "Animation.h"



Animation::Animation(Entidad * pEnt): Componente (pEnt)
{
}


Animation::~Animation()
{
	
}

void Animation::Update(float deltaTime, Mensaje const & msj) {
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);
	if (msg.getTipo() == Tipo::Animation) {

	}
}