/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:55:40 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 18:58:35 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cpu.hpp"

Cpu::Cpu() {  }

Cpu::Cpu(Cpu const & obj) { *this = obj; }

Cpu::~Cpu() {  }

Cpu & Cpu::operator = (Cpu const & obj) { data = obj.data; return (*this); }

std::vector<std::string> const & Cpu::getData(void) { return (data); }

void			Cpu::activity(void)
{
	FILE* 		pipe;
	std::string	tmp;
	char buffer [100];

	pipe = popen("top -l 1 -n 0", "r");
	if (!pipe)
	{
	    std::cerr << "Couldn't start command." << std::endl;
	    exit(-1);
	}
	while (fgets(buffer, 100, pipe) != NULL)
	{
	    tmp += buffer;
	}
	pclose(pipe);
	size_t	start = tmp.find("Processes:");
	data.push_back(tmp.substr(start, tmp.find('\n', start)));
	start = tmp.find("CPU usage");
	data.push_back(tmp.substr(start, (tmp.find("idle") + 5) - start));
}

void  Cpu::data_reading(void)
{
	FILE* pipe;
	std::string tmp;
	char buffer [100];
	std::string command[] = { "sysctl -n machdep.cpu.brand_string", "sysctl -n hw.ncpu"};
	for (int i = 0; i < 2; i++)
	{
		pipe = popen(command[i].c_str(), "r");
		if (!pipe)
		{
		    std::cerr << "Couldn't start command." << std::endl;
		    exit(-1);
		}
		while (fgets(buffer, 100, pipe) != NULL)
		{
		    tmp += buffer;
		    tmp[tmp.size() - 1] = 32;
		}
		if (i) { tmp[tmp.size() - 1] = 32; tmp += "cores";}
		pclose(pipe);
	}
	data.clear();
	data.push_back(tmp);
	activity();
}
