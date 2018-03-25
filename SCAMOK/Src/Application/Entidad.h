#pragma once
#include "Transform.h"
#include <iterator>
#include "Mensaje.h"

class Estado;

class Entidad{

public:
	Entidad(Estado* pEstado);
	Entidad(Estado* pEstado, std::string prefab);
	void Update(float deltaTime, Mensaje const & msg);
	void Awake();
	void Sleep();
	Estado* getPEstado() { return pEstado; };

	bool aņadeComponenteGrafico(std::string mesh);
	bool aņadeComponenteFisico();
	bool aņadeAnimacion(std::string mesh, std::ifstream & fe);
	bool aņadeAnimacion(std::string name,bool enabled = true, bool loop = true);
	bool aņadeComponenteLogico(std::string component);
	//Puenteo necesario para acceder al transform del objeto
	bool getEntityTransform(int& x, int& y, int& z) {
		Componente* transform = componentes.at("Transform");
		Transform* t = nullptr;
		if (transform) {
			t = dynamic_cast<Transform*>(transform);
			t->getTransform(x, y, z);
			return true;
		}
		return false;
	}
	

private:
	std::map<std::string, Componente*> componentes;
	Estado* pEstado;
	bool activo;
	Entidad* target; //Usar esta entidad para escuchar los mensajes dirigidos a ella
	
};