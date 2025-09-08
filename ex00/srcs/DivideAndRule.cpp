#include "DivideAndRule.hpp"

unsigned int Account::account_number = 0;

Account::Account(double start_value) : id(account_number), value(std::max(0.0, start_value))
{
	account_number++;
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

Bank::Bank(double start_liquidity) : liquidity(std::max(0.0, start_liquidity)) {}

Bank::~Bank(void)
{
	for (std::map<unsigned int, Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++)
	{
		this->deleteAccount(it->first);
	}
}

unsigned int Bank::createAccount(double start_amount)
{
	Account *new_account = new Account(start_amount);
	this->clientAccounts[new_account->getId()] = new_account;
	return new_account->getId();
}

void Bank::deleteAccount(unsigned int id)
{
	try
	{
		delete this->clientAccounts.at(id);
		std::cout << "Account " << id << " deleted." << std::endl;
	}
	catch (const std::out_of_range &error)
	{
		std::cerr << "Account " << id << " does not exist." << std::endl;
	}
}

void Bank::addMoney(double amount, unsigned int account_id)
{
	std::cout << " - Adding " << amount << " to account "
			  << account_id << " -" << std::endl;
	this->clientAccounts.at(account_id)->value += amount * 0.95;
	this->liquidity += amount * 0.05;
	std::cout << amount * 0.95 << " was credited to the account"
			  << ". The bank took " << amount * 0.05 << " (5\%) of fees."
			  << std::endl
			  << "  ----" << std::endl;
}

void Bank::removeMoney(double amount, unsigned int account_id)
{
	std::cout << " - Removing " << amount << " from account "
			  << account_id << " -" << std::endl;
	this->clientAccounts.at(account_id)->value -= amount;
	std::cout << amount << " was removed from the account"
			  << std::endl
			  << "  ----" << std::endl;
}

void Bank::transferMoney(double amount, unsigned int from_id, unsigned int to_id)
{
	std::cout << " -- Tranfer of " << amount
			  << " from account " << from_id
			  << " to account " << to_id
			  << " --" << std::endl;
	if (amount < 0)
	{
		std::cerr << "You can't transfer a negative amount."
				  << std::endl;
	}
	else if (this->clientAccounts.find(from_id) == this->clientAccounts.end())
	{
		std::cerr << "The account " << from_id
				  << " does not exist." << std::endl;
	}
	else if (this->clientAccounts.find(to_id) == this->clientAccounts.end())
	{
		std::cerr << "The account " << to_id
				  << " does not exist." << std::endl;
	}
	else if (this->clientAccounts.at(from_id)->value < amount)
	{
		std::cerr << "The account " << from_id
				  << " does not have the necessary funds." << std::endl;
	}
	else
	{
		this->removeMoney(amount, from_id);
		this->addMoney(amount, to_id);
	}

	std::cout << " -----" << std::endl;
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
