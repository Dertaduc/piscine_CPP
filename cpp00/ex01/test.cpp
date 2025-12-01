#include <iostream>
#include <string>

int	main(void)
{
	std::string str;

	while (1)
	{
		std::getline(std::cin, str);
		if (!std::cin)
			return (1);
		if (str.compare("ADD") == 0)
			std::cout << "IS ADD string" << std::endl;
		else
			std::cout << "NOT ADD string" << std::endl;
	}
	return (0);
}