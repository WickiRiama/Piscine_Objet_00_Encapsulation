#include "DivideAndRule.hpp"

int main()
{
	// Account creation
	Account accountA = Account(100);
	// accountA.id = 0; id is private and automatically set
	// accountA.value = 100; value is private

	Account accountB = Account(100);
	// accountB.id = 1; id is private and automatically set
	// accountB.value = 100; value is private

	// Bank Creation
	Bank bank = Bank(999);
	// bank.liquidity = 999; liquidity is private

	// Account Creation
	// bank.clientAccounts[accountA.getId()] = &accountA; clientAccount is private
	// bank.clientAccounts[accountB.getId()] = &accountB; clientAccount is private

	// Loan
	// bank.liquidity -= 200; liquidity is private
	// accountA.value += 400; value is private

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