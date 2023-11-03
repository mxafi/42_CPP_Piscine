/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:59 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/03 13:04:17 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string		&stringREF = string;
	std::cout << "        address of string: " << &string << std::endl;
	std::cout << "address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "address held by stringREF: " << &stringREF << std::endl;
	std::cout << "           value of string: " << string << std::endl;
	std::cout << "pointed value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "pointed value of stringREF: " << stringREF << std::endl;
	return 0;
}
