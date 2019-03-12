/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** OptionsMenu
*/

#pragma once

#include <irr/irrlicht.h>
#include <vector>
#include "Event.hpp"
#include "Animation.hpp"
#include "AScene.hpp"
#include "Sound.hpp"

namespace bbm {

	class MultiMenu : public AScene {
	public:
		MultiMenu(irr::IrrlichtDevice *device, MyEventReceiver &event);
		~MultiMenu();
		const std::string run() override;

	private:
		irr::scene::ISceneManager *_sceneManager;
		irr::video::IVideoDriver *_driver;
		Animation _play;
		Sound _clic;
		void _initScene();
		const std::string _handleEnter(int idx);
		int _handleEvent();
	};
}
