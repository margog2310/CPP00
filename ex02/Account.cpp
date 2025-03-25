/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:54:55 by mganchev          #+#    #+#             */
/*   Updated: 2025/03/25 23:46:18 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::accounts = 0;
int Account::total = 0;
int Account::deposits = 0;
int Account::withdrawals = 0;
int Account::currentIndex = -1;

Account::Account(int initial_deposit)
{
    currentIndex++;
    accounts++;
    this->index = currentIndex;
    this->amount = initial_deposit;
    this->nb_deposits = 0;
    this->nb_withdrawals = 0;
    total += amount;
    std::cout << "index:" << this->index << ";"
              << "amount:" << this->amount << ";"
              << "created" << std::endl;
}

Account::~Account()
{
    accounts--;
    total -= this->amount;
    std::cout << "index:" << this->index << ";"
              << "amount:" << this->amount << ";"
              << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
     int    p_amount;

     p_amount = this->amount;
     amount += deposit;
     total += deposit;
     this->nb_deposits++;
     deposits++;
     std::cout << "index:" << this->index << ";"
               << "p_amount:" << p_amount << ";"
               << "deposit:" << deposit << ";"
               << "amount:" << this->amount << ";"
               << "nb_deposits:" << this->nb_deposits << std::endl;
}

void    Account::makeWithdrawal(int withdrawal)
{
    int p_amount;

    p_amount = this->amount;
    if (withdrawal > this->amount)
        std::cout << "index:" << this->index << ";"
                  << "p_amount:" << p_amount << ";"
                  << "withdrawal:refused" << std::endl;
    else
    {
        amount -= withdrawal;
        total -= withdrawal;
        this->nb_withdrawals++;
        withdrawals++;
        std::cout << "index:" << this->index << ";"
                  << "p_amount:" << p_amount << ";"
                  << "withdrawal:" << withdrawal << ";"
                  << "amount:" << this->amount << ";"
                  << "nb_withdrawals:" << this->nb_withdrawals << std::endl;
    }
}

void    Account::displayStatus() const
{
    std::cout << "index:" << this->index << ";"
              << "amount:" << this->amount << ";"
              << "deposits:" << this->nb_deposits << ";"
              << "withdrawals:" << this->nb_withdrawals << std::endl;
}

void    Account::displayAccountsInfos()
{
    std::cout << "accounts:" << accounts << ";"
              << "total:" << total << ";"
              << "deposits:" << deposits << ";"
              << "withdrawals:" << withdrawals << std::endl;
}