/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:12:12 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/04/07 10:53:20 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.hpp"
#include "utils.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


/* Constructor & Destructor */

PhoneBook::PhoneBook(void) :
	__addrBook	{Contact()},
	__nbEntry	(0)
{ return; }

PhoneBook::~PhoneBook(void){ return;}


/* Public Methods */

void	PhoneBook::AddContact(void)
{
	if (this->__nbEntry < CAPACITY)
	{
		this->__addrBook[this->__nbEntry].Input();
		if (this->__addrBook[this->__nbEntry].GetDateInput() == 0) return;
		this->__nbEntry++;
	}
	else
	{
		Contact	c;
		int		old_index = 0;

		c.Input();
		if (c.GetDateInput() != 0)
		{
			old_index = this->__GetOlderContact();
			this->__addrBook[old_index].CopyFrom(c);
		}
	}
	return;
}

void	PhoneBook::SearchContact(void) const
{
	if (this->__nbEntry > 0)
	{
		this->__PrintContacts();
		this->__InputIndexContact();
	}
	else
		std::cout << "No entry ..." << std::endl;
	return;
}


/* Private Methods */

void	PhoneBook::__PrintContacts(void) const
{
	for (int i = 0; i < this->__nbEntry; i++)
	{
		this->__FmtField(std::to_string(i));
		this->__FmtField(this->__addrBook[i].GetFirstname());
		this->__FmtField(this->__addrBook[i].GetLastname());
		this->__FmtField(this->__addrBook[i].GetNickname());
		this->__FmtField(this->__addrBook[i].GetPhoneNumber());
		this->__FmtField(this->__addrBook[i].GetDarkestSecret());
		std::cout << "|" << std::endl;
	}
	return;
}

void	PhoneBook::__PrintAContact(int index) const
{
	std::cout
		<< this->__addrBook[index].GetFirstname()		<< std::endl
		<< this->__addrBook[index].GetLastname()		<< std::endl
		<< this->__addrBook[index].GetNickname()		<< std::endl
		<< this->__addrBook[index].GetPhoneNumber()		<< std::endl
		<< this->__addrBook[index].GetDarkestSecret()	<< std::endl;
	return;
}

void	PhoneBook::__InputIndexContact(void) const
{
	int	index		= -1;
	int	nb_retry	= NB_RETRY;

	std::cout << "Select a contact by index ? ";
	while (!(utils::cin_int(index))	|| index < 0 || index >= this->__nbEntry)
	{
		nb_retry--;
		if (nb_retry == 0)
		{
			std::cout << "Max retry !" << std::endl;
			return;
		}
		std::cout << "Bad entry ! Please retry ? ";
	}
	this->__PrintAContact(index);
	return;
}

void	PhoneBook::__FmtField(std::string field) const
{
	std::cout << "|";
	if (field.size() > FIELD_SIZE)
	{
		field.resize(FIELD_SIZE - 1);
		field += ".";
	}
	std::cout << std::setw(FIELD_SIZE) << field;
	return;
}

int	PhoneBook::__GetOlderContact(void) const
{
	int			index = 0;
	std::time_t	older = this->__addrBook[0].GetDateInput();

	for (int i = 1; i < CAPACITY; i++)
	{
		if (older > this->__addrBook[i].GetDateInput())
		{
			index = i;
			older = this->__addrBook[i].GetDateInput();
		}
	}
	return (index);
}
