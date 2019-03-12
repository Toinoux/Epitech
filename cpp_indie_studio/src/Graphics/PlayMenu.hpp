/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** PlayMenu
*/

#pragma once

#include <irr/irrlicht.h>
#include <vector>
#include "Graphics/Event.hpp"
#include "Graphics/Animation.hpp"
#include "Graphics/AScene.hpp"

namespace bbm {

	class PlayMenu : public AScene {
		public:
			PlayMenu(irr::IrrlichtDevice *device, MyEventReceiver &event);
			~PlayMenu();
			const std::string run() override;

		private:
			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_driver;
			Animation _new;
			Animation _load;
			unsigned int _idx;
			std::vector<Animation> _selectable;
			void _initScene();
			const std::string _handleEnter(int idx);
			int _handleEvent();
	};
}
