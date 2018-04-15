/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserHostName.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:54:31 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 18:51:12 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserHostName.hpp"

UserHostName::UserHostName() {  }

UserHostName::UserHostName(UserHostName const & obj) { *this = obj; }

UserHostName::~UserHostName() {  }

UserHostName & UserHostName::operator = (UserHostName const & obj) { data = obj.data; return (*this); }

std::vector<std::string> const & UserHostName::getData(void) { return (data); }

void UserHostName::data_reading(void)
{
	FILE* pipe;
	char buffer [100];
	std::string tmp;
	std::string command[] = { "whoami", "hostname"};
	tmp = "User: ";
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
		if (!i) {tmp += "Hostname: ";}
		pclose(pipe);
	}
	data.clear();
	data.push_back(tmp.substr(0, tmp.find('\n', 0)));
	data.push_back(tmp.substr(data[0].size() + 1, tmp.size() - data[0].size() - 2));
}
