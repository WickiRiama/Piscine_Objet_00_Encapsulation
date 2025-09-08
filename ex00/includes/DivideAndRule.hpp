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
	Account(double start_value = 0);

public:

	unsigned int getId(void) const;
	friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account);
	friend class Bank;
};

struct Bank
{
private:
	std::map<unsigned int, Account *> clientAccounts;
	double liquidity;
	void addMoney(double amount, unsigned int account_id);
	void removeMoney(double amount, unsigned int account_id);

public:
	Bank(double start_liquidity = 0);
	~Bank(void);

	friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
	unsigned int createAccount(double start_amount);
	void deleteAccount(unsigned int id);
	void transferMoney(double amount, unsigned int from_id, unsigned int to_id);
};

#endif
