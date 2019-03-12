//
// EPITECH PROJECT, 2018
// OpenGL
// File description:
// OpenGL Graphic Lib
//

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include "ArcadeOpenGL.hpp"

void arc::OpenGL::setup()
{
	_quit = false;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw arc::ArcadeError("OpenGL fail to init video.");
	TTF_Init();
	this->_font = TTF_OpenFont("/home/hungdao/Epitech/CPP/cpp_arcade/lib/opengl/arcade.ttf", 20);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	if (this->_font == NULL)
		throw arc::ArcadeError(TTF_GetError());
	_wd = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, arc::OpenGL::width, arc::OpenGL::height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
//	_renderer = SDL_CreateRenderer(_wd, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	atexit(SDL_Quit);
	this->_glctx = SDL_GL_CreateContext(_wd);
//	SDL_WM_SetCaption("Arcade", NULL);
//	SDL_SetVideoMode(arc::OpenGL::width, arc::OpenGL::height, 32, SDL_OPENGL);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)arc::OpenGL::width/arc::OpenGL::height, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glGenTextures(1, &_font_texture);
}

void arc::OpenGL::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	SDL_RenderClear(_renderer);
}

void arc::OpenGL::display() const
{
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(3, 20, 10, 0, 0, 0, 0, 0, 1);
	//gluLookAt(0, 0, 0, 0, 0, 0, 0, 0, 0);
	glFlush();
	SDL_GL_SwapWindow(_wd);
	glPopMatrix();
//	SDL_GL_SwapBuffers();
}

bool arc::OpenGL::getWindowStatus() const
{
	if (this->_wd == NULL)
		return (false);
	return (true);
}

int arc::OpenGL::createBlock(const std::string &)
{

}

void arc::OpenGL::drawBlock(size_t index, const arc::Vec2 &pos,
			    const arc::Vec2 &msize) const
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)arc::OpenGL::width/arc::OpenGL::height, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();
	int half_grid_size = 10;
	glRotatef(0, 0, 0, 1.0f);
	glRotatef(0, 0, 1.0f, 0);
	glRotatef(half_grid_size * 6, 1.0f, 0, 0);
	glTranslatef(-0, -(half_grid_size * 2), -(half_grid_size));
	glBegin(GL_LINES);
	glColor3f(0.75f, 0.75f, 0.75f);
	for(int i=-half_grid_size;i<=half_grid_size;i++)
	{
		glVertex3f((float)i,0,(float)-half_grid_size);
		glVertex3f((float)i,0,(float)half_grid_size);
		glVertex3f((float)-half_grid_size,0,(float)i);
		glVertex3f((float)half_grid_size,0,(float)i);
	}
	glEnd();

}

void arc::OpenGL::drawText(const std::string &text, const arc::Vec2 &pos, size_t size)
{
	glBindTexture(GL_TEXTURE_2D, _font_texture);
	SDL_Color white = {255, 255, 255, 1};
	_sfont = TTF_RenderText_Blended(_font, text.c_str(), white);
	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, arc::OpenGL::width,0,arc::OpenGL::height);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _sfont->w, _sfont->h, 0, GL_BGRA,
		     GL_UNSIGNED_BYTE, _sfont->pixels);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0,1);
		glVertex2f(pos.x, pos.y);
		glTexCoord2f(1,1);
		glVertex2f(pos.x + _sfont->w + size, pos.y);
		glTexCoord2f(1,0);
		glVertex2f(pos.x + _sfont->w + size, pos.y + _sfont->h + size);
		glTexCoord2f(0,0);
		glVertex2f(pos.x, pos.y + _sfont->h + size);
	}
	glEnd();
	glPopMatrix();
	glDeleteTextures(1, &_font_texture);
/*	SDL_Color white = {255, 255, 255, 1};
	SDL_Surface *surface = TTF_RenderText_Solid(_font, text.c_str(), white);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_Rect rect;
	rect.x = pos.x;
	rect.y = pos.y;
	TTF_SizeText(_font, text.c_str(), &(rect.w), &(rect.h));
	rect.h = rect.h * size;
	rect.w = rect.w * size;
	SDL_RenderCopy(_renderer, texture, NULL, &rect);*/
/*	glRasterPos2f(pos.x, pos.y);
	for (size_t i = 0; i < text.size(); i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);	*/
}

void arc::OpenGL::destroy()
{

}

int arc::OpenGL::getKeyCode() const
{
	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_KEYDOWN:
			switch(e.key.keysym.sym) {
			case SDLK_DOWN:
				return (arc::KeyCode::DOWN);
			case SDLK_UP:
				return (arc::KeyCode::UP);
			case SDLK_LEFT:
				return (arc::KeyCode::LEFT);
			case SDLK_RIGHT:
				return (arc::KeyCode::RIGHT);
			default:
				break;
			}
			break;
		case SDL_QUIT:
			SDL_Quit();
			break;
		}
	}
	return (-1);
}
