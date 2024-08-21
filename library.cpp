#include <iostream>
#include <cstring>
using namespace std;
int n;
class library
{
public:
    char *tt, *aut, *pub;
    int cost, sp;

public:
    void accept();
    void display();
    void search();
    library()
    {
        tt = new char();
        aut = new char();
        pub = new char();
        strcpy(tt, "oops");
        strcpy(aut, "william");
        strcpy(pub, "tata");
        cost = 0;
        sp = 0;
    }
    ~library()
    {
        delete tt;
        delete aut;
        delete pub;
        cout << "record deleted\n";
    }
} l[10];
void library::accept()
{
    cout << "Enter the Title:\n";
    cin >> tt;
    cout << "Enter the Author:\n";
    cin >> aut;
    cout << "Enter the Publisher:\n";
    cin >> pub;
    cout << "Enter the Cost:\n";
    cin >> cost;
    cout << "Enter the Stock Position:\n";
    cin >> sp;
}
void library::display()
{
    cout << "\n"
         << tt << "\t" << aut << "\t" << pub << "\t" << cost << "\t" << sp;
}
void library::search()
{
    char book[10], auth[10];
    int f = 0, cost = 0;
    int cp, available = 0;
    cout << "Enter the book Title:";
    cin >> book;
    cout << "Enter the book Author:";
    cin >> auth;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(book, l[i].tt) == 0 && strcmp(l[i].aut, auth) == 0)
        {
            f = 1;
            cout << "Enter the copies you want:";
            cin >> cp;
            if (cp <= l[i].sp)
            {
                available = 1;
                cout << "\nCopies are Available";
                cost = l[i].cost * cp;
                l[i].sp -= cp;
                cout << "\nTotal Price is:" << cost;
            }
        }
    }
    if (f == 0)
    {
        cout << "Book is not found";
    }
    if (f == 1 && available == 0)
    {
        cout << "\nA Book is available but copies are unavailable";
    }
}
int main()
{
    int ch, i;
    cout << "\nEnter the Number of Entries:";
    cin >> n;
    do
    {
        cout << "\nMenu\n1.Accept\n2.Display\n3.Search\n4.Exit\n";
        cout << "\nEnter your Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                l[i].accept();
            }
            break;

        case 2:
            cout << "\nTitle\tAuthor\tPublisher\tCost\tStock";
            for (int i = 0; i < n; i++)
            {
                l[i].display();
            }
            break;
        case 3:
            l[i].search();
            break;

        case 4:
            cout << "\nExit";
            break;
        default:
            cout << "\ninvalid Choice";
            break;
        }
    } while (ch != 0);
    return 0;
}
