#include <iostream>

void	megaphone(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}


int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < argc)
	{
		megaphone(argv[i]);
		std::cout << argv[i];
		i += 1;
	}
	std::cout << std::endl;
	return (0);
}
