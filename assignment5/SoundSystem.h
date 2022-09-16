#pragma once

#include <map>

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <EventListener.h>

using namespace std;

class SoundSystem : public EventListener {
public:
	
	SoundSystem();
	~SoundSystem();

	bool init();
	bool cleanup();

	void addAudioSample(string key, ALLEGRO_SAMPLE* sample);
	void addAudioSample(string key, string sampleFilePath);

	void playAudioSample(string key, int loop);

	void raiseVolume(int increase);
	void lowerVolume(int decrease);
	
	void handleEvent(const Event& theEvent);

private:
	ALLEGRO_VOICE* mpVoice;
	ALLEGRO_MIXER* mpMixer;
	
	map<string, ALLEGRO_SAMPLE*> mAudioSamples;
	map<string, ALLEGRO_SAMPLE_INSTANCE*> mAudioSampleInstances;

	float volume = 1;

};