#include <string>
#include "Estado.h"
#pragma once
enum Tipo{ Render, Fisica, Logica, Input, Animation };

class Mensaje{
public:
	Mensaje(Tipo tip, std::string msg, int prio = 0) { 
		tipo = tip; mensaje = msg; 

		if (prio == 0){
			switch (tipo)
			{
			case Render:
				prio = 1;
				break;
			case Animation:
				prio = 1;
				break;
			case Fisica:
				prio = 2;
				break;
			case Input:
				prio = 3;
				break;
			}
		}
		prioridad = prio; 
		emisor = nullptr;
		receptor = nullptr;
	}
	void setMsgInfo(Entidad* em, Entidad* re = nullptr) {
		emisor = em;
		receptor = re;
	}
	int getPriority() { return prioridad; }
	Entidad* getEmisor() { return emisor; }
	Entidad* getReceptor() { return receptor; };
	std::string getMsg() { return mensaje; }
	int getTipo() { return tipo; }

private:
	std::string mensaje;
	Entidad * emisor;
	Entidad * receptor;
	int prioridad;
	Tipo tipo;
};