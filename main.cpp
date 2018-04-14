/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:59:51 by skushnir          #+#    #+#             */
/*   Updated: 2018/04/14 23:34:12 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserHostName.hpp"
#include "TimeData.hpp"
#include "Info.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"
#include "Network.hpp"
#include "Graphic.hpp"

int main()
{
    UserHostName name;
    name.data_reading();
    std::cout << name.getData();
    TimeData time;
    time.data_reading();
    std::cout << time.getData();
    Info info;
    info.data_reading();
    std::cout << info.getData();
    Cpu cpu;
    cpu.data_reading();
    std::cout << cpu.getData();
    Ram ram;
    ram.data_reading();
    std::cout << ram.getData();
    Network network;
    network.data_reading();
    std::cout << network.getData();
    Graphic start;
    start.display_module(name.getData());
    return 0;
}
