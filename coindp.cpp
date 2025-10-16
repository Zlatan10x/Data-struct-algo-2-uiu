#include<bits/stdc++.h>
using namespace std;

int mycoins(int n,vector<int>& coin)
{
    int d = coin.size();
    vector<int> bestnumcoin(n+1 , INT_MAX);

    bestnumcoin[0] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(i>=coin[j] && bestnumcoin[i-coin[j]] != INT_MAX)
            {
                bestnumcoin[i] = min(bestnumcoin[i],bestnumcoin[i-coin[j]]+1);
            }
        }
    }
    return (bestnumcoin[n] == INT_MAX) ? -1 : bestnumcoin[n];
}


int main()
{
    int n,a;
    cout << "enter the total amount : ";
    cin >> a;
    cout << "Enter the number of coins : ";
    cin >> n;

    cout << "Now enter the coins one by one : " << endl; 
    vector<int> coin(n);
    for(int i=0;i<n;i++)
    {
        cin >> coin[i];
    }

    int result = mycoins(a,coin);
    if(result<= -1)
    {
        cout << "Operation not possible !!"; 
    }
    else
    {
        cout << "total coins needed : " << result;
    }
    return 0;
}