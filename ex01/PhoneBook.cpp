/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:42:55 by mganchev          #+#    #+#             */
/*   Updated: 2025/05/08 16:13:21 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

int PhoneBook::currentIndex = 0;

int PhoneBook::getCurrentIndex()
{
    return currentIndex;
}

void    PhoneBook::add()
{
    Contact NewContact;
    
    currentIndex++;
    if (currentIndex > 8)
        currentIndex = 1;
    if (currentIndex <= 8)
    {    
        NewContact.setAttributes();
        NewContact.setIndex(currentIndex);
        Contacts[currentIndex - 1] = NewContact;
    }
}

void    PhoneBook::search()
{ 
    int idx;
    
    if (currentIndex == 0)
    {
        std::cout << "No contacts in phone book. Try adding some first.\n";
        return ;
    }
    else
    {
        std::cout << "Contacts list:\n"
                << std::setw(10) << "INDEX" << "|"
                << std::setw(10) << "FIRST NAME" << "|"
                << std::setw(10) << "LAST NAME" << "|"
                << std::setw(10) << "NICKNAME" << std::endl;
        for (int i = 0; i < 8; i++)
        {
            if (Contacts[i].getIndex() != -1)
                std::cout << std::setw(10) << Contacts[i].getIndex() << "|"
                        << std::setw(10) << Contacts[i].getFirstName() << "|"
                        << std::setw(10) << Contacts[i].getLastName() << "|"
                        << std::setw(10) << Contacts[i].getNickname() << std::endl;
        }
    }
    std::cout << "Choose index to look up contact:\n";
    std::cin >> idx;
    if (idx < 0 || idx > 8 || Contacts[idx - 1].isEmpty())
        std::cout << "Invalid index.\n";
    else 
        std::cout << "First Name: " << Contacts[idx - 1].getIndex() << std::endl
                  << "Last Name: " << Contacts[idx - 1].getLastName() << std::endl
                  << "Nickname: " << Contacts[idx - 1].getNickname() << std::endl
                  << "Phone number: " << Contacts[idx - 1].getPhoneNumber() << std::endl
                  << "Darkest secret: " << Contacts[idx - 1].getDarkestSecret() << std::endl;
    return ;
}

int main()
{
   PhoneBook    newPhoneBook;
   std::string  cmd;

   while(1)
   {
        std::cout << "Please type a command:\n"
                    << "ADD\n"
                    << "SEARCH\n"
                    << "EXIT\n";
        std::cin >> cmd;
        if (cmd == "ADD")
            newPhoneBook.add();
        else if (cmd == "SEARCH")
            newPhoneBook.search();
        else if (cmd == "EXIT")
            return (0);
        else
            std::cout << "Invalid command. Try again.\n";
        std::cout << "\n";
   }
}
