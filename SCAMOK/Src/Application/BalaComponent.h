#pragma once 

#include "FComponent.h"
class BalaComponent: public Componente { 
public: 
	BalaComponent(Entidad* pEntidad); 
	~BalaComponent(); 

	virtual void Update(float deltaTime, Mensaje const & msj);//A rellenar con el cuenta steps
	virtual void destroy() {};

	float tiempoInicio;
}; 
