/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:24:08 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 15:13:16 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include <iostream>
#include <ncurses.h>
#include "SDL_ttf.h"
#include "SDL.h"

class IMonitorDisplay {
public:
	virtual void	init_module() = 0;
};


#endif