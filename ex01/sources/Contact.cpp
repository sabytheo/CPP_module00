#include "Contact.hpp"

Contact::Contact(void)
{
	int i;

	std::cout << "Constructor called Contact" << std::endl;
	for (i = FirstName; i <= DarkestSecret;i++)
	{
		this->_info[i] = std::string();
		return;
	}
}

Contact::~Contact()
{
	std::cout << "Destructor called Contact" << std::endl;
}

std::string Contact::_name[5] =
{
	"\033[32mFirst Name\033[0m",
	"\033[32mLast Name\033[0m",
	"\033[32mNickname\033[0m",
	"\033[32mPhone Number\033[0m",
	"\033[32mDarkest Secret\033[0m"
};

bool	Contact::fill_contact()
{
	int i;

	for(i = FirstName; i <= DarkestSecret;)
	{
		std::cout << Contact::_name[i] << " : --> ";
		if (!std::getline(std::cin,this->_info[i]))
		{
			std::cout << std::endl << "EOF detected. Contact creation cancelled." << std::endl;
			return (false);
		}
		if(this->_info[i].empty() == true)
		{
			std::cout << "\033[31mInvalid input, args cannot be empty.Please,retry.\033[0m" << std::endl;
			std::cout << "---------------------------------------------->" << std::endl;
			continue;
		}
		if (this->_info[i].find('\x1b') != std::string::npos)
		{
			std::cout << "\033[31mEchapped char are not allowed. Please retry.\033[0m" << std::endl;
			std::cout << "---------------------------------------------->" << std::endl;
			continue;
		}
		if (this->_info[i].find('\t') != std::string::npos)
		{
			std::cout << "\033[31mTabulations not allowed. Please retry.\033[0m" << std::endl;
			std::cout << "---------------------------------------------->" << std::endl;
			continue;
		}
		i++;
	}
	std::cout << "Contact created succefully" << std::endl;
	return (true);
}

void Contact::get_contact(int index, bool full)
{
	std::cout << "|" << std::setw(10) << index;
	if (full == true)
	{
		for (int i = FirstName; i <= DarkestSecret; i++)
		{
			std::cout << "|";
			if (this->_info[i].length() > 10)
				std::cout << this->_info[i];
			else
				std::cout << std::setw(10) << this->_info[i];
		}
		std::cout << "|" << std::endl;
	}
	else
	{
		for (int i = FirstName; i <= NickName; i++)
		{
			std::cout << "|";
			if (this->_info[i].length() > 10)
				std::cout << this->_info[i].substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << this->_info[i];
		}
		std::cout << "|" << std::endl;
	}
}

void Contact::get_contact_info(int index)
{
	std::cout << "|-----------------------------------------------------------------|" << std::endl;
	std::cout << "  You have choosen the index numbered " << index << std::endl;
	std::cout << "|-----------------------------------------------------------------|" << std::endl;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "| ";
		std::cout << this->_name[i] << std::endl;
		std::cout << "|-----------------------------------------------------------------|" << std::endl;
		std::cout << ":  ";
		std::cout << this->_info[i] << std::endl;
		if ( i != DarkestSecret)
			std::cout << "|-----------------------------------------------------------------|" << std::endl;
	}
	std::cout << "|-----------------------------------------------------------------|" << std::endl << std::endl;
}
