#pragma once 
#include "Componente.h"
#include "Estado.h"

class ManaComponent: public Componente 
{
public: 
	ManaComponent(Entidad* pEntidad);
	~ManaComponent(); 
	virtual void Update(float deltaTime, Mensaje const & msj);
private:
	CEGUI::ProgressBar * mana = nullptr;
	int maxMana;
	void restaPower();
}; 
