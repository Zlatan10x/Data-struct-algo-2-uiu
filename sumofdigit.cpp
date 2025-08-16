#include<iostream>
#include<string>

using namespace std ;

int sumd(int n) 
{
    
    if(n == 0) return n;
    if(n == 1) return n;

    return (n%10) + sumd(n/10);

    


     
}

int main()
{
    int n;
                                                        
    cin >> n ;
    
    cout << n << " sum of the digits :" << sumd(n) << endl;

    return 0;
}