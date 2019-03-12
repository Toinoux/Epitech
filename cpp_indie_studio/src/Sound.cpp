//
// EPITECH PROJECT, 2018
// indie
// File description:
// sound manage
//

#include "Sound.hpp"
#include <exception>

bbm::Sound::Sound(const std::string fileToOpen, unsigned int typeSound) :
	_typeSound(typeSound)
{
	if (_typeSound == SOUND) {
		if (!_buffer.loadFromFile(fileToOpen))
			throw std::runtime_error("Unable to load buffer from sound file");
		_sound.setVolume(bbm::g_globalVolume);
		_sound.setBuffer(_buffer);
	} else {
		if (!_music.openFromFile(fileToOpen))
			throw std::runtime_error("Unable to open buffer from music file");
		_music.setVolume(bbm::g_globalVolume);
	}
}

void bbm::Sound::play()
{
	std::cout << "VOLUME =" << g_globalVolume <<std::endl;
	if (_typeSound == MUSIC) {
		_music.setVolume(bbm::g_globalVolume);
		_music.play();
	}
	else {
		_sound.setVolume(bbm::g_globalVolume);
		_sound.play();
	}
}

void bbm::Sound::pause()
{
	if (_typeSound == MUSIC)
		_music.pause();
	else
		_sound.pause();
}

void bbm::Sound::setLoop(bool isLoop)
{
	if (_typeSound == MUSIC)
		_music.setLoop(isLoop);
	else
		_sound.setLoop(isLoop);
}

void bbm::Sound::stop()
{
	if (_typeSound == MUSIC)
		_music.stop();
	else
		_sound.stop();
}

void bbm::Sound::reset()
{
	this->stop();
	this->play();
}

void bbm::Sound::setVolume(float volume)
{
	if (_typeSound == MUSIC)
		_music.setVolume(volume);
	else
		_sound.setVolume(volume);
}

float bbm::Sound::getVolume() const
{
	return (this->getVolume());
}

void bbm::Sound::setPlayingOffset(sf::Time timeOffset)
{
	if (_typeSound == MUSIC)
		_music.setPlayingOffset(timeOffset);
	else
		_sound.setPlayingOffset(timeOffset);
}
