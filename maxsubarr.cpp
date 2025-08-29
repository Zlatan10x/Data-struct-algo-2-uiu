#include<bits/stdc++.h>
using namespace std;

int crossum(vector<int> &arr,int &l,int &r,int &mid)
{
    int leftsum = INT_MIN;
    int sum = 0;
    for(int i=mid;i>=l;i--)
    {
        sum += arr[i];
        leftsum = max(leftsum,sum);
    }
    int rightsum = INT_MIN;
    sum = 0;
    for(int i=mid+1;i<=r;i++)
    {
        sum += arr[i];
        rightsum = max(rightsum,sum);
    }
    return leftsum+rightsum;
}
int maxsum(vector<int>& arr,int l,int r)
{
    if(l==r) return arr[l];

    int mid = (l+r)/2;
    int leftsum = maxsum(arr,l,mid);
    int rightsum = maxsum(arr,mid+1,r);
    int cross = crossum(arr,l,r,mid);
    return max({leftsum,rightsum,cross});

}
int main()
{
    vector<int> arr =  {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxsum(arr,0,arr.size()-1);
    cout << res << endl;
    return 0;
}