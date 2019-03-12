/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** model
*/

#pragma once

#include <iostream>
#include <irr/irrlicht.h>


class MyEventReceiver : public irr::IEventReceiver
{
	public:
		enum keyStatesENUM
		{
			UP = 0,
			DOWN,
			PRESSED,
			RELEASED
		};
		virtual bool OnEvent(const irr::SEvent &event)
		{
			if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
				if (event.KeyInput.PressedDown == true) {
					if (keyState[event.KeyInput.Key] != DOWN) {
						keyState[event.KeyInput.Key] = PRESSED;
					} else
						keyState[event.KeyInput.Key] = DOWN;
				} else {
					if (keyState[event.KeyInput.Key] != UP) {
						keyState[event.KeyInput.Key] = RELEASED;
					}
				}
			}
			return (true);
		}

		virtual bool isKeyDown(irr::EKEY_CODE keycode) const
		{
			if (keyState[keycode] == DOWN || keyState[keycode] == PRESSED)
				return (true);
			return (false);
		}

		virtual bool isKeyPressed(irr::EKEY_CODE keycode)
		{
			if (keyState[keycode] == PRESSED) {
				keyState[keycode] = DOWN;
				return (true);
			}
			return (false);
		}

		virtual bool isKeyReleased(irr::EKEY_CODE keycode) const
		{
			if (keyState[keycode] == RELEASED)
				return (true);
			return (false);
		}

		MyEventReceiver()
		{
			for (int i = 0; i <= irr::KEY_KEY_CODES_COUNT; i++)
				keyState[i] = RELEASED;
		}

	private:
		keyStatesENUM keyState[irr::KEY_KEY_CODES_COUNT];
};