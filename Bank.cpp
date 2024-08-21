#include <iostream>
using namespace std;
int n;
class bank
{
public:
    int accountno, amount;
    string name;

public:
    void accept();
    void display();
    void withdraw();
    void deposit();
    void update();
    bank()
    {
        accountno = 0;
        amount = 0;
        name = "bank";
    }
} b[100];

void bank ::accept()
{
    cout << "Enter the Account No:";
    cin >> accountno;
    cout << "Enter the Amount:";
    cin >> amount;
    cout<< "Enter Name:";
    cin >> name;
}
void bank::display()
{
    cout << "Account\tAmount\tname\n";
    for (int i = 0; i < n; i++)
    {
        cout << b[i].accountno <<"\t" << b[i].amount << "\t" << b[i].name << "\n";
    }
}
void bank::withdraw()
{
    int i;
    int acc, withd, f = 0;
    cout << "Enter the Amount you want to Withdraw:\n";
    cin >> withd;
    if (withd <= amount)
    {
        amount -= withd;
        cout<<"\nAvailable Balance:\n"<<amount;
    }
    else
    {
        cout << "Amount is not available\n";
    }
}
void bank::deposit()
{
    int depo;
    cout << "Deposit Amount:\n";
    cin >> depo;
    amount += depo;
    cout<<"\nAvailable Balance:\n"<<amount;

}

int main()
{

    int ch;
    do
    {
        cout << "Menu" << endl;
        cout << "1.Accept" << "\n"
             << "2.Display" << "\n"
             << "3.Withdraw" << "\n"
             << "4.Deposit" << "\n"
             << "5.exit\n";
        cout << "Enter your Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter how many records you want to insert:";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                b[i].accept();
            }
            break;
        case 2:
            int i;
            b[i].display();
            break;
        case 3:
            int acc;
            cout << "Enter the Account No:\n";
            cin >> acc;
            for (int i = 0; i < n; i++)
            {
                if (b[i].accountno == acc)
                {
                    b[i].withdraw();
                }
            }
            break;
        case 4:
            int accno;
            cout << "Enter the accont no:\n";
            cin >> accno;
            for (int i = 0; i < n; i++)
            {
                if (b[i].accountno == accno)
                {
                    b[i].deposit();
                }
            }
            break;
        case 5:
            cout << "exit loop";
            break;
        default:
            cout << "returning from loop";
            break;
        }
    } while (ch != 5);
    return 0;
}