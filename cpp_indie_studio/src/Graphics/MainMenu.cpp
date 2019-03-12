/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** MainMenu
*/

#include <iostream>
#include "Graphics/MainMenu.hpp"

namespace bbm {
	MainMenu::MainMenu(irr::IrrlichtDevice *device, MyEventReceiver &event)
		: AScene(device, event),
		  _sceneManager(device->getSceneManager()),
		  _driver(device->getVideoDriver()),
		  _gui(device->getGUIEnvironment()),
		  _skin(_gui->getSkin()),
		  _play(Animation(_sceneManager, "dist/play.x")),
		  _multi(Animation(_sceneManager, "dist/multi.x")),
		  _options(Animation(_sceneManager, "dist/options.x")),
		  _quit(Animation(_sceneManager, "dist/quit.x")),
		  _bbm(Animation(_sceneManager, "dist/BomberMan.x")),
		  _bbm2(Animation(_sceneManager, "dist/BomberMan.x")),
		  _bbm3(Animation(_sceneManager, "dist/BomberMan.x")),
		  _bombe(Animation(_sceneManager, "dist/bomb_v3.x")),
		  _idx(0),
		  _clic("sounds/clic.wav", Sound::SOUND),
		  _moveButton("sounds/move_button.wav", Sound::SOUND),
		  _dems("sounds/dems.wav", Sound::SOUND)
	{
		_initScene();
		_device->setWindowCaption(L"Bomberman");
		_selectable.push_back(_play);
		_selectable.push_back(_multi);
		_selectable.push_back(_options);
		_selectable.push_back(_quit);
	}

	MainMenu::~MainMenu()
	{
		_sceneManager->clear();
	}

	void MainMenu::_initScene()
	{
		irr::video::ITexture *sky = _driver->getTexture("dist/skybox.png");

		_sceneManager->addCameraSceneNode(0);
		_sceneManager->getActiveCamera()->bindTargetAndRotation(false);
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(60, -20, 100), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(-40, 10, 30), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addSkyBoxSceneNode(sky, sky, sky, sky, sky, sky);

		_play.loadAnimationMap(bbm::playAnimation);
		_play.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_play.addRotation(irr::core::vector3df(0, 90, 0));
		_play.addPosition(irr::core::vector3df(-40, 5, 50));
		_play.setLoop(true);
		_play.play("MOVE");

		_multi.loadAnimationMap(bbm::playAnimation);
		_multi.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_multi.addRotation(irr::core::vector3df(0, 90, 0));
		_multi.addPosition(irr::core::vector3df(-40, -10, 50));
		_multi.setLoop(true);

		_options.loadAnimationMap(bbm::playAnimation);
		_options.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_options.addRotation(irr::core::vector3df(0, 90, 0));
		_options.addPosition(irr::core::vector3df(-40, -25, 50));
		_options.setLoop(true);

		_quit.loadAnimationMap(bbm::playAnimation);
		_quit.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_quit.addRotation(irr::core::vector3df(0, 90, 0));
		_quit.addPosition(irr::core::vector3df(-40, -40, 50));
		_quit.setLoop(true);

		_bbm.setLoop(true);
		_bbm.loadAnimationMap(bbm::bbmAnimation);
		_bbm.getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_bbm.setTexture(_driver->getTexture("dist/body_man_blue.png"));
		_bbm.setFPS(40);
		_bbm.getModel()->setScale(irr::core::vector3df(8, 8, 8));
		_bbm.addPosition(irr::core::vector3df(10, -30, 50));
		_bbm.addRotation(irr::core::vector3df(0, 330, 0));
		_bbm.play("RUN");

		_bbm2.setLoop(true);
		_bbm2.loadAnimationMap(bbm::bbmAnimation);
		_bbm2.getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_bbm2.setTexture(_driver->getTexture("dist/body_man_orange.png"));
		_bbm2.setFPS(-400);
		_bbm2.getModel()->setScale(irr::core::vector3df(7, 7, 7));
		_bbm2.addPosition(irr::core::vector3df(80, -30, 200));
		_bbm2.addRotation(irr::core::vector3df(0, 355, 0));
		_bbm2.play("RUN");

		_bbm3.setLoop(true);
		_bbm3.loadAnimationMap(bbm::bbmAnimation);
		_bbm3.getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_bbm3.setTexture(_driver->getTexture("dist/body_man_green.png"));
		_bbm3.setFPS(40);
		_bbm3.getModel()->setScale(irr::core::vector3df(7, 7, 7));
		_bbm3.addPosition(irr::core::vector3df(90, -30, 50));
		_bbm3.addRotation(irr::core::vector3df(0, 355, 0));
		_bbm3.play("RUN");

		_bombe.setFPS(5);
		_bombe.getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_bombe.getModel()->setScale(irr::core::vector3df(8, 8, 8));
		_bombe.setTexture(_driver->getTexture("dist/body_violet.png"));
		_bombe.addPosition(irr::core::vector3df(-10, 0, 100));
		_bombe.addRotation(irr::core::vector3df(0, 75, 0));
		_bombe.play();
	}

	int MainMenu::_handleEvent()
	{
		if (_event.isKeyPressed(irr::KEY_DOWN)) {
			if (_selectable.size() - 1 == _idx)
				return -1;
			_selectable[_idx].reset();
			_idx = (_idx + 1) % _selectable.size();
			_selectable[_idx].play("MOVE");
			_moveButton.play();
		} else if (_event.isKeyPressed(irr::KEY_UP)) {
			if (_idx == 0)
				return -1;
			_selectable[_idx].reset();
			_idx = (_idx - 1) % _selectable.size();
			_selectable[_idx].play("MOVE");
			_moveButton.play();
		} else if (_event.isKeyDown(irr::KEY_RIGHT)) {
			irr::core::vector3df rot = _sceneManager->getActiveCamera()->getTarget();

			rot.X += 1;
			_sceneManager->getActiveCamera()->setTarget(rot);
		} else if (_event.isKeyDown(irr::KEY_LEFT)) {
			irr::core::vector3df rot = _sceneManager->getActiveCamera()->getTarget();

			rot.X -= 1;
			_sceneManager->getActiveCamera()->setTarget(rot);
			_dems.play();
		}
		if (_event.isKeyPressed(irr::KEY_RETURN)) {
			_clic.play();
			return _idx;
		}
		return -1;
	}

	const std::string MainMenu::_handleEnter(int idx)
	{
		if (idx == 0) {
			return "PLAY";
		} else if (idx == 1) {
			return "MULTI";
		} else if (idx == 2) {
			return "OPTIONS";
		} else if (idx == 3) {
			return "EXIT";
		}
		return "MAIN";
	}

	const std::string MainMenu::run()
	{
		int ret;

		_driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
		ret = _handleEvent();
		if (ret != -1)
			return _handleEnter(ret);
		_sceneManager->drawAll();
		_gui->drawAll();
		_driver->endScene();
		return "MAIN";
	}
}
