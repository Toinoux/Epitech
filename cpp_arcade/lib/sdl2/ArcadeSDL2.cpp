//
// EPITECH PROJECT, 2018
// SDL2
// File description:
// SDL2 Graphic Lib
//

#include <math.h>
#include "ArcadeSDL2.hpp"

void arc::SDL2::setup()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw arc::ArcadeError("[SDL2] Can't init video.");
	_wd = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, arc::SDL2::width,
		arc::SDL2::height, SDL_WINDOW_SHOWN);
	_renderer = SDL_CreateRenderer(_wd, -1, SDL_RENDERER_ACCELERATED);
	TTF_Init();
	_font = TTF_OpenFont(arc::font_path, arc::SDL2::font_size);
	if (_font == NULL)
		throw arc::ArcadeError(TTF_GetError());
	_color = {255, 255, 255, 1};
	_font_size = 3;
}

void arc::SDL2::clear()
{
	SDL_RenderClear(_renderer);
}

void arc::SDL2::display() const
{
	SDL_RenderPresent(_renderer);
}

bool arc::SDL2::isWindowOpen() const
{
	if (_wd == NULL || _event.type == SDL_QUIT)
		return (false);
	return (true);
}

int arc::SDL2::createTexture(const std::string &path)
{
	std::string fpath = path + "/block.png";
	SDL_Texture *texture = IMG_LoadTexture(_renderer, fpath.c_str());

	if (texture == NULL)
		return (-1);
	_blocks.push_back(texture);
	return (_blocks.size() - 1);
}

void arc::SDL2::drawBlock(const arc::Block &b,
	const arc::Vec2<size_t> &msize) const
{
	if (_blocks.size() <= (size_t)b.textureIdx
		|| _blocks[b.textureIdx] == NULL)
		return;
	SDL_Rect rect;
	rect.x = ceil((float)b.pos.x * (float)arc::SDL2::width
		/ (msize.x == 0 ? 1.0 : (float)msize.x));
	rect.y = ceil((float)b.pos.y * (float)arc::SDL2::height
		/ (msize.y == 0 ? 1.0 : (float)msize.y));
	SDL_QueryTexture(_blocks[b.textureIdx], NULL, NULL, &(rect.w), &(rect.h));
	rect.w = ceil((float)arc::SDL2::width /
		(msize.x == 0 ? 1.0f : (float)msize.x));
	rect.h = ceil((float)arc::SDL2::height /
		(msize.y == 0 ? 1.0f : (float)msize.y));
	SDL_RenderCopy(_renderer, _blocks[b.textureIdx], NULL, &rect);
}

void arc::SDL2::drawText(const std::string &text,
	const arc::Vec2<float> &pos, const arc::Vec2<size_t> &msize)
{
	SDL_Surface* s_text = TTF_RenderText_Solid(_font, text.c_str(), _color);
	SDL_Texture* t_text = SDL_CreateTextureFromSurface(_renderer, s_text);
	SDL_Rect rect;
	rect.x = pos.x * arc::SDL2::width / (msize.x == 0 ? 1 : msize.x);
	rect.y = pos.y * arc::SDL2::height / (msize.y == 0 ? 1 : msize.y);
	TTF_SizeText(_font, text.c_str(), &(rect.w), &(rect.h));
	rect.w = rect.w * _font_size / 10.0;
	rect.h = rect.h * _font_size / 10.0;
	SDL_RenderCopy(_renderer, t_text, NULL, &rect);
}

void arc::SDL2::setTextAttributes(size_t font_size, size_t hexcolor)
{
	int r = (hexcolor >> 16) & 0xFF;
	int g = (hexcolor >> 8) & 0xFF;
	int b = (hexcolor) & 0xFF;
	_font_size = font_size;
	_color = {static_cast<Uint8>(r), static_cast<Uint8>(g),
		static_cast<Uint8>(b), 1};
}

bool arc::SDL2::pollEvent()
{
	return (SDL_PollEvent(&_event));
}

void arc::SDL2::destroy()
{
	for (size_t i = 0; i < _blocks.size(); i++)
		SDL_DestroyTexture(_blocks[i]);
	_blocks.clear();
}

void arc::SDL2::closeWindow()
{
	SDL_Quit();
	SDL_DestroyWindow(_wd);
	SDL_DestroyRenderer(_renderer);
	_wd = NULL;
	_renderer = NULL;
}

int arc::SDL2::getKeyCode() const
{
	if (_event.type == SDL_KEYDOWN) {
		switch (_event.key.keysym.sym) {
			case SDLK_DOWN:
			return (arc::KeyCode::DOWN);
			case SDLK_UP:
			return (arc::KeyCode::UP);
			case SDLK_LEFT:
			return (arc::KeyCode::LEFT);
			case SDLK_RIGHT:
			return (arc::KeyCode::RIGHT);
			case SDLK_ESCAPE:
			return (arc::KeyCode::ESCAPE);
			case SDLK_RETURN:
			return (arc::KeyCode::ENTER);
			case SDLK_BACKSPACE:
			return (arc::KeyCode::BACKSPACE);
			default:
			return (_event.key.keysym.sym);
		}
	}
	return (-1);
}
