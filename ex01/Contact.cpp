/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:11:18 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/04/07 09:06:09 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.hpp"
#include "Contact.hpp"
#include <iostream>


/* Constructor & Destructor */

Contact::Contact(void) :
	__firstname		(),
	__lastname		(),
	__nickname		(),
	__phoneNumber	(),
	__darkestSecret	(),
	__dateInput		(0)
{ return; }

Contact::Contact(Contact const &cpy) :
	__firstname		(cpy.GetFirstname()),
	__lastname		(cpy.GetLastname()),
	__nickname		(cpy.GetNickname()),
	__phoneNumber	(cpy.GetPhoneNumber()),
	__darkestSecret	(cpy.GetDarkestSecret()),
	__dateInput		(cpy.GetDateInput())
{ return; }

Contact::~Contact(void){ return; }


/* Accessors | Getters */

std::string	Contact::GetFirstname(void)		const
{ return (this->__firstname); }

std::string	Contact::GetLastname(void)		const
{ return (this->__lastname); }

std::string	Contact::GetNickname(void)		const
{ return (this->__nickname); }

std::string	Contact::GetPhoneNumber(void)	const
{ return (this->__phoneNumber); }

std::string	Contact::GetDarkestSecret(void)	const
{ return (this->__darkestSecret); }

std::time_t	Contact::GetDateInput(void)		const
{ return (this->__dateInput); }


/* Public Methods */

void	Contact::Input(void)
{
	this->__dateInput = time(0);
	if (!(this->__Input("Firstname", this->__firstname)))			return;
	if (!(this->__Input("Lastname", this->__lastname)))				return;
	if (!(this->__Input("Nickname", this->__nickname)))				return;
	if (!(this->__Input("Phone Number", this->__phoneNumber)))		return;
	if (!(this->__Input("Darkest Secret", this->__darkestSecret)))	return;
	return;
}

void	Contact::CopyFrom(Contact const from)
{
	this->__firstname		= from.GetFirstname();
	this->__lastname		= from.GetLastname();
	this->__nickname		= from.GetNickname();
	this->__phoneNumber		= from.GetPhoneNumber();
	this->__darkestSecret	= from.GetDarkestSecret();
	this->__dateInput		= from.GetDateInput();
	return;
}


/* Private Methods */

int	Contact::__Input(char const *msg, std::string &field)
{
	int	nb_retry = NB_RETRY;

	std::cout << msg << " : ";
	while (field.empty())
	{
		getline(std::cin, field);
		--nb_retry;
		if (nb_retry == 0)
		{
			std::cout << "Max retry !" << std::endl;
			this->__Clear();
			return (0);
		}
		if (!field.empty())
			break;
		std::cout << "Field can't be empty ! Please retry ? ";
		field = "";
	}
	return (1);
}

void	Contact::__Clear(void)
{
	this->__dateInput		= 0;
	this->__firstname		= "";
	this->__lastname		= "";
	this->__nickname		= "";
	this->__phoneNumber		= "";
	this->__darkestSecret	= "";
	return;
}
