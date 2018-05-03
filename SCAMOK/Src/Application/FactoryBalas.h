#pragma once

#include "Factory.h"

class FactoryBalas : public Factory {
public:
	FactoryBalas() : Factory() {};
	string create(string name) {
		cont++;
		return (name + to_string(cont));
	}
private:
	int cont = 0;
};