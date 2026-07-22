/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:54:28 by candre--          #+#    #+#             */
/*   Updated: 2026/07/23 00:15:54 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "iostream"

void printPairs(const std::vector< std::pair<int, int> >& pair_members)
{
	for (size_t i = 0; i < pair_members.size(); ++i)
		std::cout << "(" << pair_members[i].first << "," << pair_members[i].second << ") ";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(char **argv)
{
	_comparisons = 0;
	for (int i = 0; argv[i] != NULL; i++)
		parse_input(argv[i]);
}

size_t PmergeMe::FJ_calculator()
{
	size_t	sum = 0;
	size_t	k = 1;

	while (k <= _seen.size())
	{
		double value = (3.0 / 4.0) * static_cast<double>(k);
		if (value > 0)
			sum += static_cast<size_t>(ceil(log2(value + 1e-9)));
		++k;
	}
	return (sum);
}

PmergeMe::~PmergeMe(void){}


void PmergeMe::parse_input(const std::string& arg)
{
	unsigned long 		tmp_ulong;
	char				*end_str;

	if (arg.empty())
		throw (std::runtime_error("Error"));
	errno = 0;
	tmp_ulong = strtoul(arg.c_str(), &end_str, 10);
	if (errno == ERANGE || *end_str != '\0' || tmp_ulong > INT_MAX || tmp_ulong < 0)
		throw (std::runtime_error("Error"));

	int value = static_cast<int>(tmp_ulong);
	if (!_seen.insert(value).second)
		throw (std::runtime_error("Error"));
	_vector.push_back(value);
	_deque.push_back(value);
}



template<typename Container> void PmergeMe::create_pairs_members(const Container& sequence, std::vector< std::pair<int, int> >& pair_members, size_t n_pairs)
{
	for (size_t pair_index = 0; pair_index < n_pairs; ++pair_index)
	{
		_comparisons++;
		if (sequence[2 * pair_index] < sequence[2 * pair_index + 1])
			pair_members.push_back(std::make_pair(sequence[2 * pair_index], sequence[2 * pair_index + 1]));
		else
			pair_members.push_back(std::make_pair(sequence[2 * pair_index + 1], sequence[2 * pair_index]));
	}
}


template<typename Container>
void PmergeMe::build_main_chain(const std::vector< std::pair<int, int> >& pair_members, Container& sortedChain)
{
    if (!pair_members.empty())
        sortedChain.push_back(pair_members[0].first);

    for (size_t pairIndex = 0; pairIndex < pair_members.size(); ++pairIndex)
        sortedChain.push_back(pair_members[pairIndex].second);
}


template<typename Container> void PmergeMe::sort_pair_by_max_and_reorder(std::vector< std::pair<int, int> >& pair_members)
{
	if (pair_members.size() <= 1)
		return;

	Container bigger_elems;
	for (size_t pair_index = 0; pair_index < pair_members.size(); ++pair_index)
		bigger_elems.push_back(pair_members[pair_index].second);
	
	ford_johnson_algo(bigger_elems);
	
	std::vector< std::pair<int, int> > ordered_pairs(pair_members.size());
	std::vector<bool> pair_already_used(pair_members.size(), false);

	for (size_t bigger_index = 0; bigger_index < bigger_elems.size(); ++bigger_index)
	{
		for (size_t pair_index = 0; pair_index < pair_members.size(); ++pair_index)
		{
			if (!pair_already_used[pair_index] && pair_members[pair_index].second == bigger_elems[bigger_index])
			{
				ordered_pairs[bigger_index] = pair_members[pair_index];
				pair_already_used[pair_index] = true;
				break ;
			}
		}
	}
	pair_members = ordered_pairs;
}

std::vector<size_t> PmergeMe::init_jacobsthal(size_t size) const 
{
	std::vector<size_t>	jacobsthal_suite;
	size_t				penultimate = 1;
	size_t				last = 1;
	size_t				current;
	
	for (size_t index = 0; index < size; ++index)
	{
		if (index < 2)
			jacobsthal_suite.push_back(1);
		else
		{
			current = last + 2 * penultimate;
			jacobsthal_suite.push_back(current);
			penultimate = last;
			last = current; 
		}
	}
	return (jacobsthal_suite);
}

template<typename Container> size_t PmergeMe::find_maxpair_position(Container &main_chain, int max_value) const
{
	for (size_t chain_index = 0; chain_index < main_chain.size(); ++chain_index)
	{
		if (main_chain[chain_index] == max_value)
			return (chain_index);
	}
	return (main_chain.size());
}

template<typename Container> size_t PmergeMe::find_insert_position(Container& main_chain, int value, size_t begin, size_t end)
{
	size_t middle;

	while (begin < end)
	{
		middle = begin +(end - begin) / 2;
		_comparisons++;
		if (main_chain[middle] < value)
			begin = middle + 1;
		else
			end = middle;
	}
	return (begin);
}

template<typename Container> void PmergeMe::insert_pending_value(Container& main_chain, const std::pair<int, int> pair_member)
{
	size_t search_limit;
	size_t insert_index;

	search_limit = find_maxpair_position(main_chain, pair_member.second);
	insert_index = find_insert_position(main_chain, pair_member.first, 0, search_limit);
	main_chain.insert(main_chain.begin() + insert_index, pair_member.first);
}

template<typename Container> void PmergeMe::insert_pending_elements(Container& main_chain, const std::vector< std::pair<int, int> >& pair_members, bool is_impair, int impair_number)
{
	size_t total_slots;
	
	if (is_impair)
		total_slots = pair_members.size() + 1;
	else
		total_slots = pair_members.size();

	if (total_slots <= 1)
		return;
	
	std::vector<size_t>	jacobsthal_suite = init_jacobsthal(total_slots + 2);
	std::vector<bool>	already_inserted(total_slots, false);
	already_inserted[0] = true;
	size_t	currentJacob_number;
	size_t	previousJacob_number;
	size_t	index_pair;
	for (size_t jacob_index = 2; jacob_index < jacobsthal_suite.size(); ++jacob_index)
	{
		currentJacob_number = jacobsthal_suite[jacob_index];
		previousJacob_number = jacobsthal_suite[jacob_index - 1];
		for (size_t pos = std::min(currentJacob_number, total_slots); pos > previousJacob_number && pos > 0; --pos)
		{
			index_pair = pos - 1;
			if (index_pair < total_slots && !already_inserted[index_pair])
			{
				if (index_pair < pair_members.size())
					insert_pending_value(main_chain, pair_members[index_pair]);
				else
				{
					size_t insert_index = find_insert_position(main_chain, impair_number, 0, main_chain.size());
					main_chain.insert(main_chain.begin() + insert_index, impair_number);
				}
				already_inserted[index_pair] = true;
			}
		}
	}
	for (index_pair = 1; index_pair < total_slots; ++index_pair)
	{
		if (!already_inserted[index_pair])
		{
			if (index_pair < pair_members.size())
				insert_pending_value(main_chain, pair_members[index_pair]);
			else
			{
				size_t insert_index = find_insert_position(main_chain, impair_number, 0, main_chain.size());
				main_chain.insert(main_chain.begin() + insert_index, impair_number);
			}
		}
	}
}




template<typename Container> void PmergeMe::ford_johnson_algo(Container& sequence)
{
	switch (sequence.size())
	{
	case 0:
	case 1:
		return;
	case 2:
		_comparisons++;
		if (sequence[0] > sequence[1])
			std::swap(sequence[0], sequence[1]);
		return;
	case 3:
		_comparisons++;
		if (sequence[0] > sequence[1])
			std::swap(sequence[0], sequence[1]);
		
		_comparisons++;
		if (sequence[1] > sequence[2])
		{
			std::swap(sequence[1], sequence[2]);
			_comparisons++;
			if (sequence[0] > sequence[1])
				std::swap(sequence[0], sequence[1]);
		}
		return;
	default:
		break;
	}

	size_t n_pairs;
	int impair_number;
	bool is_impair_sequence = false;
	
	if (sequence.size() % 2 != 0)
	{
		is_impair_sequence = true;
		impair_number = sequence.back();
	}

	n_pairs = sequence.size() / 2;

	std::vector < std::pair<int, int> > pair_members;
	pair_members.reserve(n_pairs);
	create_pairs_members(sequence, pair_members, n_pairs);
	sort_pair_by_max_and_reorder<Container>(pair_members);

	Container main_chain;
	build_main_chain(pair_members, main_chain);
	insert_pending_elements(main_chain, pair_members, is_impair_sequence, is_impair_sequence ? impair_number : 0);
	sequence = main_chain;
}

std::vector<int> PmergeMe::get_vector(void) const
{
	return (_vector);
}

size_t	get_time_micro(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000000) + tv.tv_usec;
	return (time);
}


size_t PmergeMe::sort_vector(void)
{
	size_t start_time;
	size_t end_time;
	_comparisons = 0;

	start_time = get_time_micro();
	ford_johnson_algo(_vector);
	end_time = get_time_micro();
	std::cout << "After vector: " << _vector << std::endl;
	std::cout << YELLOW << "Time to sort vector : " << end_time - start_time << "us" << RESET << std::endl;
	if (_comparisons <= FJ_calculator())
		std::cout << GREEN << "Nb comparison : " << _comparisons <<  " : OK" << RESET << std::endl;
	else
		std::cout << RED << "Nb comparison : " << _comparisons << " : NOT OK" << RESET << std::endl;
	return (end_time - start_time);
}

size_t PmergeMe::sort_deque(void)
{
	size_t start_time;
	size_t end_time;
	_comparisons = 0;

	start_time = get_time_micro();
	ford_johnson_algo(_deque);
	end_time = get_time_micro();
	std::cout << "After deque: " << _deque << std::endl;
	std::cout << YELLOW  << "Time to sort deque : " << end_time - start_time << "us" << RESET << std::endl;
	if (_comparisons <= FJ_calculator())
		std::cout << GREEN << "Nb comparison : " << _comparisons <<  " : OK" << RESET << std::endl;
	else
		std::cout << RED << "Nb comparison : " << _comparisons << " : NOT OK" << RESET << std::endl;
	return (end_time - start_time);
}


std::ostream &operator<<(std::ostream &ofs, std::vector<int> const &vector)
{
	for (std::vector<int>::const_iterator i = vector.begin(); i != vector.end(); i++)
	{
		ofs << *i << " ";
	}
	return (ofs);
}

std::ostream &operator<<(std::ostream &ofs, std::deque<int> const &deque)
{
	for (std::deque<int>::const_iterator i = deque.begin(); i != deque.end(); i++)
	{
		ofs << *i << " ";
	}
	return (ofs);
}