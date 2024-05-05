#pragma once

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <memory>
#include <tuple>
#include <unordered_map>

#include <SFML/Audio.hpp>

#include "MusicState.hpp"

class Audio {
	public:
	Audio(const Audio&) = delete;
	
	static Audio& get();

	bool playMusic(MusicState state);

	private:
	static Audio m_audio;

	std::unordered_map<MusicState, std::tuple<std::unique_ptr<sf::Music>, bool>> m_audioPlayers;
	MusicState m_recentlyPlayedMusic = MusicState::None;

	Audio();
	~Audio();
};

#endif // !AUDIO_HPP
