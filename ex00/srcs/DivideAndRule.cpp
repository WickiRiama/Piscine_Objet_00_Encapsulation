#include "DivideAndRule.hpp"

unsigned int Account::account_number = 0;

Account::Account() : id(account_number), value(0) {
	account_number ++;
}

unsigned int Account::getId(void) const
{
	return this->id;
}

std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
{
	p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
	return (p_os);
}

Bank::Bank() : liquidity(0) {}

void Bank::addMoney(int amount, unsigned int account_id)
{
	Account *account;

	if (amount < 0)
	{
		std::cout << "You can't add a negative amount to an account."
				  << " If you tried to add more than "
				  << __INT_MAX__ << ", try a lower amount."
				  << std::endl;
		return;
	}
	try
	{
		account = this->clientAccounts.at(account_id);
	}
	catch (const std::out_of_range &error)
	{
		std::cout << "This account doesn't exist." << std::endl;
		return;
	}
	account->value += amount * 0.95;
	this->liquidity += amount * 0.05;
	std::cout << "--Tranfert of " << amount << " to account " << account_id << std::endl
			  << amount * 0.95 << " was credited to the account"
			  << ". The bank took " <<  amount * 0.05 << " (5\%) of fees."
			  << std::endl;
}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity << std::endl;
	for (
		std::map<unsigned int, Account *>::const_iterator it = p_bank.clientAccounts.begin();
		it != p_bank.clientAccounts.end();
		it++)
	{
		p_os << *(it->second) << std::endl;
	}
	return (p_os);
}
