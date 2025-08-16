#include<iostream>
#include<string>

using namespace std;

void print(int n)
{
    if(n<=0) return;
    print(n-1);
    cout << n << endl;
}

int main()
{
    int n;
    cout << "Enter the End number :" << endl;

    cin >> n ;
    print(n);
}