#include "IABola.h"  
#include <iostream>
 

IABola::IABola(Entidad * pEnt, std::string target, int x, int y, int z) : Componente(pEnt)
{
	this->x = x; this->y = y; this->z = z;
	this->target = pEntidad->getPEstado()->getScnManager()->getSceneNode(target);
	state = Wander;
	wState = Right;
	cont = 0;
} 
IABola::~IABola() { 
} 
void IABola::Update(float deltaTime, Mensaje const & msj) {
	Componente::Update(deltaTime, msj);
	Mensaje msg = msj;
	//Play/jddjdj/x/y/z
	if (msg.getTipo() == Tipo::IA) {

		if (msg.getSubTipo() == SubTipo::Nulo) {
			
			if (state == States::Wander) wander();
;
		}

	}
}

void IABola::wander()
{
	if (cont > 100) {
		cont = 0;
		int r = std::rand() % 7;
		std::cout << "\n" << r << "\n";
		wState = (WanderState)r;
	}
	cont++;
	std::string s ="0/0/0";
	switch (wState)
	{
	case Right:	s = "0.5/0/0";
		
		break;
	case Left:s = "-0.5/0/0";
		break;
	case Up:s = "0/0/0.5";
		break;
	case Down:s = "0/0/-0.5";
		break;
	case RD: s = "0.5/0/-0.5";
		break;
	case RU: s = "0.5/0/0.5";
		break;
	case LD: s = "-0.5/0/-0.5";
		break;
	case LU: s = "-0.5/0/0.5";
		break;
	default:
		break;
	}
	Mensaje msgI(Tipo::Fisica, s, SubTipo::Mover);
	msgI.setMsgInfo(pEntidad, pEntidad);
	pEntidad->getPEstado()->addMsg(msgI);
	/*Mensaje msg;
	Mensaje  m(Tipo::Fisica, msg.getMsg(), SubTipo::Mover);
	//Si no se especifica receptor se considera broadcast
	m.setMsgInfo(pEntidad, pEntidad);
	pEntidad->getPEstado()->addMsg(m); +*/
	
}

void IABola::stay()
{
}

void IABola::hunt()
{
}
