/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:15:16 by tsaby             #+#    #+#             */
/*   Updated: 2025/07/09 15:31:03 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact
{
	private:
			static std::string	name[5];
			std::string		information[11];

			enum info_contact
			{
				FirstName = 0,
				LastName,
				NickName,
				PhoneNumber,
				DarkestSecret,
			};
	public:
			Contact(void);
			~Contact(void);

			bool fill_contact();
			void get_contact(int index);
};

#endif
