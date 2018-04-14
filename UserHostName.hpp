/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserHostName.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:54:34 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 19:39:59 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERHOSTNAME_HPP
# define USERHOSTNAME_HPP

#include "IMonitorModule.hpp"

class UserHostName : public IMonitorModule {
private:
	std::string		data;
public:
	UserHostName();
	UserHostName(UserHostName const & obj);
	~UserHostName();
	std::string const & getData(void);
	UserHostName & operator = (UserHostName const & obj);
	std::string const & data_reading(void);
};

#endif