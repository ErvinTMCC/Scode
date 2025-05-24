// W03_stdTemplate_Iterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "account.h"
#include <list>
using std::unique_ptr;
using std::list;

void display_menu(void);
int get_user_response();
bool menu(list<Account>& account_members);
void user_withdrawl(list<Account>& account_members);
void user_deposit(list<Account>& account_members);
void add_new_account(list<Account>& account_members);
void display_members(list<Account>& account_members);
list<Account>::iterator find_mem_acct(list<Account>& account_members, int id);

int main()
{
    //unique_ptr<Account> user1(new Account());
    list<Account> accounts;
    
    //display_members(accounts);

    while (menu(accounts))
    {
    }

    std::cout << "\nBanking Program Terminated\n";
}
  
bool menu(list<Account>& account_members)
{
    int requested_id = 0;
    list<Account>::iterator member = account_members.end();
    display_menu();

    //get_user_response();
    switch (get_user_response())
    {
    case 0:
        return false;
        break;
    case 1:
        //user->display_user_acct();
        display_members(account_members);
        return true;
        break;
    case 2:
        user_deposit(account_members);
        return true;
        break;
    case 3:
        user_withdrawl(account_members);
        return true;
        break;
    case 4:
        //Add new account member
        add_new_account(account_members);
        return true;
        break;
    case 5:
        //Add new account member
        cout << "Enter the ID of the account to find: ";
        cin >> requested_id;
        member = find_mem_acct(account_members, requested_id);
        if (member == account_members.end())
        {
            cout << "No Account was found for id " << requested_id << endl;
        }
        else
        {
            member->display_user_acct();
        }
        return true;
        break;
    default:
        cout << "Error: Program Terminated" << endl;
        return false;
        break;
    }
}//End: menu

int get_user_response()
{
    int r = -1;
    while (r == -1)
    {
        cout << "Your choice: ";
        cin >> r;

        if (r >= 0 and r <= 5)
        {
            return r;
        }
        else
        {
            r = -1;
            cout << "Invalide entry, please try again." << endl;
            get_user_response();
        }
    }
}//End: get_user_response

void display_menu(void)
{
    cout << "\nAccount Menu:" << endl;
    cout << "0. Quit Program" << endl;
    cout << "1. Display Account Information" << endl;
    cout << "2. Add a deposit to an account" << endl;
    cout << "3. Withdraw from an account" << endl;
    cout << "4. Add new account" << endl;
    cout << "5. Find account by ID" << endl;

}//End: display_men

void user_deposit(list<Account>& account_members)
{
    int requested_id = 0;
    float deposit_amount = 0.00;
    cout << "Enter the ID of the account to find: ";
    cin >> requested_id;
    list<Account>::iterator member = find_mem_acct(account_members, requested_id);
    if (member == account_members.end())
    {
        cout << "No Account was found for id " << requested_id << endl;
    }
    else
    {
        cout << "Amount to deposit: ";
        cin >> deposit_amount;
        *member += deposit_amount;
        cout << endl;
    }
}//End: deposit

void user_withdrawl(list<Account>& account_members)
{
    int requested_id = 0;
    float withdraw_amount = 0.00;
    cout << "Enter the ID of the account to find: ";
    cin >> requested_id;
    list<Account>::iterator member = find_mem_acct(account_members, requested_id);
    if (member == account_members.end())
    {
        cout << "No Account was found for id " << requested_id << endl;
    }
    else
    {
        cout << "Amount to withdraw: ";
        cin >> withdraw_amount;
        *member -= withdraw_amount;
        cout << endl;
    }
}//End: withdrawl

void add_new_account(list<Account>& account_members)
{
    Account account;
    account.init_prompt();
    account_members.push_back(account);
}

void display_members(list<Account>& account_members)
{
    list<Account>::iterator it;
    for (it = account_members.begin(); it != account_members.end(); it++)
    {
        it->display_user_acct();
    }
}

list<Account>::iterator find_mem_acct(list<Account>& account_members, int id)
{
    list<Account>::iterator it;
    for (it = account_members.begin(); it != account_members.end(); it++)
    {
        if (*it == id)
            return it;
    }

    return it;
}