/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:54:50 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 20:22:45 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Info.hpp"

Info::Info() {  }

Info::Info(Info const & obj) { *this = obj; }

Info::~Info() {  }

Info & Info::operator = (Info const & obj) { data = obj.data; return (*this); }

std::string const & Info::getData(void) { return (data); }

std::string const & Info::data_reading(void)
{
	FILE* pipe;
	char buffer [100];
	std::string command[] =
	{
		"system_profiler SPSoftwareDataType | grep \"System Version\" | sed 's/^[ \t]*//'",
		"system_profiler SPSoftwareDataType | grep \"Kernel Version\" | sed 's/^[ \t]*//'"
	};
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
		    data += buffer;
		}
		pclose(pipe);
	}
	return (data);
}