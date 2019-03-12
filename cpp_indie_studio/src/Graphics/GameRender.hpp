/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** GameRender
*/

#pragma once

#include <irr/irrlicht.h>
#include <vector>
#include <unordered_map>
#include <functional>
#include <memory>
#include <map>
#include <utility>
#include "Core/CoreServer.hpp"
#include "Core/CorePlayer.hpp"
#include "Graphics/Event.hpp"
#include "Graphics/Animation.hpp"
#include "Graphics/AScene.hpp"
#include "Threads/ThreadPool.hpp"
#include "Sound.hpp"

namespace bbm {

	static std::unordered_map<unsigned int, std::string> _meshMap {
		{ BLANK, "dist/ground.x"},
		{ BREAKABLE_WALL, "dist/destruct_wall_v2.x"},
		{ PLAYER, "dist/BomberMan.x"},
		{ BOMB, "dist/bomb_v3.x"},
		{ POWERUP_SPEED, "dist/powerup.x"},
	};

	static std::unordered_map<unsigned int, std::string> _meshTexture {
		{ BREAKABLE_WALL, "dist/wall3.jpg"},
	};

	constexpr float OFFSET = 2.95;
	constexpr float XSTART = -20;
	constexpr float YSTART = 20;
	constexpr float XPLAYER = -21.5;
	constexpr float YPLAYER = 21.5;

	class GameRender : public AScene {
		public:
			GameRender(irr::IrrlichtDevice *device, MyEventReceiver &event, unsigned int ai);
			~GameRender();
			const std::string run() override;

		private:
			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_driver;
			void _initScene();
			const std::string _handleEnter(int idx);
			int _handleEvent();
			unsigned int _ai;
			std::string _map;
			void _initMap();
			void _updateMap();
			void _initPlayer();
			void _placePlayer();
			std::pair<unsigned int, unsigned int> _getCoord(unsigned int i);
			std::unordered_map<irr::EKEY_CODE, std::function<void()> > _keyMap;
			std::map<unsigned int, std::unique_ptr<Animation> > _ground;
			std::map<unsigned int, std::unique_ptr<Animation> > _entity;
			std::map<unsigned int, std::unique_ptr<Animation> > _players;
			CorePlayer *_player;
			std::thread *_thread;
			Sound _placeBomb;
			Sound _boom;
			Sound _breakWall;
	};
}
