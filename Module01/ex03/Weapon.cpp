/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:28:46 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/04 10:03:44 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string type) {
	setType(type);
}

Weapon::~Weapon() {
}

std::string &Weapon::getType() {
	std::string &ret = this->type;
	return (ret);
}

void Weapon::setType(std::string new_type) {
	this->type = new_type;
}
