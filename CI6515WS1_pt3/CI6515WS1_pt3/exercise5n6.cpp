#include <iostream>

#include "crtdbg.h"

#include "Account.h"
#include "CurrentAccount.h"
#include "DepositAccount.h"
#include "InvestmentAccount.h"

using namespace std;

void tests()
{
	CAccount* pAccount[3]; // Initialising an array of objects of type 'CAccount'
	pAccount[0] = new CCurrentAccount;
	pAccount[1] = new CDepositAccount;
	pAccount[2] = new CInvestmentAccount(2014);

	// Deposit currency to each new account, which all start at zero
	pAccount[0]->Deposit(300);
	pAccount[1]->Deposit(500);
	pAccount[2]->Deposit(4500);

	// OUTPUT for balances after the deposits
	cout << "Balances:" << endl;
	for (auto& account : pAccount) // range-based for loop over each object
	{
		cout << account->GetBalance() << endl;
	}

	// attempt withdrawals
	pAccount[0]->Withdrawal(400);
	pAccount[1]->Withdrawal(600);
	pAccount[2]->Withdrawal(1400);

	cout << "Withdrawal Balances:" << endl;
	for (auto& account : pAccount)
	{
		cout << account->GetBalance() << endl;
	}

	// collect/give interest
	pAccount[0]->Interest();
	pAccount[1]->Interest();
	pAccount[2]->Interest();

	cout << "Interest Balances:" << endl;
	for (auto& account : pAccount)
	{
		cout << account->GetBalance() << endl;
	}
	for (auto& account : pAccount)
	{
		delete account; // addresses memory leaks
	}
}


int main()
{
	// enable free store debugging and leak-checking bits
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	// direct warnings to stdout
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	
	tests();
	return 0;
}