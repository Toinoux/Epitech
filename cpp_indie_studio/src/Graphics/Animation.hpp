/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** Animation
*/

#pragma once

#include <string>
#include <unordered_map>

namespace bbm {

	using animationMap = std::unordered_map<std::string, irr::core::vector2d<irr::s32> >;

	static const animationMap bbmAnimation = {
		{"RUN", irr::core::vector2d<irr::s32>(0, 34)},
		{"STAND", irr::core::vector2d<irr::s32>(40, 41)},
	};

	static const animationMap playAnimation = {
		{"FIXE", irr::core::vector2d<irr::s32>(0, 1)},
		{"MOVE", irr::core::vector2d<irr::s32>(2, 85)},
	};

	static const animationMap plusAnimation = {
		{"FIXE", irr::core::vector2d<irr::s32>(0, 1)},
		{"MOVE", irr::core::vector2d<irr::s32>(1, 6)},
	};

	static const animationMap sliderAnimation = {
		{"MOVE 25%", irr::core::vector2d<irr::s32>(0, 11)},
		{"MOVE 50%", irr::core::vector2d<irr::s32>(11, 21)},
		{"MOVE 75%", irr::core::vector2d<irr::s32>(21, 32)},
		{"MOVE 100%", irr::core::vector2d<irr::s32>(32, 42)},
	};

	class Animation {
		public:
			Animation(irr::scene::ISceneManager *sceneManager,
				const std::string &path);
			~Animation();
			void pause();
			void play();
			void play(const std::string &anim);
			void reset();
			void setLoop(bool state);
			void setTexture(irr::video::ITexture *texture);
			void addPosition(const irr::core::vector3df &pos);
			void addRotation(const irr::core::vector3df &angle);
			void loadAnimationMap(const animationMap &map);
			void setFPS(const irr::f32 &fps) { _fps = fps; }
			bool isPlaying() const {return _isPlaying;}
			irr::scene::IAnimatedMeshSceneNode *getModel();
		private:
			irr::scene::ISceneManager *_scene;
			irr::scene::IAnimatedMeshSceneNode *_model;
			irr::f32 _fps;
			irr::core::vector2d<irr::s32> _defaultLoop;
			animationMap _map;
			bool _isPlaying = false;
	};
}
