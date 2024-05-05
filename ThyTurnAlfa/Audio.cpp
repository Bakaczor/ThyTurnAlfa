#include "Audio.hpp"
#include <exception>
#include <iostream>
#include "Error.hpp"

Audio Audio::m_audio = Audio();

Audio& Audio::get() {
	return m_audio;
}

bool Audio::playMusic(MusicState state)
{
	if (state == m_recentlyPlayedMusic || state == MusicState::None)
		return true;
	try {
		// TODO: remove the line below when whole soundtrack is done
		state = MusicState::Menu;

		std::tuple<std::unique_ptr<sf::Music>, bool>& audio_tuple = m_audioPlayers[state];
		// checking whether the music was correctly opened
		if (!std::get<1>(audio_tuple)) return false;

		std::unique_ptr<sf::Music>& new_audio_player = std::get<0>(audio_tuple);

		if (m_recentlyPlayedMusic != MusicState::None) {
			std::unique_ptr<sf::Music>& recent_player = std::get<0>(m_audioPlayers[m_recentlyPlayedMusic]);
			if (recent_player->getStatus() == sf::Music::Playing) {
				recent_player->pause();
			}
		}

		new_audio_player->play();
		m_recentlyPlayedMusic = state;

		return true;
	} catch(const std::exception& e) {
		printError(e);
		return false;
	}

}

Audio::Audio() {
	try {
		m_audioPlayers.emplace(MusicState::Menu, std::make_tuple(std::make_unique<sf::Music>(), true));
		std::unique_ptr<sf::Music>& menu_audio_ptr = std::get<0>(m_audioPlayers[MusicState::Menu]);
		std::get<1>(m_audioPlayers[MusicState::Menu]) = menu_audio_ptr->openFromFile("audio/menu.wav");
		menu_audio_ptr->setLoop(true);
	} catch (const std::exception & e) {
		printError(e);
	}
}

Audio::~Audio() {
	for (auto& map_node : m_audioPlayers) {
		std::unique_ptr<sf::Music>& audio_player = std::get<0>(std::get<1>(map_node));
		if (audio_player->getStatus() == sf::Music::Playing) {
			audio_player->stop();
		}
	}
}
