/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:14:27 by candre--          #+#    #+#             */
/*   Updated: 2026/07/13 19:14:28 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	parse_blockchainfile("./data.csv");
}
BitcoinExchange::~BitcoinExchange(void){}

void BitcoinExchange::parse_blockchainfile(const std::string& path)
{
	std::ifstream	file(path.c_str());
	std::string		line;
	size_t 			separator_pos;
	std::string		date;
	std::string		amount;

	if (!file.is_open())
		throw (std::runtime_error("Error while loading data : cannot open file " + path));

	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw (std::runtime_error("Error while loading data : invalid columns header"));	
	while (std::getline(file, line))
	{
		separator_pos = line.find(',');
		if (separator_pos == std::string::npos)
		{
			if (line.size() != 0)
				throw (std::runtime_error("Error while loading data : separator not found"));
			else
				continue;
		}
		date = line.substr(0, separator_pos);
		amount = line.substr(separator_pos + 1);
		if (check_valid_date(date) && check_valid_amount(amount))
		{
			if (_blockchain.find(date) != _blockchain.end())
				throw (std::runtime_error("Error while loading data: too many definition for " + date));
			else
				std::istringstream(amount) >> _blockchain[date];
		}
		else
			throw(std::runtime_error("Error while loading data: invalid format for date or amount"));
	}
	if (_blockchain.empty())
		throw (std::runtime_error("Error while loading data: empty file"));
}

bool BitcoinExchange::check_valid_date(const std::string& date) const
{
	std::istringstream ss(date);
	int					year, month, day;
	char				sep1, sep2;
	char				trailing;

	ss >> std::noskipws;
	if (!(ss >> year >> sep1 >> month >> sep2 >> day))
		return (false);
	if (sep1 != '-' || sep2 != '-')
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1)
		return (false);
	if (ss >> trailing)
		return (false);

	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool is_bissextile = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (is_bissextile)
		days_in_month[1] = 29;
	if (day > days_in_month[month - 1])
		return (false);
	return (true);
	
}

bool BitcoinExchange::check_valid_amount(const std::string& amount) const
{
	std::istringstream	ss(amount);
	float				value;
	char				end_str;
	
	if (!(ss >> value))
		return (false);
	if (ss >> end_str)
		return (false);
	return (true);
}

std::string BitcoinExchange::trim(const std::string& to_trim) const
{
	size_t begin;
	size_t end;

	begin = to_trim.find_first_not_of("\t\n ");
	if (begin == std::string::npos)
		return ("");
	end = to_trim.find_last_not_of("\t\n ");
	return (to_trim.substr(begin, end - begin + 1));
}

BitcoinExchange::e_line_error BitcoinExchange::process_line(const std::string& date, const std::string& exch_rate, float& result) const
{
	std::string	blockchain_date;

	if (!check_valid_date(date))
		return (BAD_DATE);
	if (!check_valid_amount(exch_rate))
		return (BAD_AMOUNT);
	std::istringstream(exch_rate) >> result;
	if (result < 0)
		return (NEGATIVE);
	if (result > 1000)
		return (TOO_LARGE);
	blockchain_date = select_date(date);
	if (blockchain_date.empty())
		return (NO_DATA);
	result = _blockchain.at(blockchain_date) * result;
	return (OK);
}

void BitcoinExchange::parse_and_process_input(const std::string& path) const
{
	std::ifstream	file(path.c_str());
	std::string		line;
	std::string		date;
	std::string		exch_rate;
	size_t			separator_pos;
	float			result;

	if (!file.is_open())
		throw (std::runtime_error("Error while loading data : cannot open file " + path));
	
	std::getline(file, line);
	if (line != "date | value")
		throw (std::runtime_error("Error while loading data : invalid columns header"));
	while (std::getline(file, line))
	{
		separator_pos = line.find('|');
		if (separator_pos == std::string::npos)
		{
			if (line.size() != 0)
				std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = trim(line.substr(0, separator_pos));
		exch_rate = trim(line.substr(separator_pos + 1));
		switch (process_line(date, exch_rate, result))
		{
			case OK:      std::cout << date << " => " << exch_rate << " = " << result << std::endl; break;
			case BAD_DATE:   std::cout << "Error: bad input => " << date << std::endl; break;
			case BAD_AMOUNT: std::cout << "Error: bad input => " << exch_rate << std::endl; break;
			case NEGATIVE:   std::cout << "Error: not a positive number." << std::endl; break;
			case TOO_LARGE:  std::cout << "Error: too large number." << std::endl; break;
			case NO_DATA:    std::cout << "Error: no data => " << date << std::endl; break;
		}
	}
}

std::string BitcoinExchange::select_date(const std::string& target_date) const
{
	std::map<std::string, float>::const_iterator it = _blockchain.lower_bound(target_date);

	if (it != _blockchain.end() && it->first == target_date)
		return (it->first);
	if (it == _blockchain.begin())
		return ("");
	--it;
	return (it->first);
}