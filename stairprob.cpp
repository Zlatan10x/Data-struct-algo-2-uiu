#include<iostream>
#include<string>

using namespace std ;

int stairs(int n) 
{
    
    if(n == 0) return 1;
    if(n == 1) return 1;

    return stairs(n-1)+stairs(n-2);


     
}

int main()
{
    int n;
   // int stair = 9;
    cin >> n ;
    //stairs(n);
    cout << n << " ways :" << stairs(n) << endl;

    return 0;
}