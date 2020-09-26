#include "DepositAccount.h"

CDepositAccount::CDepositAccount()
{
}

CDepositAccount::~CDepositAccount()
{
}

void CDepositAccount::Withdrawal(float amount)
{
	float BalanceAfterWithdrawal = GetBalance() - amount;
	if (BalanceAfterWithdrawal < 0)
	{
		cout << "Transaction declined; insufficient funds." << endl;
	}
	else
	{
		Deposit(-amount);
	}
}

void CDepositAccount::Interest()
{
	if (GetBalance() > 0)
	{
		Deposit(GetBalance() * InterestValue);
	}
}
