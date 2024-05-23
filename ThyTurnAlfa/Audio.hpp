#pragma once

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <memory>
#include <tuple>
#include <unordered_map>

#include <SFML/Audio.hpp>

#include "Const.hpp"
#include "MusicState.hpp"

class Audio {
	public:
	int volume = Const::Audio::MUSIC_DEAFULT_VOLUME;

	Audio(const Audio&) = delete;
	
	static Audio& get();

	bool playMusic(MusicState state);	
	void pauseMusic();
	void resumeMusic();
	void updateVolume();

	private:
	static Audio m_audio;
	
	bool m_isPlaying = false;

	std::unordered_map<MusicState, std::tuple<std::unique_ptr<sf::Music>, bool>> m_audioPlayers;
	MusicState m_recentlyPlayedMusic = MusicState::None;

	Audio();
	~Audio();
};

#endif // !AUDIO_HPP
