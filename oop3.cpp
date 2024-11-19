#include<iostream>
using namespace std;
class Complex
{
float r,img;
public:
Complex()
{
r=0;
img=0;
}
Complex(float rr, float im)
{
r=rr;
img=im;
}
void display()
{
if(img>=0)
{
cout<<r<<"+"<<img<<"i"<<endl;
}
else
{
cout<<r<<" "<<img<<"i"<<endl;
}
}
Complex operator+(Complex);
Complex operator-(Complex);
Complex operator*(Complex);
Complex operator/(Complex);
}c1,c2,c3;



Complex Complex::operator+(Complex c2)
{

c3.r=r+c2.r;
c3.img=img+c2.img;
return c3;
}


Complex Complex::operator-(Complex c2)
{

c3.r=r-c2.r;
c3.img=img-c2.img;
return c3;
}


Complex Complex::operator*(Complex c2)
{

c3.r=(r*c2.r)-(img*c2.img);
c3.img=r*c2.img+(img*c2.r);
return c3;
}


Complex Complex::operator/(Complex c2)
{

c3.r=(r*c2.r+img*c2.img)/(c2.r*c2.r+c2.img*c2.img);
c3.img=(-r*c2.img+img*c2.r)/(c2.r*c2.r+c2.img*c2.img);
return c3;
}
int main()
{
float rr,im;
int ch;
cout<<"Enter the real part and imaginary part of first no:"<<endl;
cin>>rr>>im;
Complex c1(rr,im);
cout<<"Enter the real part and imaginary part of second no:"<<endl;
cin>>rr>>im;
Complex c2(rr,im);
do
{


cout<<"1.Addition"<<endl;
cout<<"2.Substraction"<<endl;
cout<<"3.Multiplication"<<endl;
cout<<"4.Division"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch(ch)
{
 case 1:
       c1+c2;
       c3.display();
       break;
 case 2:
       c1-c2;
       c3.display();
       break;
 case 3:
       c1*c2;
       c3.display();
       break;
 case 4:
       c1/c2;
       c3.display();
       break;
 default:
       cout<<"invalid choice"<<endl;
       break;
 }
 }
 while(ch!=0);
 
 return 0;
 }