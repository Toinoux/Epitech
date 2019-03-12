/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** AScene
*/

#pragma once

#include <irr/irrlicht.h>
#include "Graphics/Event.hpp"

// #include "SocketManager.hpp"

namespace bbm
{
	class AScene
	{
	public:
		AScene(irr::IrrlichtDevice *device, MyEventReceiver &event) : _device(device), _event(event) {}
		virtual ~AScene() = default;
		virtual const std::string run() = 0;
	protected:
		irr::IrrlichtDevice *_device;
		MyEventReceiver &_event;
	};
}
