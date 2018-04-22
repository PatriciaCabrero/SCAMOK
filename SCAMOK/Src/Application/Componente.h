#pragma once
#include <map>
class Entidad;
class Mensaje;

class Componente {

public:
	Componente(Entidad* pEnt){ pEntidad = pEnt; };
	virtual ~Componente() {}// delete pEntidad; };
	virtual void Update(float deltaTime, Mensaje const & msj) { if (!activo) return; };
	virtual void Awake() { activo = true; };
	virtual void Sleep() { activo = false; };
	virtual void destroy() {};

protected:
	bool activo;
	Entidad* pEntidad;
};