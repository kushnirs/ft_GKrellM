/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:59:16 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 20:55:15 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

#include "IMonitorDisplay.hpp"
#include "SDL_ttf.h"
#include "SDL.h"

class Graphic : public IMonitorDisplay {
private:
	std::string			_name;
	SDL_Window			*win;
	SDL_Surface			*surface;
	int					x;
	int					y;

	static int		_last_y;
public:
	Graphic();
	Graphic(std::string name, int x, int y);
	Graphic(Graphic const & obj);
	~Graphic();
	SDL_Window	*getWin();
	void	init_module();
	void 	display_message(std::string const & module, int x, int y);
	Graphic & operator = (Graphic const & obj);
	void	display_module();
};

#endif