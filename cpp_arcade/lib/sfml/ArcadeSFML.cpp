//
// EPITECH PROJECT, 2018
// sfml
// File description:
// SFML Graphic Lib
//

#include <iostream>
#include "Error.hpp"
#include "ArcadeSFML.hpp"

void arc::SFML::setup()
{
	_wd = new sf::RenderWindow(sf::VideoMode(width, height), "Arcade");
	if (!_font.loadFromFile("./fonts/arcade2.ttf"))
		throw arc::ArcadeError("Error when loading font");
}

void arc::SFML::clear()
{
	_wd->clear(sf::Color::Black);
}
void arc::SFML::display() const
{
	_wd->display();
}

bool arc::SFML::isWindowOpen() const
{
	return (_wd->isOpen());
}

int arc::SFML::createTexture(const std::string &path)
{
	std::string fpath = path + "/block.png";
	sf::Texture *texture = new sf::Texture;

	if (!texture->loadFromFile(fpath))
		return (-1);
	_blocks.push_back(texture);
	return (_blocks.size() - 1);
}
void arc::SFML::drawBlock(const arc::Block &b,
	const arc::Vec2<size_t> &msize) const
{
	int x = 0;
	int y = 0;
	sf::IntRect rectSize;
	sf::Sprite rect;

	if (_blocks.size() <= (size_t)b.textureIdx)
		return;
	rect.setTexture(*_blocks[b.textureIdx]);
	x = ceil((float)b.pos.x * (float)arc::SFML::width
		/ (msize.x == 0 ? 1.0 : (float)msize.x));
	y = ceil((float)b.pos.y * (float)arc::SFML::height
		/ (msize.y == 0 ? 1.0 : (float)msize.y));
	rect.setPosition(x, y);
	rectSize.width = ceil((float)arc::SFML::width /
		(msize.x == 0 ? 1.0f : (float)msize.x));
	rectSize.height = ceil((float)arc::SFML::height /
		(msize.y == 0 ? 1.0f : (float)msize.y));
		sf::IntRect size = rect.getTextureRect();
	rect.scale((float)rectSize.width / size.width, (float)rectSize.height / size.height);
	_wd->draw(rect);
}

void arc::SFML::drawText(const std::string &to_print,
	const arc::Vec2<float> &pos, const arc::Vec2<size_t> &msize)
{
	sf::Text text;
	int x = 0;
	int y = 0;

	text.setFont(_font);
	text.setString(to_print);
	text.setCharacterSize(_font_size);
	text.setColor(_color);
	x = pos.x * arc::SFML::width / (msize.x == 0 ? 1 : msize.x);
	y = pos.y * arc::SFML::height / (msize.y == 0 ? 1 : msize.y);
	text.setPosition(x, y);
	_wd->draw(text);
}

void arc::SFML::setTextAttributes(size_t font_size, size_t hexcolor)
{
	int r = (hexcolor >> 16) & 0xFF;
	int g = (hexcolor >> 8) & 0xFF;
	int b = (hexcolor) & 0xFF;
	_font_size = font_size * 4;
	_color = {static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g),
		static_cast<sf::Uint8>(b), 255};
}

bool arc::SFML::pollEvent()
{
	return (_wd->pollEvent(_event));
}

void arc::SFML::destroy()
{
	_blocks.clear();
}

void arc::SFML::closeWindow()
{
	_wd->close();
}

int arc::SFML::getKeyCode() const
{
	int value = -1;

	if (_event.type == sf::Event::KeyPressed) {
		switch (_event.key.code) {
			case sf::Keyboard::Down:
			return (arc::KeyCode::DOWN);
			case sf::Keyboard::Up:
			return (arc::KeyCode::UP);
			case sf::Keyboard::Left:
			return (arc::KeyCode::LEFT);
			case sf::Keyboard::Right:
			return (arc::KeyCode::RIGHT);
			case sf::Keyboard::Escape:
			return (arc::KeyCode::ESCAPE);
			case sf::Keyboard::Return:
			return (arc::KeyCode::ENTER);
			case sf::Keyboard::BackSpace:
			return (arc::KeyCode::BACKSPACE);
			default:
			if (_event.key.code == 57)
				return (32);
			value = _event.key.code + 'A';
			return (value);
		}
	}
	return (-1);
}
