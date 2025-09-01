#ifndef DIVIDE_AND_RULE_HPP
#define DIVIDE_AND_RULE_HPP

#include <iostream>
#include <map>

struct Account
{
	unsigned int id;
	double value;

	Account(void);

	friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account);
};

struct Bank
{
private:
public:
	std::map<unsigned int, Account *> clientAccounts;
	double liquidity;
	Bank(void);

	friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
	void addMoney(int amount, unsigned int account_id);
};

#endif
