/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:55:43 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 20:45:06 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"

class Cpu : public IMonitorModule {
private:
	std::string		data;
	void			activity(void);
public:
	Cpu();
	Cpu(Cpu const & obj);
	~Cpu();
	std::string const & getData(void);
	Cpu & operator = (Cpu const & obj);
	std::string const & data_reading(void);
};

#endif