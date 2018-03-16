#pragma once 
#include "Transform.h"

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
		if (msg.getMsg() == "der") x++;
		else if (msg.getMsg() == "izq") x--;
		else if (msg.getMsg() == "arr") z--;
		else if (msg.getMsg() == "aba")	z++;
		else return;

		Mensaje * m = new Mensaje(Tipo::Render, msg.getMsg());
		//Si no se especifica receptor se considera broadcast
		m->setMsgInfo(pEntidad, pEntidad);
		pEntidad->getPEstado()->addMsg(*m);
	}

}