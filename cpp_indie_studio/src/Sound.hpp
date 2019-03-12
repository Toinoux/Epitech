//
// EPITECH PROJECT, 2018
// SOUND_HPP_
// File description:
// header
//

#pragma once
# include <iostream>
# include <string>
# include <SFML/Audio.hpp>

namespace bbm {

	extern int g_globalVolume;
class Sound {

public:
	Sound(const std::string fileToOpen, unsigned int typeSound);
	~Sound() = default;
	enum {
		MUSIC,
		SOUND
	};
	void play();
	void pause();
	void setLoop(bool isLoop);
	void stop();
	void reset();
	void setVolume(float volume);
	float getVolume() const;
	void setPlayingOffset(sf::Time timeOffset);

private:
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	sf::Music _music;
	unsigned int _typeSound;
};
}
