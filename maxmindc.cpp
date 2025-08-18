#include "Myheaders.h"


struct Minmax
{
    int mn,mx;
};
Minmax getminmax(int arr[],int l,int r)

{
    if (l==r) return {arr[l], arr[r]};

    if (r==l+1) 
    {
        if(arr[l]<arr[r]) return {arr[l], arr[r]};
        else return {arr[r], arr[l]};
    }
    
    int mid = (l+r)/2;

    Minmax L = getminmax(arr,l,mid);
    Minmax R = getminmax(arr,mid+1,r);

    return
    {
        (L.mn<R.mn ? L.mn : R.mn),
        (L.mx>R.mx ? L.mx : R.mx)

    };

}

int main()
{
    int arr[] = {1,3,4,56,7,64,6,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    Minmax rs = getminmax(arr,0,n-1);

    cout << "max is " << rs.mx << " and min is " << rs.mn << endl;
    return 0;

}
