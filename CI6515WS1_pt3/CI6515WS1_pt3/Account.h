#pragma once
#include <iostream>
using namespace std;
class CAccount
{
private:
	float mBalance;

public:
	CAccount();
	virtual ~CAccount();
	void Deposit(float amount);
	float GetBalance();
	virtual void Withdrawal(float amount);
	virtual void Interest();


};