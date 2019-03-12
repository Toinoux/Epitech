/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** MainMenu
*/

#pragma once

#include <irr/irrlicht.h>
#include <vector>
#include "Graphics/Event.hpp"
#include "Graphics/Animation.hpp"
#include "Graphics/AScene.hpp"
#include "Sound.hpp"

namespace bbm {
	class MainMenu : public AScene {
		public:
			MainMenu(irr::IrrlichtDevice *device, MyEventReceiver &event);
			~MainMenu();
			const std::string run() override;

		private:
			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_driver;
			irr::gui::IGUIEnvironment *_gui;
			irr::gui::IGUISkin *_skin;
			Animation _play;
			Animation _multi;
			Animation _options;
			Animation _quit;
			Animation _bbm;
			Animation _bbm2;
			Animation _bbm3;
			Animation _bombe;
			unsigned int _idx;
			Sound _clic;
			Sound _moveButton;
			Sound _dems;
			std::vector<Animation> _selectable;
			void _initScene();
			const std::string _handleEnter(int idx);
			int _handleEvent();
	};
}
