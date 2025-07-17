#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called PhoneBook" << std::endl;
	this->index = 0;
	this->full = false;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called PhoneBook" << std::endl;
}

int PhoneBook::set_info(void)
{
	std::string input;

	if (this->full == false && this->index < 8)
	{
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "Please enter the contact _info (type 'exit' to stop):" << std::endl;
		if (this->contacts[this->index].fill_contact() == true)
		{
			this->index++;
			if (this->index == 8)
				this->full = true;
			return(0);
		}
		else
			return (-1);
	}
	else if (this->full == true)
	{
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "PhoneBook is full, you can't add more contacts" << std::endl;
		std::cout << "if you want to add more contacts, please delete an existing one first, or the last contact you had created will be replaced by the new one" << std::endl;
		std::cout << "Do you want to continue ? (yes/no)\n Yes for create a new contact or no for back to main menu" << std::endl;
		std::cout << "Type 'yes' or 'no': ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl << "EOF detected. Returning to main menu." << std::endl;
			return (0);
		}
		if (input == "yes" || input == "y")
		{
			this->index = 0;
			this->full = false;
			if (this->contacts[this->index].fill_contact() == true)
			{
				this->index = 8;
				if (this->index == 8)
					this->full = true;
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
	int index;
	std::string input;

	if (this->index == 0)
	{
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "PhoneBook is empty, please add a contact first" << std::endl;
		return;
	}
	else if (this->index > 0)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		for (int i = 1; i <= this->index; i++)
		{
			this->contacts[i -1].get_contact(i,false);
		}
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << std::endl;
		std::cout << "---------------------------------------------->" << std::endl;
		std::cout << "Type the index of the contact you want to view (1-" << this->index << ") ; 0 to exit :  ";
		while(true)
		{
			if (!std::getline(std::cin, input))
			{
				std::cout << std::endl << "EOF detected. Exiting Search Mode..." << std::endl;
				return;
			}
			if (input == "0")
			{
				std::cout << "---------------------------------------------->" << std::endl;
				std::cout << "Exiting Search Mode..." << std::endl;
				return;
			}
			else if (input.length() > 1 || !isdigit(input[0]))
			{
				std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
				std::cout << "---------------------------------------------->" << std::endl;
				std::cout << "Type the index of the contact you want to view (1-" << this->index << "):, 9 for all contact, 0 to exit :  ";
				continue;
			}
			else if (std::atoi(input.c_str()) < 1 || std::atoi(input.c_str()) > this->index)
			{
				std::cout << "\033[31mInvalid input. Please try again.\033[0m" << std::endl;
				std::cout << "---------------------------------------------->" << std::endl;
				std::cout << "Type the index of the contact you want to view (1-" << this->index << "):, 9 for all contact, 0 to exit :  ";
				std::cin.clear();
				continue;
			}
			else
			{
				index = std::atoi(input.c_str());
				if (index > 0)
				{
					// std::cout << "|-----------------------------------------------------------------|" << std::endl;
					// std::cout << "|     Index|First Name| Last Name|  Nickname| Ph.Number|DarkSecret|" << std::endl;
					// std::cout << "|----------|----------|----------|----------|----------|----------|" << std::endl;
					this->contacts[index - 1].get_contact(index,true);
					std::cout << "|-------------------------------------------|----------|----------|" << std::endl;
					std::cout << std::endl;
				}
				return;
			}
		}
	}
}
