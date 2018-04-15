/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:54:52 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 18:55:40 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_HPP
# define INFO_HPP

#include "IMonitorModule.hpp"

class Info : public IMonitorModule {
private:
	std::vector<std::string> data;
public:
	Info();
	Info(Info const & obj);
	~Info();
	std::vector<std::string> const & getData(void);
	Info & operator = (Info const & obj);
	void data_reading(void);
};

#endif