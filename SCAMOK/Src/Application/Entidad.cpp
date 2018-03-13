#pragma once
#include "Entidad.h"
#include "GComponent.h"

Entidad::Entidad(Estado* pEstado): pEstado(pEstado){
	// Borrar esto es para comprobar que añade el ogro con esta configuracion del proyecto
	componentes.insert(std::make_pair("Grafico", new GComponent(this)));

}
void Entidad::Update(float deltaTime, Mensaje& msg){
	if (activo){
		for (auto i = componentes.begin(); i != componentes.end(); i++)
		{
			i->second->Update(deltaTime, msg);
		}
	}
}
void Entidad::Awake(){ activo = true; }
void Entidad::Sleep(){ activo = false; }