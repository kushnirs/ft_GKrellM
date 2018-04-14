/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:17:41 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 19:35:57 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <ncurses.h>

class IMonitorModule {
public:
	virtual std::string const & data_reading() = 0;
};

#endif