/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** Animation
*/

#include <irr/irrlicht.h>
#include <iostream>
#include "Graphics/Animation.hpp"

namespace bbm {
	Animation::Animation(irr::scene::ISceneManager *sceneManager, const std::string &path) : _scene(sceneManager)
	{
		_model = _scene->addAnimatedMeshSceneNode(_scene->getMesh(path.c_str()));
		if (!_model)
			throw std::runtime_error("Load " + path + " failed.");
		_fps = _model->getAnimationSpeed();
		_model->setLoopMode(false);
		_model->setAnimationSpeed(0);
		_defaultLoop.X = _model->getStartFrame();
		_defaultLoop.Y = _model->getEndFrame();
	}

	Animation::~Animation()
	{
	}

	void Animation::play()
	{
		_isPlaying = true;
		_model->setFrameLoop(_defaultLoop.X, _defaultLoop.Y);
		_model->setAnimationSpeed(_fps);
	}

	void Animation::play(const std::string &anim)
	{
		_isPlaying = true;
		if (_map.find(anim) == _map.end())
			return;
		_model->setFrameLoop(_map[anim].X, _map[anim].Y);
		_model->setAnimationSpeed(_fps);
	}

	void Animation::pause()
	{
		_isPlaying = false;
		_model->setAnimationSpeed(0);
	}

	void Animation::reset()
	{
		_model->setAnimationSpeed(0);
		_model->setCurrentFrame(_model->getStartFrame());
	}

	void Animation::setLoop(bool state)
	{
		_model->setLoopMode(state);
	}

	void Animation::setTexture(irr::video::ITexture *texture)
	{
		_model->setMaterialTexture(0, texture);
	}

	irr::scene::IAnimatedMeshSceneNode *Animation::getModel()
	{
		return _model;
	}

	void Animation::loadAnimationMap(const animationMap &map)
	{
		_map = map;
	}

	void Animation::addPosition(const irr::core::vector3df &pos)
	{
		_model->setPosition(_model->getPosition() + pos);
	}

	void Animation::addRotation(const irr::core::vector3df &angle)
	{
		_model->setRotation(_model->getRotation() + angle);
	}
}
