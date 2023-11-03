/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:59 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/03 11:59:12 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(int ac, char **av) {
	std::string	input;
	if (ac != 2) {
		std::cout << "Usage: ./horde <num-of-zombies-in-horde>" << std::endl;
		exit(1);
	}
	input = av[1];
	if (input.empty() || input.find_first_not_of("01234567890") != std::string::npos) {
		std::cout << "Usage: ./horde <num-of-zombies-in-horde>" << std::endl;
		std::cout << "<num-of-zombies-in-horde> should be a positive integer" << std::endl;
		exit(1);
	}
	int	zombie_count = atoi(input.c_str());
	Zombie*	horde = zombieHorde(zombie_count, "Clive");
	for (int i = 0; i < zombie_count; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
