/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** GameRender
*/

#include <iostream>
#include <utility>
#include "Generator.hpp"
#include "Graphics/GameRender.hpp"

namespace bbm {
	GameRender::GameRender(irr::IrrlichtDevice *device, MyEventReceiver &event, unsigned int ai)
		: AScene(device, event),
		_sceneManager(device->getSceneManager()),
		_driver(device->getVideoDriver()),
		  _ai(ai), _player(nullptr),
		  _placeBomb("sounds/pose_bomb.wav", Sound::SOUND),
		  _boom("sounds/boom.wav", Sound::SOUND),
		  _breakWall("sounds/break_wall.wav", Sound::SOUND)
	{
		_thread = new std::thread{[](int ai) {CoreServer serv(DEFAULT_PORT, ai); serv.run();}, ai + 1};
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		_player = new CorePlayer(DEFAULT_PORT, DEFAULT_IP);
		_player->enterLobby(ai);
		while (_player->inLobby() == true);
		_initScene();
		_device->setWindowCaption(L"Bomberman - Game");
		_keyMap[irr::KEY_KEY_Z] = [this]() { _player->_requestMove(NORTH); };
		_keyMap[irr::KEY_KEY_S] = [this]() { _player->_requestMove(SOUTH); };
		_keyMap[irr::KEY_KEY_Q] = [this]() { _player->_requestMove(WEST); };
		_keyMap[irr::KEY_KEY_D] = [this]() { _player->_requestMove(EAST); };
		_keyMap[irr::KEY_SPACE] = [this]() { _player->_requestBomb(); };
	}

	GameRender::~GameRender()
	{
		_sceneManager->clear();
		_player->quit();
		_thread->detach();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		delete _player;
		delete _thread;
	}

	std::pair<unsigned int, unsigned int> GameRender::_getCoord(unsigned int i)
	{
		int x = i % MAP_SIZE;
		int y = i / MAP_SIZE;

		if (i == 0)
			x = 0;
		return (std::make_pair(x, y));
	}

	void GameRender::_initMap()
	{
		for (unsigned int i = 0; i < _map.size(); i++) {
			if (_map[i] == UNBREAKABLE_WALL)
				continue;
			else if (_map[i] == BLANK) {
				std::pair<unsigned int, unsigned int> coord = _getCoord(i);
				_ground[i] = std::make_unique<Animation>(Animation(_sceneManager, _meshMap[BLANK]));
				_ground[i]->getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				_ground[i]->getModel()->setPosition(irr::core::vector3df(XSTART + (OFFSET * coord.first), (YSTART - (OFFSET * coord.second)), 0));
				_ground[i]->getModel()->setRotation(irr::core::vector3df(-90, 0, 0));
			} else {
				std::pair<unsigned int, unsigned int> coord = _getCoord(i);
				_ground[i] = std::make_unique<Animation>(Animation(_sceneManager, _meshMap[BLANK]));
				_ground[i]->getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				_ground[i]->getModel()->setPosition(irr::core::vector3df(XSTART + (OFFSET * coord.first), (YSTART - (OFFSET * coord.second)), 0));
				_ground[i]->getModel()->setRotation(irr::core::vector3df(-90, 0, 0));
				_entity[i] = std::make_unique<Animation>(Animation(_sceneManager, _meshMap[_map[i]]));
				_entity[i]->getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				_entity[i]->getModel()->setPosition(irr::core::vector3df(XSTART + (OFFSET * coord.first), (YSTART - (OFFSET * coord.second)), 0));
				_entity[i]->getModel()->setRotation(irr::core::vector3df(-90, 0, 0));
			}
		}
	}

	void GameRender::_initPlayer()
	{
		auto &p = _player->getPlayers();
		for (auto &i : p) {
			auto pos = i.second.getPos();
			if (_players.find(i.first) == _players.end()) {
				_players[i.first] = std::make_unique<Animation>(Animation(_sceneManager, _meshMap[PLAYER]));
				_players[i.first]->setTexture(_driver->getTexture("dist/body_man_orange.png"));
				_players[i.first]->getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				_players[i.first]->getModel()->setPosition(irr::core::vector3df(XPLAYER + (OFFSET * pos.first), (YPLAYER - (OFFSET * pos.second)), 0));
				_players[i.first]->getModel()->setRotation(irr::core::vector3df(-90, 0, 0));
				_players[i.first]->loadAnimationMap(bbm::bbmAnimation);
				_players[i.first]->setFPS(50);
				_players[i.first]->setLoop(true);
				_players[i.first]->play("STAND");
			} else {
				_players[i.first]->getModel()->setPosition(irr::core::vector3df(XPLAYER + (OFFSET * pos.first), (YPLAYER - (OFFSET * pos.second)), 0));
				if (i.second.getLives() == 0)
					_players[i.first]->getModel()->setVisible(false);
				if (i.second.getCardinal() == SOUTH)
					_players[i.first]->getModel()->setRotation(irr::core::vector3df(-90, 0, 0));
				else if (i.second.getCardinal() == NORTH)
					_players[i.first]->getModel()->setRotation(irr::core::vector3df(-90, 0, 180));
				else if (i.second.getCardinal() == WEST)
					_players[i.first]->getModel()->setRotation(irr::core::vector3df(-90, 0, 270));
				else if (i.second.getCardinal() == EAST)
					_players[i.first]->getModel()->setRotation(irr::core::vector3df(-90, 0, 90));
				if (i.second.getMove() == true && _players[i.first]->isPlaying() == false) {
					// SON DEPLACEMENT
					_players[i.first]->play("RUN");
				}
				else if (i.second.getMove() == false && _players[i.first]->isPlaying() == true) {
					_players[i.first]->play("STAND");
					_players[i.first]->pause();
				}
			}
		}
	}

