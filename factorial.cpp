#include<iostream>
#include<string>

using namespace std;

int Factorial(int n)
{
    if(n==0 || n==1) return 1;
    return n*Factorial(n-1);
}

int main()
{
    int n;
    cout << "Give me a number :" ;
    cin >> n ;
    cout << "Factorial is : " << Factorial(n) ;
}