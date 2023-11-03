/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:08:36 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/03 11:41:44 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cout << "You sneaky sneky snek. No Horde for you!" << std::endl;
		exit(1);
	}
	Zombie*	array = new Zombie[N];
	for (int i = 0; i < N; i++)
		array[i].setName(name);
	return array;
}
