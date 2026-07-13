/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:53:10 by candre--          #+#    #+#             */
/*   Updated: 2026/07/13 18:30:39 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange 
{
	public :
		enum e_line_error {
			OK,
			BAD_DATE,
			BAD_AMOUNT,
			NEGATIVE,
			TOO_LARGE,
			NO_DATA
		};

		BitcoinExchange();
		~BitcoinExchange();

		void parse_and_process_input(const std::string& path) const;
	private :
		void 			parse_blockchainfile(const std::string& path);
		bool			check_valid_amount(const std::string& amount) const;
		bool			check_valid_date(const std::string& date) const;
		std::string		select_date(const std::string& target_date) const;
		std::string		trim(const std::string& to_trim) const;
		e_line_error	process_line(const std::string& date, const std::string& exch_rate, float& result) const;
		std::map<std::string, float> _blockchain;

		BitcoinExchange &operator=(const BitcoinExchange &to_assign);
		BitcoinExchange(const BitcoinExchange &to_copy);	
	
};

#endif