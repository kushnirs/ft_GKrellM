/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:59:51 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/15 15:37:30 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserHostName.hpp"
#include "TimeData.hpp"
#include "Info.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"
#include "Network.hpp"
#include "Graphic.hpp"
#include "Gkrellm.hpp"

int main(int ac, char **av)
{
    Gkrellm (ac, av);
    return 0;
}
