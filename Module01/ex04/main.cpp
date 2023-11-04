/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:55:55 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/04 11:57:56 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Replacer.hpp"

int main(int argc, char **argv)
{
	Replacer replacer;
	int exit_value = SUCCESS;

	if (argc != 4)
	{
		std::cout << "Wrong amount of arguments." << std::endl;
		exit_value = FAILURE;
	}
	if (exit_value == SUCCESS) {
		replacer.setFilename(argv[1]);
		replacer.setS1(argv[2]);
		replacer.setS2(argv[3]);
		exit_value = replacer.run();
	}
	if (exit_value == FAILURE)
		std::cout << "Usage: ./replacer <filename> <string_to_replace> <replacement_string>" << std::endl;
	return exit_value;
}
