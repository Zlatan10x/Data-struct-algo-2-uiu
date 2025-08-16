#include "MYheaders.h"
 
void arrayprint(int arr[],int index)
{
    if(index<0) return;
    arrayprint(arr,index-1);
    cout << arr[index] << endl;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};

    arrayprint(arr,sizeof(arr)/sizeof(arr[0])-1);
}