/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:15:16 by tsaby             #+#    #+#             */
/*   Updated: 2025/07/09 15:31:39 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdlib>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
			Contact contacts[8];
			int index;
			bool full;
	public:
			PhoneBook(void);
			~PhoneBook(void);

			void set_info(void);
			void get_info(void);
};

#endif
