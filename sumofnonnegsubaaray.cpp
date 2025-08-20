#include "MYheaders.h"

int sumofarr(vector<int> &nums,int left,int right)
{
    

    if(left==right) return (nums[left]>0) ? nums[left] : 0;


    int mid = (left+right)/2;

    int leftsub = sumofarr(nums,left,mid);
    int rightsub = sumofarr(nums,mid+1,right);

    int leftsum = 0;
    int temp = 0;
    for(int i=mid;i>=left;i--)
    {
        if(nums[i]<0) break;
        temp += nums[i];
        leftsum = temp;
    }

    int rightsum = 0;
    temp = 0;
    for(int i = mid+1; i<=right; i++)
    {
        if(nums[i]<0) break;
        temp += nums[i];
        rightsum = temp;
    }

    int crossmax = rightsum+leftsum;
    return max({leftsub,rightsub,crossmax});


    
}
int main()
{
    vector<int> nums = {0,-33,3,4,3,2,-1,6,7,8};

    int result = sumofarr(nums,0,nums.size()-1);

    cout << result << endl;
    return 0;
}

