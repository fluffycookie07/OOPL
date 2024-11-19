#include<iostream>
using namespace std;

int n;

class MyBank
{
    int AccNo;
    int Amt;
    char name[20];

public:
    void accept();
    void display();
    void withdrawal();
    void deposit();
} B[100];

void MyBank::accept()
{
    cout << "Enter the Account Number: ";
    cin >> AccNo;
    cout << "Enter the Amount: ";
    cin >> Amt;
    cout << "Enter your name: ";
    cin >> name; 
}

void MyBank::display()
{
    cout << "Account No: " << AccNo << "\tAmount: " << Amt << "\tName: " << name << endl;
}

void MyBank::withdrawal()
{
    int withdrawAmount;
    cout << "Enter amount to withdraw: ";
    cin >> withdrawAmount;
    if (withdrawAmount > Amt)
    {
        cout << "Insufficient Amount..!" << endl;
    }
    else
    {
        Amt -= withdrawAmount;
        cout << "Withdrawal successful.: "<< endl;
         cout << "Remaining Amount is: " << Amt << endl;
    }
}

void MyBank::deposit()
{
    int depositAmount;
    cout << "Enter amount to deposit: ";
    cin >> depositAmount;
    Amt += depositAmount;
    cout << "Deposit successful.: "<< endl;
     cout << "Your updated Balance is: " << Amt << endl;
}

int main()
{
    int choice;

    cout << "Enter your choice:" << endl;
    cout << "1. Accept" << endl;
    cout << "2. Display" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Deposit" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter the number of records you want to store: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            B[i].accept();
        }
    }
    else if (choice == 2)
    {
        cout << "Records are:" << endl;
        for (int i = 0; i < n; i++)
        {
            B[i].display();
        }
    }
    else if (choice == 3)
    {
        cout << "Enter the record number for withdrawal (0 to " << n - 1 << "): ";
        int recordIndex;
        cin >> recordIndex;
        if (recordIndex >= 0 && recordIndex < n)
        {
            B[recordIndex].withdrawal();
        }
        else
        {
            cout << "Invalid record number!" << endl;
        }
    }
    else if (choice == 4)
    {
        cout << "Enter the record number for deposit (0 to " << n - 1 << "): ";
        int recordIndex;
        cin >> recordIndex;
        if (recordIndex >= 0 && recordIndex < n)
        {
            B[recordIndex].deposit();
        }
        else
        {
            cout << "Invalid record number!" << endl;
        }
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
