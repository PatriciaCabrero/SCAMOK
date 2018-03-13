#pragma once
#include <map>
class Entidad;
class Mensaje;

class Componente {

public:
	Componente(Entidad* pEnt){ pEntidad = pEnt; };
	~Componente(){};
	virtual void Update(float deltaTime, Mensaje& msj) { if (!activo) return; };
	virtual void Awake() { activo = true; };
	virtual void Sleep() { activo = false; };

protected:
	bool activo;
	Entidad* pEntidad;
};