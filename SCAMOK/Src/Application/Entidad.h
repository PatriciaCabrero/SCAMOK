#pragma once
#include "Componente.h"
#include <iterator>
#include "Mensaje.h"

class Estado;

class Entidad{

public:
	Entidad(Estado* pEstado);
	void Update(float deltaTime, Mensaje& msg);
	void Awake();
	void Sleep();
	Estado* getPEstado() { return pEstado; };
private:
	std::map<std::string, Componente*> componentes;
	Estado* pEstado;
	bool activo;
};