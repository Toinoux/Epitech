//
// EPITECH PROJECT, 2018
// ArcadeSolarFox
// File description:
// SolarFox Game
//

#pragma once

#include "Game.hpp"

namespace arc {

	class SolarFox : public Game {
		class Bullet {
		public:
			Bullet(const arc::Block &b, Vec2<float> _dir,
				bool _ofPlayer) :
			block(b), dir(_dir), ofPlayer(_ofPlayer), iPos(b.pos),
			toDelete(false)
			{ textureIdx = b.textureIdx; }
			arc::Block 	block;
			int		textureIdx;
			Vec2<float> 	dir;
			bool		ofPlayer;
			Vec2<float> 	iPos;
			bool		toDelete;
		};
	public:
		SolarFox();
		std::shared_ptr<arc::IGame>	getInstance() const final;
		arc::GameStatus 		update(int) final;		
	private:
		void	newLevel();
		bool	isCollided(const Vec2<float> &, const Vec2<float> &,
			float size);
		void	checkGemTouched(const Vec2<float> &);
		void	checkBulletTouched(Bullet &);
		void	loadLevel();
		void	updatePosition();
		void	initBlocksPaths();
		void	keyHandler(int);
		void	specialKeyHandler(int);
		void	gunsHandler(std::vector<arc::Block> &);
		void	bulletsHandler(std::vector<arc::Block> &);
		void	handleBulletsRange();
		void	handleBulletsCollisions();
		void	updateSpaceship(std::vector<arc::Block> &);
		void	shoot(int, arc::Vec2<float>,
			arc::Vec2<float>, bool = false);
	private:
		static constexpr size_t len = 4;
		static constexpr size_t row = 10;
		static constexpr size_t col = 15;
		static constexpr float spaceshipSpd = 0.1;
		bool			_playing;
		arc::Vec2<float>	_guntop;
		arc::Vec2<float>	_gunbot;
		float			_gunspd;
		int			_dir;
		arc::Vec2<float>	_spaceship;
		int			_spaceshipDir;
		float			_spaceshipSpd;
		std::vector<Bullet>	_bullets;
		float			_bulletSpd;
		bool			_firstTurn;
		std::vector<Block>	_levelMap;
		std::vector<Block>	_tmpMap;
		int			_curScore;
		int			_shootRate;		
		enum Bloc {
			BG,
			BULLETO,
			HBULLETO,
			BULLETV,
			HBULLETV,
			GEM,
			GUNBOT,
			GUNTOP,
			SPACESHIPR,
			SPACESHIPL,
			SPACESHIPU,
			SPACESHIPD
		};
	};
}