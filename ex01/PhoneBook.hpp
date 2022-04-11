/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:12:12 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/04/06 22:29:56 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "config.hpp"
# include "Contact.hpp"


class PhoneBook
{
	public:
		/* Constructor & Destructor */
		PhoneBook					(void);
		~PhoneBook					(void);

		/* Methods */
		void	AddContact			(void);
		void	SearchContact		(void)				const;

	private:
		/* Attributes */
		int		__nbEntry;
		Contact	__addrBook[CAPACITY];

		/* Methods */
		void	__PrintContacts		(void)				const;
		void	__PrintAContact		(int index)			const;
		void	__InputIndexContact	(void)				const;
		void	__FmtField			(std::string field)	const;
		int		__GetOlderContact	(void)				const;
};

#endif /* PHONEBOOK_HPP */
