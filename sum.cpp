#include<iostream>
#include<string>

using namespace std ;

int print(int n) 
{
    if(n<=0) return n;
     return n+print(n-1);
    //cout << n << endl;
}

int main()
{
    int n;
    cin >> n ;
    print(n);
    cout << print(n) << endl;

    return 0;
}