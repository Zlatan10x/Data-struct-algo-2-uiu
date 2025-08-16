#include "MYheaders.h"

int powerofn(int n)
{
    if (n%4==0 || n==1) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;

    cout << powerofn(n);
    
}