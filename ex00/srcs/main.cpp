#include "DivideAndRule.hpp"

int main()
{
	// Account creation
	Account accountA = Account();
	// accountA.id = 0; id is private and automatically set
	accountA.value = 100;

	Account accountB = Account();
	// accountB.id = 1; id is private and automatically set
	accountB.value = 100;

	// Bank Creation
	Bank bank = Bank();
	bank.liquidity = 999;
	bank.clientAccounts[accountA.getId()] = &accountA;
	bank.clientAccounts[accountB.getId()] = &accountB;

	// Loan
	bank.liquidity -= 200;
	accountA.value += 400;

	//Transfer
	bank.addMoney(80, 0);
	bank.addMoney(-1, 0);
	bank.addMoney(20, 3);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}