#include<iostream>
#include<string>

using namespace std;

int countdig(int n)
{
    if (n==0) return 0;
    return 1+countdig(n/10);
}

int main()
{
    int d;
    cout << "Enter a number :";
    cin >> d ;
    
    cout << "the number of digits in the number is :" << countdig(d);

}
