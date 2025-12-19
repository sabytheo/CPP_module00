/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:52:22 by tsaby             #+#    #+#             */
/*   Updated: 2025/12/19 13:47:54 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook Phonebook;
	std::string command;
	Contact contact;

	std::cout << "---------------------------------------------->" << std::endl;
	std::cout << "Welcome to the PhoneBook application!" << std::endl;
	std::cout << "You can add, search, or exit the application." << std::endl;
	while (true)
	{
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "Type 'ADD' to add a contact, 'SEARCH' to search for contacts, or 'EXIT' to exit the application." << std::endl;
		std::cout << "Please enter a command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl << "EOF detected. Exiting the application. Goodbye!" << std::endl;
			break;
		}
		if (command == "ADD")
		{
			Phonebook.set_info();
		}
		else if (command == "SEARCH")
		{
			Phonebook.search_info();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting the application. Goodbye!" << std::endl;
			break;
		}
		else if (command.length() >= 0 && (command != "ADD" && command != "SEARCH" && command != "EXIT"))
		{
			std::cout << "\033[31mInvalid command. Please try again.\033[0m" << std::endl;
		}
		else
			return (-1);
	}
	return 0;

}
