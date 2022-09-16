#include "SoundSystem.h"

SoundSystem::SoundSystem() {
	init();
}

SoundSystem::~SoundSystem() {
	cleanup();
}

bool SoundSystem::init() {
	if (!al_install_audio()) {
		cout << "error installing audio";
		return false;
	}
	if (!al_init_acodec_addon()) {
		cout << "error initting acodec";
		return false;
	}
	if (!al_reserve_samples(10)) {
		cout << "error reserving sample";
	}

	const string ASSET_PATH = "..\\assets\\";

	addAudioSample("kaching", ASSET_PATH + "kaching.ogg");
	addAudioSample("click", ASSET_PATH + "click.ogg");
	addAudioSample("ant", ASSET_PATH + "ants.ogg");

	return true;
}

bool SoundSystem::cleanup() {
	map<string, ALLEGRO_SAMPLE_INSTANCE*>::iterator it;
	for (it = mAudioSampleInstances.begin(); it != mAudioSampleInstances.end(); ++it) {
		al_destroy_sample_instance(it->second);
	}
	mAudioSampleInstances.clear();

	al_uninstall_audio();

	return true;
}

void SoundSystem::addAudioSample(string key, ALLEGRO_SAMPLE* sample) {
	mAudioSamples[key] = sample;
	mAudioSampleInstances[key] = al_create_sample_instance(mAudioSamples[key]);
}

void SoundSystem::addAudioSample(string key, string sampleFilePath) {
	mAudioSamples[key] = al_load_sample((sampleFilePath).c_str());
	if (mAudioSamples[key]) {
		cout << "adding sample success" << endl;
	}
	else {
		cout << "error loading sample" << endl;
	}
}

void SoundSystem::playAudioSample(string key, int loop) {
	switch (loop) {
	case 0:
		if (al_play_sample(mAudioSamples[key], volume, 0, 1, ALLEGRO_PLAYMODE_ONCE, nullptr)) {
			cout << "playing sound once" << endl;
		}
		else {
			cout << "error playing sound once" << endl;
		}
		break;
	case 1:
		if (al_play_sample(mAudioSamples[key], volume, 0, 1, ALLEGRO_PLAYMODE_LOOP, nullptr)) {
			cout << "playing sound on loop" << endl;
		}
		else {
			cout << "error playing sound on loop" << endl;
		}
		break;
	}
}

void SoundSystem::raiseVolume(int increase) {
	volume += increase;
}

void SoundSystem::lowerVolume(int decrease) {
	volume -= decrease;
}

void SoundSystem::handleEvent(const Event& theEvent) {

}