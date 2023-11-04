/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:56:09 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/04 13:04:16 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# define FAILURE 1
# define SUCCESS 0

# include <string>
# include <iostream>
# include <fstream>

class Replacer {
	private:
		std::string filename_;
		std::string s1_;
		std::string s2_;
		std::string file_as_string_;
	public:
		Replacer(void);
		~Replacer(void);
		void setFilename(char* filename);
		void setS1(char* s1);
		void setS2(char* s2);
		int run(void);
};

#endif