#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Account
{
private:
	int ID;
	static int next_id;
	string name;
	float balance;
	const int get_new_id();
public:
	Account();
	void init_prompt();
	void display_user_acct();
	void deposit(const float& deposit_amt);
	void withdrawl(const float& withdrawl_amt);
	const int get_id();
	Account& operator+= (float deposit);
	Account& operator-= (float withdrawl);
	bool operator== (int id) const;
};