#pragma once 
#include "Componente.h"
#include "Estado.h"
enum States { Hunt, Wander, Stay };
enum WanderState { Right, Left, Up, Down, RU,RD, LU,LD };
class IABola: public Componente
{
public: 
	IABola(Entidad* pEnt, std::string target, int x, int y, int z);
	~IABola(); 

	virtual void Update(float deltaTime, Mensaje const & mensaje);
	void wander();
	void stay();
	void hunt();
private:
	int x, y, z;
	Ogre::SceneNode *target;
	States state;
	WanderState wState;
	int cont;
}; 
