#include<iostream>
#include<string.h>
using namespace std;
int i,n;
class books
{
    
    char title[50], author[50], pub[50];
    int cost,stock;
    public:
    void accept();
    void display();
    void search();
}b[100];

void books::accept() 
{
    cout<<"Enter the title:"<<endl;
    cin>>title;
    cout<<"Enter the Author:"<<endl;
    cin>>author;
    cout<<"Enter the publisher of book:"<<endl;
    cin>>pub;
    cout<<"Enter the cost:"<<endl;
    cin>>cost;
    cout<<"Enter the stock available:\n";
    cin>>stock;
}

void books::display()
{   
    cout<<"Title"<<"\t"<<"Author"<<"\t"<<"Cost"<<"\t"<<"Publisher"<<"\t"<<"Stock"<<endl;
    cout<<title<<"\t"<<author<<"\t"<<cost<<"\t"<<pub<<"\t"<<stock<<endl;
}

void books::search()
{
    int cost,cp,flag=0,f1=0;
    char *sTitle,*sAuthor;

    sTitle=new char;
    sAuthor=new char;

    cout<<"Enter the title and Author to search book:"<<endl;
    cin>>sTitle>>sAuthor;
    for(i=0;i<n;i++)
    {
        if(strcmp(sTitle,b[i].title)==0 &&  strcmp(sAuthor,b[i].author)==0)
           {
            flag=1;
            cout<<"Book is found."<<endl;
            b[i].display();
            break;
           }  
    }

    if(flag==0)
    {
        cout<<"Book not found\n";
    }
}

int main() 
{
    int ch, n;
    do{
    cout<<"Menu"<<endl;
    cout<<"1.Accept"<<endl;
    cout<<"2.Display"<<endl;
    cout<<"3.Searching"<<endl;
    cout<<"4.Exiting"<<endl;
    cout<<"Enter the choice:"<<endl;
    cin>>ch;
    switch(ch)
     {
        case 1:
            cout << "Enter the number of records you want to store: "<<endl;
            cin >> n;
            for (int j = 0; j < n; j++)
             {
                b[j].accept();
            }
            break;
        case 2:
            cout << "Books Record are:" << endl;
            for (int j = 0; j < n; j++) 
            {
                b[j].display();
            }
            break;
        case 3:
              b[i].search();
            break;
        default:
        cout<<"inavlid choice...!"<<endl;
        break;
    }
    }
    while(ch!=4);
    return 0;
}

