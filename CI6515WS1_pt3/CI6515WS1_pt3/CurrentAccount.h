#pragma once
#include "Account.h"

class CCurrentAccount : public CAccount
{
public:
	CCurrentAccount();
	~CCurrentAccount();

	void Withdrawal(float amount) override;
	void Interest() override;
private:
	float OverdraftLimit = 5000.f;

};