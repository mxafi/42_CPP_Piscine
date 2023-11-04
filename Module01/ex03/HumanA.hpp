/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:36:10 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/04 10:22:05 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon &weapon;
		std::string name;
	public:
		HumanA(std::string human_name, Weapon &initial_weapon);
		~HumanA(void);
		void attack(void);
};

#endif
