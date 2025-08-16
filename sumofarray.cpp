#include "MYheaders.h"

/*void arrayprint(int arr[],int index)
{
    if(index<0) return;
    arrayprint(arr,index-1);
    cout << arr[index] << endl;
}*/

int arraysum(int arr[],int index)
{
    if(index<0) return 0;
    //arraysum(arr,index-1);
    return arr[index]+arraysum(arr,index-1);
}
int main()
{
    int n;
    cout << "Enter the size of the array :" ;
    cin >> n;
    int arr[n];

    cout << "Enter the values of array which has the size of " << n << ":" ;

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int sum = arraysum(arr,n-1);
    cout << sum << endl;

    //arrayprint(arr,n-1);
}