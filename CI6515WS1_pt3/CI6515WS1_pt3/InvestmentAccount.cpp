#include "InvestmentAccount.h"
#include <iostream>
#include <ctime>
using namespace std;

CInvestmentAccount::CInvestmentAccount(int cyear)
{
	year = cyear;
}

void CInvestmentAccount::Withdrawal(float amount)
{
	float BalanceAfterWithdrawal = GetBalance() - amount;

	const time_t CurrentTime = time(0);
	struct tm TimeData;
	localtime_s(&TimeData, &CurrentTime);
	int cyear = TimeData.tm_year + 1900;

	if (cyear - year >= 2)
	{
		if (BalanceAfterWithdrawal >= 0)
		{
			Deposit(-amount);
		}
		else
		{
			cout << "Transaction declined." << endl;
		}
	}
	else
	{
		cout << "Unable to withdraw within two years since last withdrawal." << endl;
	}

}

void CInvestmentAccount::Interest()
{
	if (GetBalance() > 0)
	{
		Deposit(GetBalance() * InterestValue);
	}
}
