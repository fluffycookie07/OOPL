/*
Assignmnet No:3:-Class,Object,Constructor(default,copy,paramterised),Destructor,Inline,Friend Function,New-Delete,Static
*/
#include <iostream>
#include <cstring>
using namespace std;

int i, n;
class Info
{
    static int cnt;
    int pn, cn, wt, ht, dob;
    char *name, *add, *dln, bg[3];

public:
    Info()
    {
        name = new char;
        add = new char;
        dln = new char;
        strcpy(name, "vvvv");
        strcpy(add, "WWW");
        strcpy(dln, "dl100");
        pn = 100;
        cn = 99999;
        wt = 10;
        ht = 10;
        dob = 2024;
        strcpy(bg, "O+");
    }

    Info(int h, int w, int d)
    {
        ht = h;
        wt = w;
        dob = d;
    }

    Info(Info &ss)
    {
        ss.ht = ht;
    }

    static void displaycnt()
    {
        cout << "\n Total number of Records in the database: " << cnt;
    }

    void display();
    void accept()
    {
        cnt++;
        cout << "\n Enter the name,address,driving licence number,policy number,contact number:";
        cin >> name >> add >> dln >> pn >> cn ;
    }

    friend void Search(Info[], int);

    ~Info()
    {
        delete dln;
        delete name;
        cout << "\n Destructor is called";
    }

    void Delete();
    void update();
} p[100];

int Info::cnt;

void Info::update()
{
    int q, f = 0;
    cout << "\n Enter the policy number:";
    cin >> q;
    for (i = 0; i < n; i++)
    {

        if (q == p[i].pn)
        {
            f = 1;

            p[i].accept();
            break;
        }
    }
    if (f == 0)
        cout << "\n Record is not Found";
}

void Info::Delete()
{

    int q, f = 0;
    cout << "\n Enter the policy number:";
    cin >> q;
    for (i = 0; i < n; i++)
    {

        if (q == p[i].pn)
        {
            f = 1;

            do
            {
                p[i] = p[i + 1];
                i++;
            } while (i < n);
            n--;
            break;
        }
    }
    if (f == 0)
        cout << "\n not found";
}
void Search(Info p[], int i)
{
    int f = 0, pp;
    cout << "\n Enter the Policy number for search:";
    cin >> pp;

    for (i = 0; i < n; i++)
    {
        if (pp == p[i].pn)
        {
            f = 1;

            p[i].display();
            break;
        }
    }
    if (f == 0)
        cout << "\n Details are not found";
}

inline void Info::display()
{
    cout << "\n"
         << name << "\t" << add << "\t" << dln << "\t" << pn << "\t" << cn;
}

int main()
{
    int ch;

    cout << "\n Enter the n:";
    cin >> n;
    do
    {

        cout << "\nMenu";
        cout << "\n1.Accept\n2.Display\n3.Search\n4.Display number of Record\n5.Update Record\n6.Delete Record\n7.Exit";
        cout << "\nEnter Your Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (i = 0; i < n; i++)
            {
                p[i].accept();
            }
            break;
        case 2:
            cout << "\n Name\t Add\tDLN\tPN\tCN";
            for (i = 0; i < n; i++)
            {
                p[i].display();
            }
            break;
        case 3:
            Search(p, i);
            break;
        case 4:
            Info::displaycnt();
            break;
        case 5:
            p[i].update();
            break;
        case 6:
            p[i].Delete();
            break;
        case 7:
            cout<<"Exiting";
            break;
        }
    } while (ch != 7);
    return 0;
}