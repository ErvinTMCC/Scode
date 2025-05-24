#include "account.h"

int Account::next_id = -1;

Account::Account() :ID{ 0 }, name{ "nobody" }, balance{ 0.00 } {}

//prompt user for starting account name and balance.
void Account::init_prompt()
{
    cout << "Enter the name: ";
    cin >> this->name;

    cout << "Enter the balance: ";
    cin >> this->balance;

    this->ID = get_new_id();

    display_user_acct();
}//End: init_acct_user

void Account::display_user_acct()
{
    cout << std::fixed << std::setprecision(2) << "Account ID: " << this->ID
        << "  Name: " << this->name << " Balance : $" << this->balance << endl;
}//End: display_user_acct

void Account::deposit(const float& deposit_amt)
{
    this->balance += deposit_amt;
}//End: deposit

void Account::withdrawl(const float& withdrawl_amt)
{
    this->balance -= withdrawl_amt;
}//End: withdrawl

const int Account::get_new_id()
{
    ++(this->next_id);
    return this->next_id;
}//End: get_new_id

Account& Account::operator+= (float deposit)
{
    this->balance += deposit;
    return *this;
}

Account& Account::operator-= (float withdrawl)
{
    this->balance -= withdrawl;
    return *this;
}

bool Account::operator== (int id) const
{
    return (this->ID == id);
}

const int Account::get_id()
{
    return this->ID;
}
