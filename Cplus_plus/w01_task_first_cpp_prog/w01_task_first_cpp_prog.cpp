// w01_task_first_cpp_prog.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Name: Ervin Martinez
//Date: 4/26/25

#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::endl;

//function defines:
void init_acct_user(string& n, float& b);
void get_user_menu_response(int& r);
void display_menu(void);
void deposit(float& b);
void withdrawl(float& b);

//function main:
int main()
{
    int id = 0, response = -1;
    string name = "nobody";
    float balance = 0.00;

    //Promt user for name and balance
    init_acct_user(name, balance);

    //Display menu, promt user for selection, and provide option.
    //zero exits program.
    while (response != 0)
    {
        display_menu();
        get_user_menu_response(response);

        switch (response)
        {
            case 0:
                break;
            case 1:
                cout << std::fixed << std::setprecision(2) << "Account ID: " << id << "  Name: " << name << " Balance : $" <<  balance <<  endl;
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdrawl(balance);
                break;
            default:
                cout << "Error: Program Terminated" << endl;
                break;
        }
    }
}//End: main

void init_acct_user(string& n, float& b)
{
    cout << "Enter the name: ";
    cin >> n;

    cout << "Enter the balance: ";
    cin >> b;
}//End: init_acct_user

void get_user_menu_response(int& r)
{
    cout << "Your choice: ";
    cin >> r;
}//End: 

void display_menu(void)
{
    cout << "\nAccount Menu:" << endl;
    cout << "0. Quit Program" << endl;
    cout << "1. Display Account Information" << endl;
    cout << "2. Add a deposit to an account" << endl;
    cout << "3. Withdraw from an account" << endl;
}//End: display_menu

void deposit(float& b)
{
    float deposit = 0.00;
    cout << "Amount to deposit: ";
    cin >> deposit;
    b += deposit;
    cout << endl;
}//End: deposit

void withdrawl(float& b)
{
    float withdraw_amnt;
    cout << "Amount to withdraw: ";
    cin >> withdraw_amnt;
    b -= withdraw_amnt;
    cout << endl;
}//End: withdrawl