#include "IABola.h"  
#include <iostream>
#include "FComponent.h"
#include "OgreParticleSystem.h"
#include "OgreParticleEmitter.h"

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
				wander();
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
			else if (state == States::Hunt) {
				hunt();
				contDivide++;
				if (contDivide == 800) {
					contDivide = 0;
					state = States::Stay;
				}
			}
			else if (state == Die) {
				die();
			}
		}
		else {
			state = Hunt;
			//pS->clear();
			//pS = pEntidad->getPEstado()->getScnManager()->createParticleSystem(pEntidad->getNombreNodo() + "PFX", "Division");
			//if(state==Hunt)	divide();
			//else state = Hunt;
			////divide();
		}
	}
}

void IABola::wander()
{
	if (cont > 50) {
		cont = 0;
		int r = std::rand() % 8;
		if (r > 6) {
			state = States::Hunt;
			cont = 0;
			return;
		}
		std::cout << "\n" << r << "\n";
		wState = (WanderState)r;
	}
	cont++;
	std::string s ="0/0/0";
	switch (wState)
	{
	case Right:	s = "-0.5/0/0";
		
		break;
	case Left:s = "0.5/0/0";
		break;
	case Up:s = "0/0/0.5";
		break;
	case Down:s = "0/0/-0.5";
		break;
	case RD: s = "-0.5/0/-0.5";
		break;
	case RU: s = "-0.5/0/0.5";
		break;
	case LD: s = "0.5/0/-0.5";
		break;
	case LU: s = "0.5/0/0.5";
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
	
	btVector3 vecSinbad = static_cast<FComponent*>(pEntidad->getPEstado()->getEntidad("sinbad")->getComponente("Fisico"))->getRigidBody()->getWorldTransform().getOrigin();
	btVector3 vecBola = static_cast<FComponent*>(pEntidad->getComponente("Fisico"))->getRigidBody()->getWorldTransform().getOrigin();

	float X, Y, Z;
	if (vecSinbad.x() - vecBola.x() > 0) X = 0.5f;
	else if(vecSinbad.x() - vecBola.x() < 0) X = -0.5f;
	else X = 0;
	if (vecSinbad.z() - vecBola.z() > 0) Z = 0.5f;
	else if (vecSinbad.z() - vecBola.z() < 0) Z = -0.5f;
	else Z = 0;

	std::cout << "\nºººººº\nHUNT" << vecSinbad.z() - vecBola.z();

	std::string s = std::to_string(X) + "/0/" + std::to_string(Z);
	if (abs(vecSinbad.x() - vecBola.x()) < 6.0f && abs(vecSinbad.z() - vecBola.z()) < 6.0f) {
		cont++;
		die();
	}
	/*Mensaje m(Tipo::Render, s, SubTipo::Orientar); //Look at de la camara
	m.setMsgInfo(pEntidad, pEntidad);
	pEntidad->getPEstado()->addMsg(m);*/
	Ogre::SceneNode* node = pEntidad->getPEstado()->getScnManager()->getSceneNode(pEntidad->getNombreNodo());
	Ogre::Vector3 aux = Ogre::Vector3(vecSinbad.x(), 0, vecSinbad.z());
	node->setOrientation(pEntidad->getPEstado()->getScnManager()->getSceneNode("sinbad")->getOrientation());
	node->lookAt(aux,Ogre::Node::TS_LOCAL, Ogre::Vector3::UNIT_Z);
	Mensaje msgI(Tipo::Fisica, s, SubTipo::Mover);
	msgI.setMsgInfo(pEntidad, pEntidad);
	pEntidad->getPEstado()->addMsg(msgI);

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

void IABola::die()
{
		Ogre::ParticleEmitter * em = pS->getEmitter(0);
		em->setEnabled(false);
		em->setEnabled(true);
	
	 if(cont > 200)
		pEntidad->getPEstado()->destroy(pEntidad->getNombreNodo());
	cont++;
}
