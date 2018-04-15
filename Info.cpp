/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:54:50 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 18:57:00 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Info.hpp"

Info::Info() {  }

Info::Info(Info const & obj) { *this = obj; }

Info::~Info() {  }

Info & Info::operator = (Info const & obj) { data = obj.data;  return (*this); }

std::vector<std::string> const & Info::getData(void) { return (data); }

void Info::data_reading(void)
{
	FILE* pipe;
	std::string tmp;
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
		    tmp += buffer;
		}
		pclose(pipe);
	}
	size_t	start = tmp.find("System");
	data.clear();
	data.push_back(tmp.substr(start, tmp.find('\n', start)));
	start = tmp.find("Kernel");
	data.push_back(tmp.substr(start, tmp.size() - start - 1));
}