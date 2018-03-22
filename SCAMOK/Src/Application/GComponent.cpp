
#include "GComponent.h"
using namespace Ogre;
GComponent::GComponent(Entidad* pEnt, std::string name) : Componente (pEnt){
	
	std::string mesh = name + ".mesh";
	ent = pEnt->getPEstado()->getScnManager()->createEntity(mesh);
	groupNode = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode("GNode"+name);
	node = groupNode->createChildSceneNode(name);
	node->attachObject(ent);

}
void GComponent::Update(float deltaTime,  Mensaje const & msj) { 
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);
	if (msg.getTipo() == Tipo::Render ){
		
		if (msg.getSubTipo() == SubTipo::Mover) {
			int pos = msg.getMsg().find("/");
			std::string xS = msg.getMsg().substr(0, pos);
			std::string subcad = msg.getMsg().substr(pos + 1);
			pos = subcad.find("/");
			std::string yS = subcad.substr(0, pos);
			std::string zS = subcad.substr(pos + 1);

			translate(std::stof(xS), std::stof(yS), std::stof(zS));
			node->lookAt(Ogre::Vector3(groupNode->getPosition().x+std::stof(zS), groupNode->getPosition().y, groupNode->getPosition().z-std::stof(xS)), Node::Node::TS_WORLD, Vector3::UNIT_X);
			
		}
		if (msg.getSubTipo() == SubTipo::Rotar) {
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
void GComponent::destroy() {
	node->removeAndDestroyAllChildren();
	pEntidad->getPEstado()->getScnManager()->getRootSceneNode()->detachObject(ent);
	delete node;
	delete ent;
}
GComponent::~GComponent() {
	
}
void GComponent::rota(float angle, Vector3 eje){
	node->rotate(Quaternion(Degree(angle), eje));
}
void GComponent::translate(float x, float y, float z) {
	groupNode->translate(x, y, z);
}
void GComponent::scale(float x, float y, float z) {
	node->scale(x, y, z);
}