#include <iostream>
#include "CurrentAccount.h"
using namespace std;

CCurrentAccount::CCurrentAccount()
{
}

CCurrentAccount::~CCurrentAccount()
{
}

void CCurrentAccount::Withdrawal(float amount)
{
	float BalanceAfterWithdrawal = GetBalance() + OverdraftLimit - amount;
	
	if (BalanceAfterWithdrawal >= amount)
	{
		Deposit(-amount);
	}
	else
	{
		cout << "Transaction declined; desired withdrawal exceeds current balance (including overdraft limit" << endl;
	}
}

void CCurrentAccount::Interest()
{
	// Interest for customer payment when current balance is negative
	if (GetBalance() < 0)
	{
		Deposit(GetBalance() * 0.05f);
	}
}
