#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called PhoneBook" << std::endl;
	this->_index = 0;
	this->_full = false;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called PhoneBook" << std::endl;
}

int PhoneBook::set_info(void)
{
	std::string input;
	static int oldest = 0;
	if (this->_full == false && this->_index < 8)
	{
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "Please enter the contact info " << std::endl;
		if (this->_contacts[this->_index].fill_contact() == true)
		{
			this->_index++;
			if (this->_index == 8)
				this->_full = true;
			return(0);
		}
		else
			return (-1);
	}
	else if (this->_full == true)
	{
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "PhoneBook is full, you can't add more contacts" << std::endl;
		std::cout << "if you want to add more contacts, please delete an existing one first, or first contact you had created will be replaced by the new one" << std::endl;
		std::cout << "Do you want to continue ? (yes/no)\n Yes for create a new contact or no for back to main menu" << std::endl;
		std::cout << "Type 'yes' or 'no': ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl << "EOF detected. Returning to main menu." << std::endl;
			return (0);
		}
		if (input == "yes" || input == "y")
		{
			this->_index = oldest;
			oldest++;
			this->_full = false;
			if (oldest >= 8)
				oldest = 0;
			if (this->_contacts[this->_index].fill_contact() == true)
			{
				this->_index = 8;
				this->_full = true;
			}
			else
				return (-1);
		}
		else if (input == "no" || input == "n")
		{
			std::cout << "---------------------------------------------->" << std::endl;
			std::cout << "Back to main menu" << std::endl;
			return (0);
		}
		else
		{
			std::cout << "---------------------------------------------->" << std::endl;
			std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
			return (0);
		}
	}
	return (0);
}

void PhoneBook::search_info(void)
{
	std::string input;

	std::cout << _index << std::endl;

	if (this->_index == 0)
	{
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "PhoneBook is empty, please add a contact first" << std::endl;
		return;
	}
	else if (this->_index > 0)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		for (int i = 1; i <= this->_index; i++)
		{
			this->_contacts[i -1].get_contact(i);
		}
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << std::endl;
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "Type the index of the contact you want to view (1-" << this->_index << ") ; 0 to exit :  ";
		while(true)
		{
			if (!std::getline(std::cin, input))
			{
				std::cout << std::endl << "EOF detected. Exiting Search Mode..." << std::endl;
				return;
			}
			std::stringstream ss(input);
			int index_search;
			ss >> index_search;
			if (input == "0")
			{
				std::cout << "---------------------------------------------->" << std::endl;
				std::cout << "Exiting Search Mode..." << std::endl;
				return;
			}
			else if (input.length() > 1 || !std::isdigit(input[0]))
			{
				std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
				std::cout << "---------------------------------------------->" << std::endl;
				std::cout << "Type the index of the contact you want to view (1-" << this->_index << "):, 0 to exit :  ";
				continue;
			}
			else if (index_search < 1 || index_search > this->_index)
			{
				std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
				std::cout << "---------------------------------------------->" << std::endl;
				std::cout << "Type the index of the contact you want to view (1-" << this->_index << "):, 0 to exit :  ";
				std::cin.clear();
				continue;
			}
			else
			{
				if (index_search > 0)
				{
					this->_contacts[index_search - 1].get_contact_info(index_search);
				}
				return;
			}
		}
	}
}
