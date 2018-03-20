#pragma once
#include "Entidad.h"
#include "GComponent.h"
#include "Transform.h"
#include "Animation.h"
#include "Camara.h"
#include <iostream>
#include <fstream>

Entidad::Entidad(Estado* pEstado): pEstado(pEstado){


}
Entidad::Entidad(Estado* pEstado, std::string prefab) : pEstado(pEstado) {


	std::string path = "../Media/prefabs/";
	path += prefab + ".txt";
	std::ifstream fe(path);
	std::string type;
	fe >> type;
	while (type != "---") {
		if (type == "Grafico") {
			std::string mesh; fe >> mesh;
			añadeComponenteGrafico(mesh);
		}
		else if (type == "Logico") {
			std::string component; fe >> component;
			añadeComponenteLogico(component);
		}
		else if (type == "Animation") {
			std::string mesh; fe >> mesh;
			añadeAnimacion(mesh, fe);
		}
		else if (type == "Camara") {
			componentes.insert(std::make_pair("Camara", new Camara(this)));
		}
		fe >> type;
	}

	fe.close();
	
}

bool Entidad::añadeAnimacion(std::string mesh, std::ifstream & fe) {
	if (fe.is_open()) {
		auto s = componentes.find("Grafico");
		if (s != componentes.end())
		{
			std::cout << "No puede tener componente grafico y animacion\n";
		}
		Animation *animation = new Animation(this, mesh);
		int numAnims; fe >> numAnims;
		for (int i = 0; i < numAnims; i++) {
			std::string name; fe >> name;
			animation->addAnimationState(name);
		}
		componentes.insert(std::make_pair("Anim", animation));
		return true;
	}
	else return false;
	
}
bool Entidad::añadeAnimacion(std::string name, bool enabled, bool loop) {

	auto s = componentes.find("Grafico");
	if (s != componentes.end())
	{
		componentes.at("Grafico")->destroy();
		componentes.erase(s);
	}
	dynamic_cast<Animation*>(componentes.at("Anim"))->addAnimationState(name,enabled, loop);
	return true;
}

bool Entidad::añadeComponenteGrafico(std::string mesh) {
	componentes.insert(std::make_pair("Grafico", new GComponent(this, mesh)));
	return true;
}
bool Entidad::añadeComponenteLogico(std::string component) {
	if (component == "Transform") {
		componentes.insert(std::make_pair("Transform", new Transform(this, 0, 0, 0)));
	}

	return true;
}
void Entidad::Update(float deltaTime,  Mensaje const & msj){
	Mensaje msg = msj;
	if (activo){

		if (msg.getReceptor() == this || msg.getReceptor() == nullptr) {
			for (auto i = componentes.begin(); i != componentes.end(); i++)
			{
				i->second->Update(deltaTime, msg);
			}
		}
	}
}
void Entidad::Awake(){ activo = true; }
void Entidad::Sleep(){ activo = false; }
