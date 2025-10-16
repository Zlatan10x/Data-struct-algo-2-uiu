#include<bits/stdc++.h>

using namespace std;
struct item{
    int w;
    int v;
    int index;
};
int knapsackdp(int w,vector<item>& items,int n)

{
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    
    for(int i = 1;i <= n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(items[i-1].w<=j)
            {
                int include = items[i-1].v+dp[i-1][j-items[i-1].w];
                int exclude = dp[i-1][j];
                dp[i][j] = max(include,exclude);
            }
        }
    }
    return dp[n][w];
}
int main()
{
    int W,n;

    cout << "Enter the number of how many items are available : " << endl;
    cin >> n;
    cout << "Enter the total capacity of the bag(in kg) : ";
    cin >> W;

    vector<item> items(n);
    for(int i=0;i<n;i++)
    {
        cin >> items[i].w >> items[i].v;
        items[i].index = i+1;
    }

    cout << "max : " << knapsackdp(W,items,n);
    return 0; 
}