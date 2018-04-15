/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ram.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:55:40 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 18:54:12 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ram.hpp"

Ram::Ram() {  }

Ram::Ram(Ram const & obj) { *this = obj; }

Ram::~Ram() {  }

Ram & Ram::operator = (Ram const & obj) { data = obj.data; return (*this); }

std::vector<std::string> const & Ram::getData(void) { return (data); }

void Ram::data_reading(void)
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
	size_t	start = tmp.find("PhysMem:");
	data.clear();
	data.push_back(tmp.substr(start, tmp.find('\n', start) - start));
}