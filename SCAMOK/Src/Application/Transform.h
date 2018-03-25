#pragma once
#include "Componente.h"
#include "Estado.h"

class Transform : public Componente
{
public:
	Transform(Entidad* pEnt, int x, int y, int z);
	~Transform();

	virtual void Update(float deltaTime, Mensaje const & mensaje);
	void getTransform(int& X, int& Y, int& Z) { X = x; Y = y; Z = z; };

private:
	int x, y, z;
	Entidad * camera;
};

