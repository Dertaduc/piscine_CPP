#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"
#include <iomanip>

void prompt_instruction(void)
{
	std::cout <<  "WELCOME IN YOUR PHONEBOOK\n\n";
	std::cout << "List of available instructions:\n";
	std::cout << "- ADD : add a contact to the phonebook\n";
	std::cout << "- SEARCH : search a contact into the phonebook\n";
	std::cout << "- EXIT : quit the phonebook\n";
}

int main(void)
{
	phonebook my_phonebook;
	std::string input;

	prompt_instruction();
	while (1)
	{
		std::cout << "Enter your command (SEARCH, ADD, EXIT) : ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return (0);
		}
		if (input.compare("ADD") == 0)
			my_phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
			my_phonebook.print_search();
		else if (input.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "Invalid command, please try again" << std::endl;
	}
	return (0);
}