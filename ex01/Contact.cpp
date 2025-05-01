/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:33:45 by mganchev          #+#    #+#             */
/*   Updated: 2025/05/01 19:20:57 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : index(-1) {}

void    Contact::setIndex(int i)
{
    this->index = i;
}

int Contact::getIndex() const
{
    return this->index;
}

std::string Contact::getFirstName() const
{
    return this->firstName;
}

std::string Contact::getLastName() const
{
    return this->lastName;
}

std::string Contact::getNickname() const
{
    return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}

bool Contact::isEmpty()
{
    return firstName.empty() && lastName.empty() && nickname.empty() && phoneNumber.empty();
}

bool Contact::stringValid(const std::string& text) const
{
    for (size_t i = 0; i < text.length(); i++)
        if (!std::isalnum(text[i]) && !std::isspace(text[i]))
            return false;
    return true;
}

bool Contact::phoneValid(const std::string& phoneNo) const
{
    for (size_t i = 0; i < phoneNo.length(); i++)
        if (!std::isdigit(phoneNo[i]))
            return false;
    return true;
}

void Contact::setAttributes()
{
    do
    {
        std::cout << "First Name: ";
        std::cin.ignore();
        std::getline(std::cin, this->firstName);
        if (this->firstName.empty())
            std::cerr << "First Name field can't be empty." << std::endl;
        else if (!stringValid(this->firstName))
            std::cerr << "Invalid first name." << std::endl;
    } while (this->firstName.empty() || !stringValid(this->firstName));
    do 
    {
        std::cout << "Last Name: ";
        std::getline(std::cin, this->lastName);
        if (this->lastName.empty())
            std::cerr << "Last Name field can't be empty." << std::endl;
        else if (!stringValid(this->lastName))
            std::cerr << "Invalid last name." << std::endl;
    } while (this->lastName.empty() || !stringValid(this->lastName));
    do 
    {
        std::cout << "Nickname: ";
        std::getline(std::cin, this->nickname);
        if (this->nickname.empty())
            std::cerr << "Nickname field can't be empty." << std::endl;
    } while (this->nickname.empty());
    do 
    {
        std::cout << "Phone Number: ";
        std::getline(std::cin, this->phoneNumber);
        if (this->phoneNumber.empty())
            std::cerr << "Phone Number field can't be empty." << std::endl;
        else if (!phoneValid(this->phoneNumber))
            std::cerr << "Invalid phone number." << std::endl;
    } while (this->phoneNumber.empty() || !phoneValid(phoneNumber));
    do 
    {
        std::cout << "Your deepest darkest secret: ";
        std::getline(std::cin, this->darkestSecret);
        if (this->darkestSecret.empty())
            std::cerr << "Secret field can't be empty." << std::endl;
    } while (this->darkestSecret.empty());
}