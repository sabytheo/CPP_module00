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

void PhoneBook::set_info(void)
{
	std::string input;

	if (this->full == false && this->index < 8)
	{
		std::cout << "Please enter the contact information (type 'exit' to stop):" << std::endl;
		if (this->contacts[this->index].fill_contact() == true)
		{
			this->index++;
			if (this->index == 8)
				this->full = true;
		}
	}
	else if (this->full == true)
	{
		std::cout << "PhoneBook is full, you can't add more contacts" << std::endl;
		std::cout << "if you want to add more contacts, please delete an existing one first, or the last contact you had created will be replaced by the new one" << std::endl;
		std::cout << "Do you want to continue ? (yes/no)\n Yes for create a new contact or no for back to main menu" << std::endl;
		std::cout << "Type 'yes' or 'no': ";
		std::getline(std::cin, input);
		if (input == "yes" || input == "y")
		{
			this->index = 7;
			this->full = false;
			if (this->contacts[this->index].fill_contact() == true)
			{
				this->index++;
				if (this->index == 8)
					this->full = true;
			}
		}
		else if (input == "no" || input == "n")
		{
			std::cout << "Back to main menu" << std::endl;
			return;
		}
		else
		{
			std::cout << "Invalid input, please try again." << std::endl;
			return;
		}
	}
}

void PhoneBook::get_info(void)
{
	int index;
	std::string input;

	if (this->index == 0)
	{
		std::cout << "PhoneBook is empty, please add a contact first" << std::endl;
		return;
	}
	else if (this->index > 0)
	{
		std::cout << "Type the index of the contact you want to view (1-" << this->index << "):, 9 for all contact, 0 to exit :  ";
		while(true)
		{
			std::getline(std::cin, input);
			if (input == "0")
			{
				std::cout << "Exiting Search Mode..." << std::endl;
				return;
			}
			if (input == "9")
			{
					std::cout << "|-------------------------------------------|" << std::endl;
					std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
					std::cout << "|----------|----------|----------|----------|" << std::endl;
					for (int i = 1; i <= this->index; i++)
					{
						this->contacts[i -1].get_contact(i);
					}
					std::cout << "|-------------------------------------------|" << std::endl;
					return;
			}
			else if (input.length() > 1 || !isdigit(input[0]))
			{
				std::cout << "Invalid input, please try again." << std::endl;
				continue;
			}
			else if (std::atoi(input.c_str()) < 1 || std::atoi(input.c_str()) > this->index)
			{
				std::cout << "Invalid index, please try again." << std::endl;
				std::cout << "Type the index of the contact you want to view (1-" << this->index << "):, 0 to exit :  ";
				std::cin.clear();
				continue;
			}
			else
			{
				index = std::atoi(input.c_str());
				if (index > 0)
				{
					std::cout << "|-------------------------------------------|" << std::endl;
					std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
					std::cout << "|----------|----------|----------|----------|" << std::endl;
					this->contacts[index - 1].get_contact(index);
					std::cout << "|-------------------------------------------|" << std::endl;
				}
				return;
			}
		}
	}
}
