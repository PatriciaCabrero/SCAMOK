#pragma once 
#include "Transform.h"
#include <iostream>

Transform::Transform(Entidad * pEnt, int x, int y, int z) : Componente(pEnt)
{
	this->x = x; this->y = y; this->z = z;
}
Transform::~Transform()
{
}
void Transform::Update(float deltaTime, Mensaje const & msj) {
	Componente::Update(deltaTime, msj);
	Mensaje msg = msj;
	if (msg.getTipo() == Tipo::Input) {
		
		int pos = msg.getMsg().find("/");
		std::string sx = msg.getMsg().substr(0,pos);
		std::string sy = msg.getMsg().substr(pos+1);

		float x = std::stof(sx);
		float y = std::stof(sy);

		this->x += x; this->z += y;

		Mensaje * m = new Mensaje(Tipo::Render, msg.getMsg());
		//Si no se especifica receptor se considera broadcast
		m->setMsgInfo(pEntidad, pEntidad);
		pEntidad->getPEstado()->addMsg(*m);
	}

}