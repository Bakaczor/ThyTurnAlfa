#include "Audio.hpp"
#include <exception>

Audio Audio::m_audio = Audio();

Audio& Audio::get() {
	return m_audio;
}

bool Audio::playMusic(MusicState state)
{
	if (state == MusicState::None)
		return true;
	try {
		// TODO: remove the line below when whole soundtrack is done
		state = MusicState::Menu;

		std::tuple<sf::Music, bool>& audio_tuple = m_audioPlayers[state];
		// checking whether the music was correctly opened
		if (!std::get<1>(audio_tuple)) return false;

		sf::Music& new_audio_player = std::get<0>(audio_tuple);

		if (m_recentlyPlayedMusic != MusicState::None) {
			sf::Music& recent_player = std::get<0>(m_audioPlayers[m_recentlyPlayedMusic]);
			if (recent_player.getStatus() == sf::Music::Playing) {
				recent_player.pause();
			}
		}

		new_audio_player.play();
		m_recentlyPlayedMusic = state;

		return true;
	} catch(std::exception& e) {
		return false;
	}

}

Audio::Audio() {
	std::tuple<sf::Music, bool> menu_tuple;
	std::get<1>(menu_tuple) = std::get<0>(menu_tuple).openFromFile("audio/menu.wav");

	m_audioPlayers.insert({ MusicState::Menu, std::move(menu_tuple)});
}

Audio::~Audio() {
	for (auto& map_node : m_audioPlayers) {
		sf::Music& audio_player = std::get<0>(std::get<1>(map_node));
		if (audio_player.getStatus() == sf::Music::Playing) {
			audio_player.stop();
		}
	}
}
