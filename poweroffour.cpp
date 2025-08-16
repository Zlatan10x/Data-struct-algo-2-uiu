#include<iostream>
#include<string>

using namespace std ;

int powerof(int n,int num) 
{   
    if(num==1) return true;

    if(num==0 || num%n!=0) return false;

    return powerof(n,num/n);
    
    
     
}

int main()
{
    int n;
    cin >> n ;
    int num;
    cin >> num;
    
    
    
    cout << powerof(n,num) << endl;

    return 0;
}