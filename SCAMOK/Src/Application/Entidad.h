#pragma once
#include "Componente.h"
#include <iterator>
#include "Mensaje.h"

class Estado;
//enum tipoFisica { Dinamico, Estatico, Kinematico };
class Entidad{

public:
	Entidad(Estado* pEstado);
	Entidad(Estado* pEstado, std::string prefab);
	void Update(float deltaTime, Mensaje const & msg);
	void Awake();
	void Sleep();
	Estado* getPEstado() { return pEstado; };

	bool añadeComponenteGrafico(std::string mesh);
	bool añadeComponenteFisico(float altoCaja, float anchoCaja, float profCaja, bool suelo, tipoFisica type = tipoFisica::Estatico, int masa = 0, bool mainChar = false);
	bool añadeAnimacion(std::string mesh, std::ifstream & fe);
	bool añadeAnimacion(std::string name,bool enabled = true, bool loop = true);
	bool añadeComponenteLogico(std::string component);
	

private:
	std::map<std::string, Componente*> componentes;
	Estado* pEstado;
	bool activo;
	Entidad* target; //Usar esta entidad para escuchar los mensajes dirigidos a ella
	
};