#include "MYheaders.h"

struct Pair
{
    int largest,second;    
};

Pair findlargest(int arr[],int l,int r)
{
    Pair p;

    if(l==r)
    {
        p.largest = arr[l];
        p.second = 0;

        return p;
    }

    if(r==l+1)
    {
        if(arr[l]>arr[r])
        {
            p.largest = arr[l];
            p.second = arr[r];

            return p;
        }
        else 
        {
            p.largest = arr[r];
            p.second = arr[l];

            return p;
        }
    }

    int mid = (l+r)/2;

    Pair left = findlargest(arr,l,mid);
    Pair right = findlargest(arr,mid+1,r);
    
    if(left.largest>right.largest)
    {
        p.largest = left.largest;
        p.second = max(left.second , right.largest);
    }
    else
    {
        p.largest = right.largest;
        p.second = max(right.second , left.largest);
    }
    return p;


}

int main()
{
    int arr[] = {1,2,3,4,5,6};

    int n = sizeof(arr)/sizeof(arr[0]);

    Pair result = findlargest(arr,0,n-1);

    cout << result.largest << "," << result.second << endl;

    return 0;
}