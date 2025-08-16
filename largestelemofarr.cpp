#include<iostream>
#include<string>

using namespace std ;

int largestarr(int arr[],int n,int L) 
{
    
    if(n == 1) return arr[0];

    if(arr[n-1]>L)
    {
        L = arr[n-1];
        largestarr(arr,n-1,L);
    
    }
    return L;
     
}

int main()
{
    int n;
    cin >> n ;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    int L = 0;
    
    
    cout << "the largest element :" << largestarr(arr,n,L) << endl;

    return 0;
}