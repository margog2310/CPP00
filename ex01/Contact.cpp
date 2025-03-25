/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:33:45 by mganchev          #+#    #+#             */
/*   Updated: 2025/03/25 21:47:14 by mganchev         ###   ########.fr       */
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

void Contact::setAttributes()
{
    std::cout << "First Name: ";
    std::cin >> this->firstName;
    std::cout << "Last Name: ";
    std::cin >> this->lastName;
    std::cout << "Nickname: ";
    std::cin >> this->nickname;
    std::cout << "Phone Number: ";
    std::cin >> this->phoneNumber;
    std::cin.ignore();
    std::cout << "Your deepest darkest secret: ";
    std::getline(std::cin, this->darkestSecret);
}