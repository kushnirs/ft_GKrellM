/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:54:52 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 20:14:24 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_HPP
# define INFO_HPP

#include "IMonitorModule.hpp"

class Info : public IMonitorModule {
private:
	std::string		data;
public:
	Info();
	Info(Info const & obj);
	~Info();
	std::string const & getData(void);
	Info & operator = (Info const & obj);
	std::string const & data_reading(void);
};

#endif