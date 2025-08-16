#include<iostream>
using namespace std;

int main ()
{
    cout<< "Enter two numbers :";
    int a,b;

    cin>> a >> b;
    //cin>> b;

    int sum = a+b;

    cout<<"The sum is : "<<a<<"+"<<b<<"="<<sum<<endl;

    return 0;
}