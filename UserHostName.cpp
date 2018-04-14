/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserHostName.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:54:31 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 20:14:36 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserHostName.hpp"

UserHostName::UserHostName() {  }

UserHostName::UserHostName(UserHostName const & obj) { *this = obj; }

UserHostName::~UserHostName() {  }

UserHostName & UserHostName::operator = (UserHostName const & obj) { data = obj.data; return (*this); }

std::string const & UserHostName::getData(void) { return (data); }

std::string const & UserHostName::data_reading(void)
{
	FILE* pipe;
	char buffer [100];
	std::string command[] = { "whoami", "hostname"};
	data = "User: ";
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
		if (!i) {data += "Hostname: ";}
		pclose(pipe);
	}
	return (data);
}
