/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserHostName.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:54:34 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 18:48:23 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERHOSTNAME_HPP
# define USERHOSTNAME_HPP

#include "IMonitorModule.hpp"

class UserHostName : public IMonitorModule {
private:
	std::vector<std::string>	data;
public:
	UserHostName();
	UserHostName(UserHostName const & obj);
	~UserHostName();
	std::vector<std::string> const & getData(void);
	UserHostName & operator = (UserHostName const & obj);
	void data_reading(void);
};

#endif