#pragma once
#include "Account.h"

class CDepositAccount : public CAccount
{
public:
	CDepositAccount();
	~CDepositAccount();

	void Withdrawal(float amount) override;
	void Interest() override;
	
private:
	float InterestValue = 0.03f;
};