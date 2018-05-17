#pragma once
#include "Componente.h"
#include "Estado.h"
class Ataque : public Componente{ 
public: 
	Ataque(Entidad* pEntidad);
	~Ataque(); 

	virtual void Update(float deltaTime, Mensaje const & msj);
}; 
