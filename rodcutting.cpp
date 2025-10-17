#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> price =
    {
        {1,2},
        {2,5},
        {3,10},
        {6,13},
        {10,25}
    };

    int n=10;

    vector<int> dp(n+1,0);
    vector<int> cut(n+1,-1);

    for(int len=0;len<n;len++)
    {
        for(auto [plen,pval] : price)
        {
            if(plen <= len)
            {
                int possiblerev = pval+ dp[len-plen];
                if(possiblerev>dp[len])
                {
                    dp[len] = possiblerev;
                    cut[len] = plen;
                }   
            }
        }
    }

    cout << "Maximum Revenue = " << dp[n] << endl;
    cout << "Cut lengths: ";

    int length = n;
    vector<int> pieces;
    while (length > 0) {
        int c = cut[length];
        pieces.push_back(c);
        length -= c;
    }

    for (int x : pieces)
        cout << x << " ";
    cout << endl;

    return 0;
}