/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:52:22 by tsaby             #+#    #+#             */
/*   Updated: 2025/07/09 15:29:20 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook Phonebook;
	std::string command;
	Contact contact;

	std::cout << "Welcome to the PhoneBook application!" << std::endl;
	std::cout << "You can add, search, or exit the application." << std::endl;
	std::cout << "Type 'ADD' to add a contact, 'SEARCH' to search for contacts, or 'EXIT' to exit the application." << std::endl;
	while (true)
	{
		std::cout << "Please enter a command: ";
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add")
		{
			Phonebook.set_info();
		}
		else if (command == "SEARCH" || command == "search")
		{
			Phonebook.get_info();
		}
		else if (command == "EXIT" || command == "exit")
		{
			std::cout << "Exiting the application. Goodbye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}
	return 0;

}
