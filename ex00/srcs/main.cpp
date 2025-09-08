#include "DivideAndRule.hpp"

int main()
{
	// Bank Creation
	Bank bank = Bank(999);
	
	// Account Creation
	unsigned int accountA = bank.createAccount(100);
	unsigned int accountB = bank.createAccount(100);

	// Creation of a second bank
	Bank bank2 = bank;
	std::cout << " ----- " << std::endl;
	std::cout << "Bank 1: " << std::endl;
	std::cout << bank << std::endl;
	std::cout << " ----- " << std::endl;
	std::cout << "Bank 2: " << std::endl;
	std::cout << bank2 << std::endl;

	// Loan
	bank.loanMoney(200, accountA);
	bank.loanMoney(900, accountB);
	bank.loanMoney(50, 3);
	bank.loanMoney(-10, accountA);

	//Transfer
	bank.transferMoney(80, accountB, accountA);
	bank.transferMoney(-1, accountB, accountA);
	bank.transferMoney(20, accountB, 3);
	bank.transferMoney(20, 3, accountB);
	bank.transferMoney(50, accountB, accountA);

	// Account deletion
	bank2.deleteAccount(3);

	// Final State
	std::cout << " ----- " << std::endl;
	std::cout << "Bank 1: " << std::endl;
	std::cout << bank << std::endl;
	std::cout << " ----- " << std::endl;
	std::cout << "Bank 2: " << std::endl;
	std::cout << bank2 << std::endl;

	return (0);
}