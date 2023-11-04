/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:00:54 by malaakso          #+#    #+#             */
/*   Updated: 2023/11/04 13:34:24 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer() {
}

Replacer::~Replacer() {
}

void Replacer::setFilename(char* filename) {
	this->filename_ = filename;
}
void Replacer::setS1(char* s1) {
	this->s1_ = s1;
}
void Replacer::setS2(char* s2) {
	this->s2_ = s2;
}

int Replacer::run() {

	if (this->s1_.empty() || this->s2_.empty()) {
		std::cout << "The string cannot be empty." << std::endl;
		return FAILURE;
	}

	std::ifstream infile(this->filename_);
	if (!infile.good() || !infile.is_open()) {
		std::cout << "The input file is no good." << std::endl;
		return FAILURE;
	}
	std::string line;
	while (infile.good()) {
		std::getline(infile, line);
		this->file_as_string_.append(line);
		if (!infile.eof())
			this->file_as_string_.push_back('\n');
	}
	infile.close();

	std::ofstream outfile(this->filename_.append(".replace"));
	if (!outfile.good() || !outfile.is_open()) {
		std::cout << "The output file is no good. (no permissions?)" << std::endl;
		return FAILURE;
	}

	size_t idx = 0;
	size_t s2_len = this->s2_.length();
	idx = this->file_as_string_.find(this->s1_);
	while (idx != std::string::npos) {
		this->file_as_string_.erase(idx, this->s1_.length());
		this->file_as_string_.insert(idx, this->s2_);
		idx = this->file_as_string_.find(this->s1_, idx + s2_len);
	}
	outfile << this->file_as_string_;
	return SUCCESS;
}
