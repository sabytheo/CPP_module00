/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:15:16 by tsaby             #+#    #+#             */
/*   Updated: 2025/07/17 14:32:17 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdlib>
#include <iomanip>
#include <cstring>
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

			int set_info(void);
			void search_info(void);
};

#endif
