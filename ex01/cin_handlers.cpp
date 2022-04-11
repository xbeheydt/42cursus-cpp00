#include "utils.hpp"
#include <iostream>
#include <sstream>


int	utils::cin_int(int &i)
{
	std::string	input;
	int			ret = 0;

	getline(std::cin, input);
	std::stringstream ss(input);
	if (ss >> i)
		ret = 1;
	else
		i = -1;
	return (ret);
}
