/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:17:41 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 19:25:19 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <vector>
#include <ncurses.h>

class IMonitorModule {
public:
	virtual void data_reading() = 0;
	virtual std::vector<std::string> const & getData(void) = 0;
};

#endif