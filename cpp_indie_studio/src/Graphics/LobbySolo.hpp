/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** LobbySolo
*/

#pragma once

#include <irr/irrlicht.h>
#include <vector>
#include "Graphics/Event.hpp"
#include "Graphics/Animation.hpp"
#include "Graphics/AScene.hpp"
#include "Sound.hpp"

namespace bbm {

	class LobbySolo : public AScene {
	public:
		LobbySolo(irr::IrrlichtDevice *device, MyEventReceiver &event);
		~LobbySolo();
		const std::string run() override;
		int getAI() const;

	private:
		irr::scene::ISceneManager *_sceneManager;
		irr::video::IVideoDriver *_driver;
		irr::gui::IGUIEnvironment *_gui;
		irr::gui::IGUIFont *_font;
		int _ia;
		void _initScene();
		void _placePlayer();
		const std::string _handleEnter(int idx);
		int _handleEvent();
		Animation _plus;
		Animation _minus;
		std::vector<Animation> _bbms;
		std::vector<Animation> _numbers;
		Sound _clic;
	};
}
