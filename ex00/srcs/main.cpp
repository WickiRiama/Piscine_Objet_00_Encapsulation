#include "DivideAndRule.hpp"

int main()
{
	// Bank Creation
	Bank bank = Bank(999);
	
	// Account Creation
	unsigned int accountA = bank.createAccount(100);
	unsigned int accountB = bank.createAccount(100);

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

	// Final State
	std::cout << " ----- " << std::endl;
	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}