#include "Contact.hpp"



Contact::Contact(void)
{
	int i;

	std::cout << "Constructor called Contact" << std::endl;
	for (i = FirstName; i <= DarkestSecret;i++)
	{
		this->information[i] = std::string();
		return;
	}
}

Contact::~Contact()
{
	std::cout << "Destructor called Contact" << std::endl;
}

std::string Contact::name[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

bool	Contact::fill_contact()
{
	int i;

	for(i = FirstName; i <= DarkestSecret;i++)
	{
		std::cout << "Would you mind fill this form : let's start with " << Contact::name[i] << std::endl;
		std::getline(std::cin,this->information[i]);
	}
	std::cout << "Contact created succefully" << std::endl;
	return (true);
}

void Contact::get_contact(int index)
{
	std::cout << "|" << std::setw(10) << index;
	for (int i = FirstName; i <= NickName; i++)
	{
		std::cout << "|";
		if (this->information[i].length() > 10)
			std::cout << this->information[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->information[i];
	}
	std::cout << "|" << std::endl;
}
