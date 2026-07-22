/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:45:03 by candre--          #+#    #+#             */
/*   Updated: 2026/07/22 23:50:19 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <set>
# include <string>
# include <sstream>
#include <sys/time.h>

# define GREEN	"\033[32m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define GREY 	"\033[30m"
# define RESET	"\033[0m" 


class PmergeMe
{
	public :
		PmergeMe(char **argv);
		~PmergeMe(void);

		size_t sort_vector(void);
		size_t sort_deque(void);
		size_t FJ_calculator(void);
		std::vector<int> get_vector(void) const;


	private :
		void parse_input(const std::string& arg);
		
		PmergeMe(void);
		PmergeMe(const PmergeMe& to_copy);
		PmergeMe &operator=(const PmergeMe &to_assign);

		std::vector<int>	_vector;
		std::deque<int>		_deque;
		std::set<int>		_seen;
		size_t				_comparisons;

		std::vector<size_t> init_jacobsthal(size_t size) const;

		template<typename Container>
		void create_pairs_members(const Container& sequence, std::vector< std::pair<int, int> >& pair_members, size_t n_pairs);

		template<typename Container>
		void sort_pair_by_max_and_reorder(std::vector< std::pair<int, int> >& pair_members);

		template<typename Container>
		size_t find_maxpair_position(Container &main_chain, int max_value) const;
		
		template<typename Container> size_t
		find_insert_position(Container& main_chain,int value, size_t begin, size_t end);
		
		template<typename Container>
		void insert_pending_value(Container& main_chain, const std::pair<int, int> pair_member);

		template<typename Container>
		void insert_pending_elements(Container& sortedChain, const std::vector<std::pair<int, int> >& valuePair, bool is_impair, int impair_number);

		template<typename Container>
		void build_main_chain(const std::vector< std::pair<int, int> >& valuePairs, Container& sortedChain);
		
		template<typename Container>
		void ford_johnson_algo(Container& sequence);

};

std::ostream &operator<<(std::ostream &ofs, std::vector<int> const &vector);
std::ostream &operator<<(std::ostream &ofs, std::deque<int> const &deque);

#endif