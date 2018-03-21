#pragma once 
#include "Componente.h"
#include <fmod.hpp>
#include <vector>
class SoundManager : public Componente { 
public: 
	SoundManager(Entidad* pEnt, FMOD::System* sys);
	~SoundManager(); 

	//Audio-----------------------------------------

	void reproduceFx(std::string fx, float x, float y, float z, float wet);
	void reproduceAmbM(std::string amb, float wet, bool fade);
	void paraAmb(int ch, bool fade);

private:
	// Fmod settings
	FMOD::ChannelGroup* reverbGroup;
	FMOD::ChannelGroup* mainGroup;
	FMOD::DSP* reverbUnit;
	FMOD::DSP* channelHead;
	int cMusic;
	int cAmb;
	FMOD::System* system;

	std::vector<FMOD::DSPConnection*> reverbConnectionfx;
	std::vector<FMOD::Channel*> cFx;
	std::vector<FMOD::Channel*> cMA;
	std::vector<FMOD::DSPConnection*> reverbConnectionAmbM;
	std::map<std::string, FMOD::Sound*> vfx;
	std::map<std::string, FMOD::Sound*> vmusic;

	void cargaAudio(std::string irPath);
	void cargarAssetsAudio();
}; 
