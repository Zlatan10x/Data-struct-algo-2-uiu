#include "MYheaders.h"

int rangecount(vector <int> &nums,int num,int left, int right)
{ 
    int cnt = 0;
    for(int i=left;i<=right;i++)
    {
        
        if(nums[i]==num) cnt++;
    }
    return cnt;
}

int majorityelem(vector<int> &nums,int left,int right)
{
    if(left==right) return nums[left];

    int mid= (left+right)/2;

    int leftmajor = majorityelem(nums,left,mid);
    int rightmajor = majorityelem(nums,mid+1,right);

    if(leftmajor==rightmajor)
    {
        return leftmajor;
    }

    int leftcount = rangecount(nums,leftmajor,left,right);
    int rightcount = rangecount(nums,rightmajor,left,right);

    return (leftcount>rightcount) ? leftmajor : rightmajor;
}

int main()
{
    vector<int> nums = {11,22,11,23,11,44,11,33,11};

    int candidate = majorityelem(nums,0,nums.size()-1);
    int res = rangecount(nums,candidate,0,nums.size()-1);

    if(res>nums.size()/2) 
    {
        cout << candidate ;
    }
    else 
    {
        cout << "no majority exists." << endl;
    }

    return 0;

}

