/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:10:21 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/04/06 13:11:12 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>


/* App entry */

int	main(void)
{
	std::string	ui("");
	PhoneBook	pb;

	std::cout << "Welcome in your PhoneBook from 80's system !" << std::endl;
	while (ui.find("EXIT") != 0 && !std::cin.eof())
	{
		ui = "";
		std::cout << "> ";
		getline(std::cin, ui);
		if (ui.compare("ADD") == 0)
			pb.AddContact();
		else if (ui.find("SEARCH") == 0)
			pb.SearchContact();
	}
	std::cout << std::endl
		<< "Goodbye but all entries will be lost !" << std::endl;
    return (0);
}
