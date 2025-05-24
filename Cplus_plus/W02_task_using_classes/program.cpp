// W02_task_using_classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "account.h"

using std::unique_ptr;

void display_menu(void);
int get_user_response(void);
bool menu(Account* user);
void user_withdrawl(Account& user);
void user_deposit(Account& user);

int main()
{
    /*unique_ptr<Account> user1(new Account());
    user1->init_prompt();*/

    while(menu(user1.get()))
    {}

    std::cout << "\nBanking Program Terminated\n";
}

bool menu(Account* user)
{
    display_menu();

    //get_user_response();
    switch (get_user_response())
    {
    case 0:
        return false;
        break;
    case 1:
        user->display_user_acct();
        return true;
        break;
    case 2:
        user_deposit(*user);
        return true;
        break;
    case 3:
        user_withdrawl(*user);
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

        if (r >= 0 and r <= 3)
        {
            return r;
        }
        else
        {
            r = -1;
            cout << "Invalide entry, please try again." << endl;
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
}//End: display_men

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
void user_deposit(Account& user_account)
{
    float deposit_amount = 0.00;
    cout << "Amount to deposit: ";
    cin >> deposit_amount;
    user_account += deposit_amount;
    cout << endl;
}//End: deposit

void user_withdrawl(Account& user_account)
{
    float withdraw_amount;
    cout << "Amount to withdraw: ";
    cin >> withdraw_amount;
    user_account -= withdraw_amount;
    cout << endl;
}//End: withdrawl