	void GameRender::_initScene()
	{
		irr::video::ITexture *sky = _driver->getTexture("dist/skyspace.jpg");
		_sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, -20, -40), irr::core::vector3df(0, 0, 0));
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(60, -20, 100), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(0, 10, 30), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addSkyBoxSceneNode(sky, sky, sky, sky, sky, sky);
		_map = _player->getMap();
		_initMap();
	}

	int GameRender::_handleEvent()
	{
		if (_event.isKeyPressed(irr::KEY_ESCAPE)) {
			return 42;
		}
		if (_event.isKeyReleased(irr::KEY_KEY_Z) && _event.isKeyReleased(irr::KEY_KEY_S)
			&& _event.isKeyReleased(irr::KEY_KEY_D) && _event.isKeyReleased(irr::KEY_KEY_Q))
			_player->_stopMoving();
		for (auto i : _keyMap) {
			if (_event.isKeyDown(i.first))
				i.second();
		}
		if (!_event.isKeyDown(irr::KEY_KEY_D) && !_event.isKeyDown(irr::KEY_KEY_Q) && !_event.isKeyDown(irr::KEY_KEY_S) && !_event.isKeyDown(irr::KEY_KEY_Z))
			_player->_stopMoving();
		return -1;
	}

	const std::string GameRender::_handleEnter(int idx)
	{
		if (idx == 42) {
			return "MAIN";
		}
		return "GAME";
	}

	void GameRender::_updateMap()
	{
		std::string map = _player->getMap();

		for (unsigned int i = 0; i < map.size(); i++) {
			if (_map[i] == UNBREAKABLE_WALL && map[i] != UNBREAKABLE_WALL) {
				std::pair<unsigned int, unsigned int> coord = _getCoord(i);
				_ground[i] = std::make_unique<Animation>(Animation(_sceneManager, _meshMap[BLANK]));
				_ground[i]->getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				_ground[i]->getModel()->setPosition(irr::core::vector3df(XSTART + (OFFSET * coord.first), (YSTART - (OFFSET * coord.second)), 0));
				_ground[i]->getModel()->setRotation(irr::core::vector3df(-90, 0, 0));
			}
			if (map[i] == UNBREAKABLE_WALL)
				continue;
			else if (map[i] != _map[i] && map[i] != BLANK) {
				std::pair<unsigned int, unsigned int> coord = _getCoord(i);
				_entity[i] = std::make_unique<Animation>(Animation(_sceneManager, _meshMap[map[i]]));
				_entity[i]->getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				_entity[i]->getModel()->setPosition(irr::core::vector3df(XSTART + (OFFSET * coord.first), (YSTART - (OFFSET * coord.second)), 0));
				_entity[i]->getModel()->setRotation(irr::core::vector3df(-90, 0, 0));
				if (map[i] == BOMB) {
					_entity[i]->play();
					_placeBomb.play();
				}
				if (_meshTexture.find(map[i]) != _meshTexture.end()) {
					std::string texture(_meshTexture[map[i]]);
					_entity[i]->setTexture(_driver->getTexture(texture.c_str()));
				}
			}
			else if (map[i] != _map[i] && map[i] == BLANK && _map[i] != UNBREAKABLE_WALL) {
				if (_map[i] != BOMB) {
					_entity[i]->play();
					_breakWall.play();
				}
				else {
					_entity[i]->pause();
					_entity[i]->getModel()->setVisible(false);
					_boom.play();
				}
			}
		}
		_map = map;
	}

	const std::string GameRender::run()
	{
		int ret;

		irr::core::stringw str = "FPS :";
		str += _driver->getFPS();
		_device->setWindowCaption(str.c_str());
		_driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
		_player->run();
		_updateMap();
		_initPlayer();
		ret = _handleEvent();
		if (ret != -1)
			return _handleEnter(ret);
		_sceneManager->drawAll();
		_driver->endScene();
		return "GAME";
	}
}
