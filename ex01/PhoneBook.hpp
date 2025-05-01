/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:42:45 by mganchev          #+#    #+#             */
/*   Updated: 2025/05/01 18:39:10 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>

class PhoneBook
{
    private:
        static int currentIndex;
        Contact Contacts[8];

    public:
        void    add();
        void    search();
        int getCurrentIndex();
};

#endif