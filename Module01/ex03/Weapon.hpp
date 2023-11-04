/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:24:11 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/04 10:03:32 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string	type;
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		std::string	&getType(void);
		void		setType(std::string new_type);
};

#endif
