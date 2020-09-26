#pragma once
#include "DepositAccount.h"

class CInvestmentAccount : public CDepositAccount
{
public:
	CInvestmentAccount(int cyear);
	void Withdrawal(float amount) override;
	void Interest() override;
private:
	int year;
	float InterestValue = 0.08f;
};