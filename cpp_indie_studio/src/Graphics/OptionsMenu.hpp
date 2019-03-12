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

	class OptionsMenu : public AScene {
	public:
		OptionsMenu(irr::IrrlichtDevice *device, MyEventReceiver &event);
		~OptionsMenu();
		const std::string run() override;

	private:
		irr::scene::ISceneManager *_sceneManager;
		irr::video::IVideoDriver *_driver;
		Animation _volume;
		Animation _slider;
		Animation _plus;
		Animation _minus;
		int _idx;
		std::vector<Animation> _selectable;
		Sound _clic;
		void _initScene();
		const std::string _handleEnter(int idx);
		int _handleEvent();
	};
}
