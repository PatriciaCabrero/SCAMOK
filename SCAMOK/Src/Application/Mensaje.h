#include <string>
#include "Estado.h"
#pragma once
enum Tipo{ Render, Fisica, Logica };

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
			case Fisica:
				prio = 2;
				break;
			case Logica:
				prio = 3;
				break;
			}
		}
		prioridad = prio; 
	}

	int getPriority() { return prioridad; }
	std::string getMsg() { return mensaje; }
	int getTipo() { return tipo; }

private:
	std::string mensaje;
	int prioridad;
	Tipo tipo;
};