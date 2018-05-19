#include "IABola.h"  
#include <iostream>
#include "FComponent.h"
#include "OgreParticleSystem.h"

IABola::IABola(Entidad * pEnt, std::string target, int x, int y, int z) : Componente(pEnt)
{
	this->x = x; this->y = y; this->z = z;
	this->target = pEntidad->getPEstado()->getScnManager()->getSceneNode(target);
	state = Wander;
	wState = Right;
	cont = 0;
	contDivide = 0;
	numDiv = 0;
	pS = pEntidad->getPEstado()->getScnManager()->createParticleSystem(pEntidad->getNombreNodo() + "PFX", "Division");
	Ogre::SceneNode* node = pEntidad->getPEstado()->getScnManager()->getSceneNode(pEntidad->getNombreNodo());
	node->attachObject(pS);
} 
IABola::~IABola() { 
} 
void IABola::Update(float deltaTime, Mensaje const & msj) {
	Componente::Update(deltaTime, msj);
	Mensaje msg = msj;
	//Play/jddjdj/x/y/z
	if (msg.getTipo() == Tipo::IA) {

		if (msg.getSubTipo() == SubTipo::Nulo) {
			
			if (state == States::Wander) {
				// wander();
				contDivide++;
				if (contDivide == 800) {
					contDivide = 0;
					state = States::Stay;
				}
			}
			else if (state == States::Stay) {
				contDivide++;
				pS->setEmitting(true);
				if (contDivide == 200) {
					contDivide = 0;
					divide();
					state = States::Wander;
				}
			}
		}
		else {
			//if(state==Hunt)	divide();
			//else state = Hunt;
			divide();
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

void IABola::divide()
{
		Ogre::SceneNode* node = pEntidad->getPEstado()->getScnManager()->getSceneNode(pEntidad->getNombreNodo());
	if (node->getScale().x > 0.218) {
		node->scale(0.6, 0.6, 0.6);

		Entidad* aux1 = new Entidad(pEntidad->getPEstado());
		string auxBola = pEntidad->getPEstado()->getFactory()->create("stone");
		aux1->setNombreNodo(auxBola);

		aux1->añadeComponenteGrafico("stone", auxBola);
		aux1->añadeComponenteLogico("IABola");
		aux1->añadeComponenteFisico(0, 0, 0, false, tipoFisica::Kinematico, 1);
		pEntidad->getPEstado()->addEntidad(auxBola, aux1);
		

		btRigidBody *b = static_cast<FComponent*>(pEntidad->getComponente("Fisico"))->getRigidBody();
		std::string pos = std::to_string(b->getWorldTransform().getOrigin().x()) + "/0/" + std::to_string(b->getWorldTransform().getOrigin().z());
		Mensaje ms(Tipo::Fisica, pos, SubTipo::Reposicionar);
		ms.setMsgInfo(aux1, aux1);
		pEntidad->getPEstado()->addMsg(ms, true);

		pEntidad->getPEstado()->getScnManager()->getSceneNode(auxBola)->scale(node->getScale().x, node->getScale().x, node->getScale().x);
		numDiv++;
	}
}
