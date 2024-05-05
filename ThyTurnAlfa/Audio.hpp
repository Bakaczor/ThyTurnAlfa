#pragma once

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <map>
#include <tuple>

#include <SFML/Audio.hpp>

#include "MusicState.hpp"

class Audio {
public:
	Audio(const Audio&) = delete;
	
	static Audio& get();

	bool playMusic(MusicState state);

private:
	Audio();
	~Audio();

	static Audio m_audio;

	std::map<MusicState, std::tuple<sf::Music, bool>> m_audioPlayers;
	MusicState m_recentlyPlayedMusic = MusicState::None;
};

#endif // !AUDIO_HPP
