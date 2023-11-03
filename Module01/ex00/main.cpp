/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:55:26 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/03 10:57:48 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void) {
	Zombie	*zomb = newZombie("Newt");
	randomChump("Chumpy");
	zomb->announce();
	zomb->announce();
	delete zomb;
	return 0;
}
