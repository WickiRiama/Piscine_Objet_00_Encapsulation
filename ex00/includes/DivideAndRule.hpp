#ifndef DIVIDE_AND_RULE_HPP
#define DIVIDE_AND_RULE_HPP

#include <iostream>
#include <vector>

struct Account
{
	int id;
	int value;


	Account();

	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
};

struct Bank
{
	int liquidity;
	std::vector<Account *> clientAccounts;

	Bank();

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);

};

#endif
