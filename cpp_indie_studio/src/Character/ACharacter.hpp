/*
** EPITECH PROJECT, 2018
** ACharacter
** File description:
** Interface Character
*/

#pragma once
#include <string>
#include <cstddef>
#include <utility>

#include "IEntity.hpp"
#include "Timer.hpp"

namespace bbm {

	constexpr float RADIUS_PLAYER = 0.17f;
	constexpr float SPEED_PLAYER = 0.1f;
	enum Direction {
		NORTH = 1,
		SOUTH,
		EAST,
		WEST
	};

	class ACharacter : public IEntity {
	public:
		ACharacter();
		ACharacter(const ACharacter &character);
		ACharacter(size_t id);
		virtual ~ACharacter() = default;
		ACharacter &operator=(ACharacter &character) = default;

	public:
		inline void operator=(const std::string &nick);
		void hurt();

		inline void setPos(float x, float y);
		inline std::pair<float, float> getPos() const;
		inline const std::string &getNick() const;
		inline void setNick(const std::string &nick);
		inline size_t getID() const;
		inline void setID(const size_t id);
		inline bool canKick() const;
		inline void setKick(const bool kick);
		inline bool canThrow() const;
		inline void setThrow(const bool throwBomb);
		inline int getBombAmount() const;
		inline void setBombAmount(const int bombAmount);
		inline int getBombRange() const;
		inline void setBombRange(const int bombRange);
		inline int getLives() const;
		inline void setLives(const int lives);
		inline void setMove(bool move);
		inline bool getMove() const;
		inline void setCardinal(Direction dir);
		inline Direction getCardinal() const;
		Timer &getTimer();
		float getSpeed() const { return _speed; }
		void addSpeed(float speed) { _speed += speed; }

	protected:
		float _x;
		float _y;
		std::string _nick;
		size_t _id;
		bool _canKick;
		bool _canThrow;
		int _bombAmount;
		int _bombRange;
		int _lives;
		Direction _card = NORTH;
		bool _isMoving = false;
		Timer _clock;
		float _speed = SPEED_PLAYER;
	};
	std::ostream &operator<<(std::ostream &io, ACharacter &aChar);
	std::string &operator<<(std::string &output, ACharacter &aChar);
	ACharacter &operator>>(const std::string &input, ACharacter &aChar);
}

void bbm::ACharacter::operator=(const std::string &nick)
{
        setNick(nick);
}

void bbm::ACharacter::setPos(float x, float y)
{
	_x = x;
	_y = y;
}

std::pair<float, float> bbm::ACharacter::getPos() const
{
	return std::make_pair(_x, _y);
}

const std::string &bbm::ACharacter::getNick() const
{
        return _nick;
}

void bbm::ACharacter::setNick(const std::string &nick)
{
        _nick = nick;
}

size_t bbm::ACharacter::getID() const
{
	return _id;
}

void bbm::ACharacter::setID(const size_t id)
{
        _id = id;
}

bool bbm::ACharacter::canKick() const
{
	return _canKick;
}

void bbm::ACharacter::setKick(bool kick)
{
	_canKick = kick;
}

bool bbm::ACharacter::canThrow() const
{
	return _canThrow;
}

void bbm::ACharacter::setThrow(bool throwBomb)
{
        _canThrow = throwBomb;
}

int bbm::ACharacter::getBombAmount() const
{
	return _bombAmount;
}

void bbm::ACharacter::setBombAmount(const int bombAmount)
{
        _bombAmount = bombAmount;
}

int bbm::ACharacter::getBombRange() const
{
	return _bombRange;
}

void bbm::ACharacter::setBombRange(const int bombRange)
{
        _bombRange = bombRange;
}

int bbm::ACharacter::getLives() const
{
	return _lives;
}

void bbm::ACharacter::setLives(const int lives)
{
	_lives = lives;
}

void bbm::ACharacter::setMove(bool move)
{
	_isMoving = move;
}

bool bbm::ACharacter::getMove() const
{
	return _isMoving;
}

void bbm::ACharacter::setCardinal(Direction dir)
{
	_card = dir;
}

bbm::Direction bbm::ACharacter::getCardinal() const
{
	return _card;
}