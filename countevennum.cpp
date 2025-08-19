#include "MYheaders.h"

int countevenn(int arr[],int l,int r)
{
    int count = 0;
    if(l==r)
    {
        if(arr[l]%2==0) count++;
        return count;
    } 
    if(r==l+1)
    {
        if(arr[l]%2==0) count++;
        if(arr[r]%2==0) count++;

        return count;
    }

    else
    {
        int mid = (l+r)/2;

        count += countevenn(arr,l,mid);
        count += countevenn(arr,mid+1,r);
        return count;


    }

}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,7,8,9,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    int total = countevenn(arr,0,n-1);

    cout << total << endl;

    return 0;
}