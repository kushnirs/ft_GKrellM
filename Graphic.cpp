/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:59:14 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 21:00:19 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphic.hpp"

int	Graphic::_last_y = 30;

Graphic::Graphic() : _name("default"), win(NULL), surface(NULL), x(0), y(0) {  }

Graphic::Graphic(std::string name, int x_, int y_) : _name(name), win(NULL), surface(NULL), x(x_), y(y_) {  }

Graphic::Graphic(Graphic const & obj) { *this = obj; }

Graphic::~Graphic() {  }

SDL_Window	* Graphic::getWin() { return (win); }

Graphic & Graphic::operator = (Graphic const & obj) { _name = obj._name; win = obj.win; surface = obj.surface; return (*this); }

void Graphic::display_message(std::string const & module, int x, int y)
{
	TTF_Font				*ttf;
	SDL_Rect				dstrect;
	SDL_Surface				*param;

	ttf = TTF_OpenFont("ARIAL.TTF", 14);
	param = TTF_RenderText_Blended(ttf, module.c_str(),
		(SDL_Color){0, 0, 0, 0});
	dstrect.x = x; dstrect.y = y;  dstrect.h = 0; dstrect.w = 0;
	SDL_BlitSurface(param, NULL, surface, &dstrect);
	TTF_CloseFont(ttf);
	SDL_FreeSurface(param);
}

void	Graphic::display_module()
{
	unsigned *pixels = static_cast<unsigned*>(surface->pixels);
	for (int i = 0; i < (surface->h * surface->w); i++)
			pixels[i] = 0xe6e6e6;
}

void	Graphic::init_module()
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	win = SDL_CreateWindow(_name.c_str(),
		SDL_WINDOWPOS_CENTERED, _last_y + y, x, y, 0);
	_last_y += y + 20;
	if (!win)
	{
		std::cout << "Window error: %s\n" << std::endl;
		exit(-1);
	}
	surface = SDL_GetWindowSurface(win);
}
