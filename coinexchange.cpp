#include<bits/stdc++.h>
using namespace std;

void mycoin(int v)
{
    vector<int> coins = {1000,500,100,50,20,10,5,2,1};
    vector<int> totalcoins;
    for(int coin : coins)
    {
        if(v>=coin);
        v -= coin;
        totalcoins.push_back(coin);
    }
    cout << totalcoins.size() << " Coins were taken" << endl;
    cout << "Chosen coins" ;
    for(int c : totalcoins)
    {
        cout << c << endl;
    }
}

int main()
{
    int v;
    cout << "Enter the value : ";
    cin >> v;

    mycoin(v);
}