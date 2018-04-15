/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ram.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:55:43 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 18:53:37 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP

#include "IMonitorModule.hpp"

class Ram : public IMonitorModule {
private:
	std::vector<std::string>		data;
	void			activity(void);
public:
	Ram();
	Ram(Ram const & obj);
	~Ram();
	std::vector<std::string> const & getData(void);
	Ram & operator = (Ram const & obj);
	void data_reading(void);
};

#endif