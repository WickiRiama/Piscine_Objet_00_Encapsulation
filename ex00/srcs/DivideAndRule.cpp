#include "DivideAndRule.hpp"

unsigned int Account::account_number = 0;

Account::Account(double start_value) : id(account_number), value(std::max(0.0, start_value))
{
	account_number++;
}

Account::Account(Account const &src) : id(account_number)
{
	account_number++;
	*this = src;
}

Account::~Account(void)
{
	std::cout << "Account " << this->id << " deleted." << std::endl;
}

unsigned int Account::getId(void) const
{
	return this->id;
}

Account &Account::operator=(Account const &rhs)
{
	if (this != &rhs)
	{
		this->value = rhs.value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
{
	p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
	return (p_os);
}

Bank::Bank(double start_liquidity) : liquidity(std::max(0.0, start_liquidity)) {}

Bank::Bank(Bank const &src)
{
	*this = src;
}

Bank::~Bank(void)
{
	while (this->clientAccounts.size() > 0)
	{
		this->deleteAccount(this->clientAccounts.begin()->first);
	}
}

Bank &Bank::operator=(Bank const &rhs)
{
	if (this != &rhs)
	{
		this->liquidity = rhs.liquidity;
		while (this->clientAccounts.size() > 0)
		{
			std::cerr << this->clientAccounts.size() << std::endl;
			this->deleteAccount(this->clientAccounts.begin()->first);
		}
		for (std::map<unsigned int, Account *>::const_iterator it = rhs.clientAccounts.begin(); it != rhs.clientAccounts.end(); it++)
		{
			this->createAccount(it->second->value);
		}
	}
	return *this;
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
		this->clientAccounts.erase(id);
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

void Bank::loanMoney(double amount, unsigned int account_id)
{
	std::cout << " -- Loan of " << amount
			  << " to account " << account_id
			  << " --" << std::endl;
	if (amount < 0)
	{
		std::cerr << "You can't loan a negative amount."
				  << std::endl;
	}
	else if (this->clientAccounts.find(account_id) == this->clientAccounts.end())
	{
		std::cerr << "The account " << account_id
				  << " does not exist." << std::endl;
	}
	else if (this->liquidity < amount)
	{
		std::cerr << "The bank does not have the necessary funds."
				  << std::endl;
	}
	else
	{
		this->liquidity -= amount;
		this->addMoney(amount, account_id);
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
