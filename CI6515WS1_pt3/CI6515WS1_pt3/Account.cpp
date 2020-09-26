#include <iostream>
#include "Account.h"
using namespace std;

CAccount::CAccount() // constructor
{
	mBalance = 0;
}

CAccount::~CAccount() // destructor
{
}

void CAccount::Deposit(float amount)
{
	mBalance += amount;
}

float CAccount::GetBalance()
{
	return mBalance;
}

// virtual functions
void CAccount::Withdrawal(float amount)
{
}

void CAccount::Interest()
{
}
