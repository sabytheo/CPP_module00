/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:15:16 by tsaby             #+#    #+#             */
/*   Updated: 2025/12/19 18:08:06 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>



class Contact
{
	private:
			static std::string	_name[5];
			std::string		_info[11];

			enum _info_contact
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
			void get_contact(int index, bool full);
			void get_contact_info(int index);
};

#endif
