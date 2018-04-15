/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gkrellm.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:25:38 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 20:51:42 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gkrellm.hpp"
#include <unistd.h>

Gkrellm::Gkrellm() { }

Gkrellm::Gkrellm(int a, char **v)
{
	check_flags(a, v);
	modules.push_back(new TimeData());
	modules.push_back(new UserHostName());
	modules.push_back(new Cpu());
	modules.push_back(new Ram());
	modules.push_back(new Network());
	modules.push_back(new Info());
	graphic.push_back(new Graphic("Time/Date", 200, 20));
	graphic.push_back(new Graphic("User/HostName", 200, 30));
	graphic.push_back(new Graphic("CPU", 400, 30));
	graphic.push_back(new Graphic("RAM", 400, 30));
	graphic.push_back(new Graphic("Network", 400, 20));
	graphic.push_back(new Graphic("INFO", 400, 30));
	std::string mode = v[1];
	if (mode == "-g")
		init_graphic_mode();
	else if (mode == "-c")
		init_console_mode();
	else
	{
		std::cout << "wrong mode\n";
		exit(-1);
	}

}

Gkrellm::Gkrellm(Gkrellm const & obj) { *this = obj;}

Gkrellm::~Gkrellm() { }

Gkrellm & Gkrellm::operator = (Gkrellm const & obj)
{
	for (int i = 0; i < 6; i++)
		flags[i] = obj.flags[i];
	return (*this);
}

void Gkrellm::check_flags(int ac, char **av)
{
	std::cout << "./ft_gkrellm [mode] [flags]\nmode:\n-g graphic\n-c"
	<< " console\nflags:\n-time\n-name\n-cpu\n-ram\n-network\n-info" << std::endl;
	for (int i = 0; i < 6; i++)
		flags[i] = 0;
	if (ac == 1)
		exit(-1);
	if (ac == 2)
		for (int i = 0; i < 6; i++)
			flags[i] = 1;
	std::string str;
	std::string arr[6] = { "-time", "-name", "-info", "-cpu", "-ram", "-network" };
	int i = 1;
	while(++i < ac)
	{
		str = av[i];

		for (int it = 0; it < 6; it++)
		{
			if (str == arr[it])
				flags[it] = 1;
			if (str != arr[0] && str != arr[1] && str != arr[2] && str != arr[3] && str != arr[4] && str != arr[5] )
			{
				std::cout << "wrong param" << std::endl;
				exit(-1);
			}
		}
	}
}

void Gkrellm::init_console_mode()
{
	if (!initscr())
	{
		std::cout <<  "Error initialising ncurses." << std::endl;
		exit(1);
	}
	initscr();
	curs_set(0);
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);

	modules[2]->data_reading();
	modules[1]->data_reading();

	std::vector<std::string> disp;
	std::vector<std::string>::iterator it;
	std::string header[6] =
	{
		"***************************<<TIME>>***************************\n",
		"***********************<<USER/HOSTNAME>>**********************\n",
		"***************************<<INFO>>***************************\n",
		"***************************<<CPU>>****************************\n",
		"***************************<<RAM>>****************************\n",
		"*************************<<NETWORK>>**************************\n"
	};
	while(1)
	{
		clear();
		for (int i = 0; i < 6; i++)
		{
			if (flags[i])
			{
				attron(COLOR_PAIR(1));
				printw("%s", header[i].c_str());
				attroff(COLOR_PAIR(1));
				modules[i]->data_reading();
				disp = modules[i]->getData();
				for (it = disp.begin(); it != disp.end(); it++)
					printw("%s\n", it->c_str());
			}
		}
		int ch = getch();
		switch (ch) {
			case 'q':
				endwin();
				exit(0);
				break;
		}
		refresh();
		usleep(10000);
	}
}

void Gkrellm::init_graphic_mode()
{
	modules[2]->data_reading();
	modules[1]->data_reading();

	SDL_Event		event;

	for (int i = 0; i < 6; i++)
		if (flags[i])
			graphic[i]->init_module();

	unsigned last_time = SDL_GetTicks();
	while(1)
	{
		if (SDL_GetTicks() - last_time > 300)
		{
			for (int i = 0; i < 6; i++)
				if (flags[i] && graphic[i])
					draw_module(*modules[i], *graphic[i]);
			last_time = SDL_GetTicks();
		}
		while (SDL_PollEvent(&event))
			if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) || event.type == SDL_QUIT)
				exit(0);
			else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE)
				for (unsigned i = 0; i < graphic.size(); i++)
					if (flags[i] && graphic[i] && SDL_GetWindowID(graphic[i]->getWin()) == event.window.windowID)
					{
						SDL_DestroyWindow(graphic[i]->getWin());
						graphic[i] = 0;
					}
	}
}
