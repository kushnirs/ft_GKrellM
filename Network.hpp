/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:55:43 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 22:13:34 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
# define NETWORK_HPP

#include "IMonitorModule.hpp"

class Network : public IMonitorModule {
private:
	std::string		data;
	void			activity(void);
public:
	Network();
	Network(Network const & obj);
	~Network();
	std::string const & getData(void);
	Network & operator = (Network const & obj);
	std::string const & data_reading(void);
};

#endif