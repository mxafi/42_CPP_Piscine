/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:56:09 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/04 11:03:08 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Replacer {
	private:
	public:
		Replacer(void);
		~Replacer(void);
		int run(std::string filename, std::string s1, std::string s2);
};
