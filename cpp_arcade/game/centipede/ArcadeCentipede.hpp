//
// EPITECH PROJECT, 2018
// ArcadeCentipede
// File description:
// Centipede Game
//

#pragma once

#include "Game.hpp"
#include <vector>

namespace arc {
	class Centipede : public Game {
	public:
		Centipede();
		std::shared_ptr<arc::IGame>	getInstance() const final;
		arc::GameStatus			update(int) final;
	public:
		enum ChiloDir {
			DOWNLEFT = 0,
			DOWN,
			DOWNRIGHT,
			LEFT,
			RIGHT
		};
		class Chilopod
		{
		public:
			Chilopod(int length);
			void createChilopod(int textIdx);
			void createChilopod(int textIdx, int length);
		public:
			int			_length;
			int			_dir;
			arc::Vec2<float>	_pos;
			std::vector<arc::Block>	_wBody;
		};
	private:
		void				initBlocksPaths();
		std::vector<arc::Block>		initObstacleOnMap();
		std::vector<arc::Block>		putObstcl(std::vector
						<arc::Block> map);
		bool				checkIfFree
						(arc::Vec2<float> pos,
						std::vector<arc::Block> map);
		void				handleKey(int key);
		std::vector<arc::Block>		managePlayer
						(std::vector<arc::Block> map);
		std::vector<arc::Block>		manageShot
						(std::vector<arc::Block> map);
		std::vector<arc::Block>		manageCentipedes
						(std::vector<arc::Block> map);
		bool				isTouchingObtscl
						(arc::Vec2<float> pos);
		bool				isTouchingChilopod
						(arc::Vec2<float> pos);
		void				whereTouchingChilopod
						(int block,
						arc::Vec2<float> pos);
		void				changeObstcl
						(int block, int textIdx);
		void				changeChilopod
						(int block);
		arc::Centipede::Chilopod	getHeadNewPos
						(arc::Centipede::Chilopod
						chilopod);
		arc::Centipede::Chilopod	getNewHeadDir
						(arc::Centipede::Chilopod
						chilopod);
		arc::Centipede::Chilopod	updateChilopodPos
						(arc::Centipede::Chilopod
						chilopod);
		std::vector<arc::Block>		renderChilopod
						(arc::Centipede::Chilopod
						chilo, std::vector<arc::Block>
						map);
		std::vector<arc::Centipede::Chilopod> checkIfOnScreen
						(int count, std::vector
						<arc::Centipede::Chilopod>
						chilopods);

	private:
		static constexpr size_t		row = 30;
		static constexpr size_t		col = 30;
		enum {
			OBSTCL_1 = 11,
			OBSTCL_2,
			OBSTCL_3,
			OBSTCL_4,
			OBSTCL_5
		};
	private:
		bool				_firstTurn;
		bool				_playing;
		bool				_isFiring;
		bool				_isShotOnScreen;
		bool				_isChiloOnScreen;
		int				_prevChiloDir;
		std::vector<arc::Block>		_obstcl;
		std::vector<arc::Centipede::Chilopod> _chilopods;
		arc::Vec2<float>		_shotPos;
		arc::Vec2<float>		_playerPos;
	};
}
