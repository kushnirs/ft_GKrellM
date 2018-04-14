/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:59:14 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 23:35:25 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphic.hpp"

Graphic::Graphic() {  }

Graphic::Graphic(Graphic const & obj) { *this = obj; }

Graphic::~Graphic() {  }

Graphic & Graphic::operator = (Graphic const & obj) { win = obj.win; surface = obj.surface;
event = obj.event; return (*this); }

void Graphic::display_message(std::string const & module)
{
	TTF_Font				*ttf;
	SDL_Surface				*param;

	ttf = TTF_OpenFont("ARIAL.TTF", 15);
	param = TTF_RenderText_Solid(ttf, module.c_str(),
		(SDL_Color){255, 255, 255, 255});
	SDL_BlitSurface(param, NULL, surface, NULL);
	TTF_CloseFont(ttf);
	SDL_FreeSurface(param);	
}

int	Graphic::close_sdl(void)
{
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}

int			Graphic::events(void)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			return (close_sdl());
	}
	else if (event.type == SDL_QUIT)
		return (close_sdl());
	return (1);
}

void	Graphic::display_module(std::string const & module)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	win = SDL_CreateWindow("GKrellM", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 200, 70, 0);
	if (!win)
	{
		std::cout << "Window error: %s\n" << std::endl;
		exit(-1);
	}
	surface = SDL_GetWindowSurface(win);
	if (!surface)
	{
		std::cout << "Surface error: %s\n" <<std::endl;
		exit(-1);
	}
	while (1)
	{
		display_message(module);
		while (SDL_PollEvent(&event))
			if (!events())
				exit(-1);
		SDL_UpdateWindowSurface(win);
	}
}
