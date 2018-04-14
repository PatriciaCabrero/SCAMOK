
#include "GComponent.h"
using namespace Ogre;
GComponent::GComponent(Entidad* pEnt, std::string name) : Componente (pEnt){
	
	std::string mesh = name + ".mesh";
	ent = pEnt->getPEstado()->getScnManager()->createEntity(mesh);
	groupNode = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode("GNode"+name);
	node = groupNode->createChildSceneNode(name);
	node->attachObject(ent);
	firstMsg = false;
	

}
void GComponent::Update(float deltaTime,  Mensaje const & msj) { 
	if (!firstMsg) {
		Mensaje msg = msj;
		Componente::Update(deltaTime, msj);
		if (nodeCh == nullptr) {
			nodeCh = node->createChildSceneNode("nodeCh");
			Vector3 posAux = groupNode->getChild("NodoCamera")->getPosition();
			posAux.y = posAux.y*-1;
			nodeCh->setPosition(-posAux);
		}
		if (msg.getTipo() == Tipo::Render) {

			if (msg.getSubTipo() == SubTipo::Mover) {
				int pos = msg.getMsg().find("/");
				std::string xS = msg.getMsg().substr(0, pos);
				std::string subcad = msg.getMsg().substr(pos + 1);
				pos = subcad.find("/");
				std::string yS = subcad.substr(0, pos);
				std::string zS = subcad.substr(pos + 1);

				translate(std::stof(xS), std::stof(yS), std::stof(zS));
				Vector3 aux = Ogre::Vector3(groupNode->getPosition().x + std::stof(xS) * 100000, groupNode->getPosition().y, groupNode->getPosition().z + std::stof(zS) * 100000);
				node->setOrientation(groupNode->getChild("NodoCamera")->getOrientation());
				//if (std::stof(xS) != 0 && std::stof(zS) != 0)
					//node->rotate(Vector3(0, groupNode->getPosition().y, 0), Radian(sin(groupNode->getPosition().x / groupNode->getPosition().z)), Node::TS_LOCAL);

				node->lookAt(aux, Node::TS_LOCAL, Vector3::UNIT_Z);
				//node->rotate(Quaternion(Radian(90),Vector3(0,1,0)), Node::TS_LOCAL);





			}
			else if (msg.getSubTipo() == SubTipo::Rotar) {
				//angle/int-> 0 = x, 1 = y, 2 = z
				int pos = msg.getMsg().find("/");
				std::string anguloS = msg.getMsg().substr(0, pos);
				std::string ejeS = msg.getMsg().substr(pos + 1);

				int eje = std::stoi(ejeS);
				float angulo = std::stof(anguloS);

				switch (eje)
				{
				case 0: rota(angulo, Vector3::UNIT_X);
					break;
				case 1: rota(angulo, Vector3::UNIT_Y);
					break;
				case 2: rota(angulo, Vector3::UNIT_Z);
					break;
				default:
					break;
				}
			}
		}
	}
	else { 
		firstMsg = true; 
	}
}
void GComponent::destroy() {
	node->removeAndDestroyAllChildren();
	pEntidad->getPEstado()->getScnManager()->getRootSceneNode()->detachObject(ent);
	delete node;
	delete ent;
}
GComponent::~GComponent() {
	
}
void GComponent::rota(float angle, Vector3 eje){
	//groupNode->rotate(Quaternion(Degree(-angle*2), eje));
	//node->setOrientation(groupNode->getChild("NodoCamera")->getOrientation());
	
}
void GComponent::translate(float x, float y, float z) {
	
	groupNode->translate(groupNode->getChild("NodoCamera")->getLocalAxes(), Vector3(x, y, z));
}
void GComponent::scale(float x, float y, float z) {
	node->scale(x, y, z);
}