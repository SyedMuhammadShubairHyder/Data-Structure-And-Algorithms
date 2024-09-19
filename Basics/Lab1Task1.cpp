/*
Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
a) Default Constructor Usage:
Create a default-initialized BankAccount object named account1. Print out the balance of
account1.
b) Parameterized Constructor Usage:
Create a BankAccount object named account2 with an initial balance of $1000. Print out the
balance of account2.
c) Copy Constructor Usage:
Using the account2 you created earlier, create a new BankAccount object named account3 using
the copy constructor. Deduct $200 from account3 and print out its balance. Also, print out the
balance of account2 to ensure it hasn&#39;t been affected by the transaction involving account3. Note:
assume the variables in your case and print out the details.
*/
#include <iostream>
using namespace std;

class BankAccount{
    private:
    float balance;
    public:
    BankAccount(){
        balance=0;//intialize with zeor take garbage value na aye
        cout<<"Total Balance : $ "<<balance<<endl;
    }

    BankAccount(int a){//paratermised constructor ke liye randomly int leliye
        balance=1000;
        cout<<"Total Balance : $ "<<balance<<endl;
    }

    BankAccount(BankAccount & otherAcc)
    {
        balance=otherAcc.balance;
        balance-=200;
        
        cout<<"Total Balance : $ "<<balance<<endl;
    }
};
int main()
{
    cout<<"Account 1 ";
    BankAccount Acc1;

    cout<<"Account 2 ";
    BankAccount Acc2(1);

    cout<<"Account 3 ";
    BankAccount Acc3(Acc2);
}