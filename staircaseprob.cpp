#include<iostream>
#include<string>

using namespace std;

int steps(int n)
{
    if(n==1 || n==0) return 1;
    return steps(n-1)+steps(n-2);
}

int main()
{
    int n;
    cout << "Give me the number of stairs :" ;
    cin >> n ;
    cout << "Needed steps : " << steps(n) ;
}