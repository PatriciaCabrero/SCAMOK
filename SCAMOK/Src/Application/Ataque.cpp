#include "Ataque.h"  
 
Ataque::Ataque(Entidad* pEntidad) : Componente(pEntidad) {
} 
Ataque::~Ataque() { 
} 

void Ataque::Update(float deltaTime, Mensaje const & msj) {
	Mensaje m = msj;
	if (m.getTipo() == Tipo::Input && m.getSubTipo() == SubTipo::Ataca) {
	
	
	}
}
