/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** LobbySolo
*/

#include <iostream>
#include "Graphics/LobbySolo.hpp"

namespace bbm {
	LobbySolo::LobbySolo(irr::IrrlichtDevice *device, MyEventReceiver &event)
		: AScene(device, event),
		  _sceneManager(device->getSceneManager()),
		  _driver(device->getVideoDriver()),
		  _gui(device->getGUIEnvironment()),
		  _ia(1),
		  _plus(Animation(_sceneManager, "dist/plus.x")),
		  _minus(Animation(_sceneManager, "dist/moins.x")),
		  _clic("sounds/clic.wav", Sound::SOUND)
	{
		for (unsigned int i = 0; i < 9; i++)
			_bbms.push_back(Animation(_sceneManager, "dist/Bomberman.x"));
		for (unsigned int i = 1; i < 10; i++)
			_numbers.push_back(Animation(_sceneManager, "dist/" + std::to_string(i) + ".x"));
		_initScene();
		_device->setWindowCaption(L"Bomberman - Play");
		_font = _gui->getFont("dist/megaman_2.png");
		if (!_font)
			throw std::runtime_error("Invalid font");
	}

	LobbySolo::~LobbySolo()
	{
		_sceneManager->clear();
	}

	void LobbySolo::_initScene()
	{
		irr::video::ITexture *sky = _driver->getTexture("dist/skybox.png");

		_sceneManager->addCameraSceneNode(0);
		_sceneManager->getActiveCamera()->bindTargetAndRotation(false);
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(60, -20, 100), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(0, 10, 30), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addSkyBoxSceneNode(sky, sky, sky, sky, sky, sky);

		_plus.loadAnimationMap(bbm::playAnimation);
		_plus.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_plus.addRotation(irr::core::vector3df(0, 90, 0));
		_plus.addPosition(irr::core::vector3df(10, 5, 50));
		_plus.setLoop(false);
		_plus.play("FIXE");

		_minus.loadAnimationMap(bbm::playAnimation);
		_minus.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_minus.addRotation(irr::core::vector3df(0, 90, 0));
		_minus.addPosition(irr::core::vector3df(-10, 5, 50));
		_minus.setLoop(false);
		_minus.play("FIXE");

		for (int i = 0; i < 9; i++) {
			_bbms[i].setLoop(true);
			_bbms[i].loadAnimationMap(bbm::bbmAnimation);
			_bbms[i].getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_numbers[i].getModel()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_numbers[i].getModel()->setScale(irr::core::vector3df(7, 7, 7));
			_numbers[i].addRotation(irr::core::vector3df(0, 90, 0));
			_numbers[i].addPosition(irr::core::vector3df(-2, 8, 25));
			if (i != 0) {
				_bbms[i].getModel()->setVisible(false);
				_numbers[i].getModel()->setVisible(false);
			}
			_bbms[i].setTexture(_driver->getTexture("dist/body_man_blue.png"));
			_bbms[i].setFPS(40);
			_bbms[i].getModel()->setScale(irr::core::vector3df(1, 1, 1));
			if (i % 2 == 0)
				_bbms[i].addPosition(irr::core::vector3df(i, -3, i * 2 + 5));
			else {
				_bbms[i].addPosition(irr::core::vector3df(-i * 2, -3, i * 2 + 5));
			}
			_bbms[i].addRotation(irr::core::vector3df(0, 330, 0));
			_bbms[i].play("RUN");
		}
	}

	int LobbySolo::_handleEvent()
	{
		if (_event.isKeyPressed(irr::KEY_LEFT)) {
			if (_ia - 1 <= 0)
				return -1;
			else if (_ia > 1) {
				_bbms[_ia - 1].getModel()->setVisible(false);
				_numbers[_ia - 2].getModel()->setVisible(true);
				_numbers[_ia - 1].getModel()->setVisible(false);
			}
			_ia -= 1;
			_minus.play();
			_clic.play();
		} else if (_event.isKeyPressed(irr::KEY_RIGHT)) {
			if (_ia + 1 >= 10)
				return -1;
			else if (_ia < 10) {
				_bbms[_ia].getModel()->setVisible(true);
				_numbers[_ia].getModel()->setVisible(true);
			}
			_numbers[_ia - 1].getModel()->setVisible(false);
			_ia += 1;
			_plus.play();
			_clic.play();
		} else if (_event.isKeyPressed(irr::KEY_ESCAPE)) {
			return 42;
		}
		if (_event.isKeyPressed(irr::KEY_RETURN)) {
			return 0;
		}
		return -1;
	}

	const std::string LobbySolo::_handleEnter(int idx)
	{
		if (idx == 0) {
			return "GAME";
		} else if (idx == 42)
			return "MAIN";
		return "NEW";
	}

	int LobbySolo::getAI() const {
		return _ia;
	}

	const std::string LobbySolo::run()
	{
		int ret;
		irr::core::stringw str = L"Choose NB IA : ";

		_driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
		ret = _handleEvent();
		if (ret != -1)
			return _handleEnter(ret);
		_sceneManager->drawAll();
		_font->draw(str.c_str(), irr::core::rect<irr::s32>(100, 100, 100, 100), irr::video::SColor(255,100,100,100));
		_driver->endScene();
		return "NEW";
	}
}
