/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gkrellm.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:26:12 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 20:53:58 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GKRELLM_HPP
# define GKRELLM_HPP

#include "UserHostName.hpp"
#include "TimeData.hpp"
#include "Info.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"
#include "Network.hpp"
#include "Graphic.hpp"

template < class M, class D >
void draw_module(M  & mod, D  & disp)
{
	mod.data_reading();
	disp.display_module();
	if (!disp.getWin())
		return;
	std::vector<std::string> tmp = mod.getData();
	int y = 0;
	for (std::vector<std::string>::iterator i = tmp.begin(); i != tmp.end(); i++)
	{
		disp.display_message(*i, 0, y);
		y += 15;
	}
	SDL_UpdateWindowSurface(disp.getWin());
}

class Gkrellm {
private:
	std::vector<IMonitorModule *>	modules;
	std::vector<Graphic *> 			graphic;

	int 			flags[6];
	void	init_console_mode();
	void 	init_graphic_mode();
	void	check_flags(int ac, char **av);
	Gkrellm();
public:
	Gkrellm(int a, char **v);
	Gkrellm(Gkrellm const & obj);
	~Gkrellm();
	Gkrellm & operator = (Gkrellm const & obj);
};

#endif