/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:55:02 by mganchev          #+#    #+#             */
/*   Updated: 2025/03/25 23:20:12 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Account
{
    private:
        static int  accounts;
        static int  total;
        static int  deposits;
        static int  withdrawals;
        static int  currentIndex;
        
        int index;
        int amount;
        int nb_deposits;
        int nb_withdrawals;
    
    public:
        Account(int initial_deposit);
        ~Account();
        void    makeDeposit(int deposit);
        void    makeWithdrawal(int withdrawal);
        void    displayStatus() const;
        void    displayAccountsInfos() const;
};