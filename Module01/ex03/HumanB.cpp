/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:55:07 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/04 10:33:51 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: name(name), weapon(NULL) {
}

HumanB::~HumanB(void) {
}

void HumanB::attack(void) {
	if (this->weapon == NULL)
		std::cout << this->name << " attacks with their fists" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon) {
	this->weapon = &new_weapon;
}
