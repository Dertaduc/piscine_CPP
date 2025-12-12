/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:08:48 by candre--          #+#    #+#             */
/*   Updated: 2025/12/10 22:01:45 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool readfile(const char *filename, std::string& file_content)
{
	std::ifstream		ifs;
	std::stringstream	tmp_stream;
	
	ifs.open(filename);
	if (!ifs)
	{
		std::cerr << "Fail to open file : " << filename << "\n";
		return (false);
	}
	tmp_stream << ifs.rdbuf();
	file_content = tmp_stream.str();
	return (true);
}

void	replace_occur(std::string& file_content, const std::string s1, const std::string s2)
{
	std::size_t	found;
	std::string	before;
	std::string after;

	found = file_content.find(s1);
	while (found != std::string::npos)
	{
		file_content.erase(found, s1.length());
		file_content.insert(found, s2);
		found = found + s2.length();
		found = file_content.find(s1, found);
	}
}

bool	write_outfile(const std::string file_content, const std::string infile_name)
{
	std::string		outfile_name;
	std::ofstream 	outfile_stream;

	outfile_name = infile_name + ".replace";
	outfile_stream.open(outfile_name.c_str(), std::ofstream::out);
	if (!outfile_stream)
	{
		std::cerr << "Fail to open or create : " << outfile_name << "\n";
		return (false);
	}
	outfile_stream << file_content;
	return (true);
}

int main(int argc, char *argv[])
{

	std::string			file_content;

	if (argc != 4)
	{
		std::cerr << "Wrong usage : <binary> <filename> <str1> <str2>\n";
		return (0);
	}
	if (readfile(argv[1], file_content) == false)
		return (1);
	replace_occur(file_content, argv[2], argv[3]);
	write_outfile(file_content, argv[1]);
}
