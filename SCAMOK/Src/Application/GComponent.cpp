
#include "GComponent.h"
using namespace Ogre;
GComponent::GComponent(Entidad* pEnt, std::string name) : Componente (pEnt){
	
	std::string mesh = name + ".mesh";
	ent = pEnt->getPEstado()->getScnManager()->createEntity(mesh);
	node = pEnt->getPEstado()->getScnManager()->getRootSceneNode()->createChildSceneNode(name);
	node->attachObject(ent);
	
}
void GComponent::Update(float deltaTime,  Mensaje const & msj) { 
	Mensaje msg = msj;
	Componente::Update(deltaTime, msj);
	if (msg.getTipo() == Tipo::Render ){
		
		if (msg.getSubTipo() == SubTipo::Mover) {
			int pos = msg.getMsg().find("/");
			std::string sz = msg.getMsg().substr(0, pos);
			std::string sx = msg.getMsg().substr(pos + 1);

			float x = -1 * std::stof(sx);
			float z = -1 * std::stof(sz);
			
			node->translate(x,0,z);
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
	node->translate(x, y, z);
}
void GComponent::scale(float x, float y, float z) {
	node->scale(x, y, z);
}