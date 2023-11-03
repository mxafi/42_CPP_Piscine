/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:00:11 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/03 11:32:04 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
private:
	std::string	name;
public:
	Zombie(void);
	Zombie(std::string zombie_name);
	~Zombie(void);
	void	announce(void);
	void	setName(std::string zombie_name);
};

#endif
