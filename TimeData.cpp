/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:55:29 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 20:23:45 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeData.hpp"

TimeData::TimeData() {  }

TimeData::TimeData(TimeData const & obj) { *this = obj; }

TimeData::~TimeData() {  }

TimeData & TimeData::operator = (TimeData const & obj) { data = obj.data; return (*this); }

std::string const & TimeData::getData(void) { return (data); }

std::string const & TimeData::data_reading(void)
{
	time_t rawtime;
	struct tm *info;
	char buffer[80];

	time( &rawtime );
	info = localtime( &rawtime );
	strftime(buffer,80,"%c", info);
	data = buffer;
	return (data += "\n");
}