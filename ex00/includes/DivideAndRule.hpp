#ifndef DIVIDE_AND_RULE_HPP
#define DIVIDE_AND_RULE_HPP

#include <iostream>
#include <map>

struct Account
{
private:
	static unsigned int account_number;
	unsigned int id;
	double value;

public:
	Account(double start_value = 0);

	unsigned int getId(void) const;
	friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account);
	friend class Bank;
};

struct Bank
{
private:
	std::map<unsigned int, Account *> clientAccounts;
	double liquidity;

public:
	Bank(double start_liquidity = 0);

	friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
	void addMoney(int amount, unsigned int account_id);
};

#endif
