/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:59:16 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 23:27:03 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

#include "IMonitorDisplay.hpp"
#include "SDL_ttf.h"
#include "SDL.h"

class Graphic : public IMonitorDisplay {
private:
	SDL_Window			*win;
	SDL_Surface			*surface;
	SDL_Event			event;
	int					close_sdl(void);
	int					events(void);
public:
	Graphic();
	Graphic(Graphic const & obj);
	~Graphic();
	void display_message(std::string const & module);
	Graphic & operator = (Graphic const & obj);
	void	display_module(std::string const & module);
};

#endif