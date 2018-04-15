/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeData.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:55:31 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 18:52:15 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEDATA_HPP
# define TIMEDATA_HPP

#include "IMonitorModule.hpp"

class TimeData : public IMonitorModule {
private:
	std::vector<std::string>		data;
public:
	TimeData();
	TimeData(TimeData const & obj);
	~TimeData();
	std::vector<std::string> const & getData(void);
	TimeData & operator = (TimeData const & obj);
	void data_reading(void);
};

#endif