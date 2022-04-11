/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:12:12 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/04/07 08:57:27 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <ctime>
# include <iostream>


class Contact
{
	public:
		/* Constructor & Destructor */
		Contact						(void);
		Contact						(Contact const &cpy);
		~Contact					(void);

		/* Accessors | Getters */
		std::string	GetFirstname	(void)	const;
		std::string	GetLastname		(void)	const;
		std::string	GetNickname		(void)	const;
		std::string	GetPhoneNumber	(void)	const;
		std::string	GetDarkestSecret(void)	const;
		std::time_t	GetDateInput	(void)	const;

		/* Methods */
		void		Input			(void);
		void		CopyFrom		(Contact const from);

	private:
		/* Attributes */
		std::string	__firstname;
		std::string	__lastname;
		std::string	__nickname;
		std::string	__phoneNumber;
		std::string	__darkestSecret;
		std::time_t	__dateInput;

		/* Methods */
		int			__Input			(char const *msg, std::string &field);
		void		__Clear			(void);
};

#endif /* CONTACT_HPP */
