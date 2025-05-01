/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:54:55 by mganchev          #+#    #+#             */
/*   Updated: 2025/05/01 20:05:50 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _nbAccounts++;
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "created" << std::endl;
}

Account::~Account()
{
    _nbAccounts--;
    _totalAmount -= this->_amount;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "closed" << std::endl;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

void Account::makeDeposit(int deposit)
{
     int    p_amount;

     p_amount = this->_amount;
     _amount += deposit;
     _totalAmount += deposit;
     this->_nbDeposits++;
     _totalNbDeposits++;
     _displayTimestamp();
     std::cout << "index:" << this->_accountIndex << ";"
               << "p_amount:" << p_amount << ";"
               << "deposit:" << deposit << ";"
               << "amount:" << this->_amount << ";"
               << "nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount() const
{
    return this->_amount;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    int p_amount;

    p_amount = this->_amount;
    if (withdrawal > this->_amount)
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";"
                  << "p_amount:" << p_amount << ";"
                  << "withdrawal:refused" << std::endl;
        return false;
    }
    else
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";"
                  << "p_amount:" << p_amount << ";"
                  << "withdrawal:" << withdrawal << ";"
                  << "amount:" << this->_amount << ";"
                  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    }
    return true;
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << _totalAmount << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void    Account::_displayTimestamp()
{
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);

    std::cout << "["
              << 1900 + ltm->tm_year
              << (ltm->tm_mon + 1 < 10 ? "0" : "") << (ltm->tm_mon + 1)
              << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
              << "_"
              << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
              << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
              << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
              << "] ";
}