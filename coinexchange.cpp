#include<bits/stdc++.h>
using namespace std;

int mycoin(int v)
{
    vector<int> coins = {1000,500,100,50,20,10,5,2,1};
    vector<int> result;
    
    for(int coin : coins)
    {
        if(v>=coin)
        {
            v-=coin;
            result.push_back(coin);
        }

    }
    cout << result.size() << " coins needed " << endl;
    cout << "The coins are : ";
    for(int c : result)
    {
        cout << c << "";
       cout << endl;
    }
}

int main()
{
    int v;
    cout << "Enter the amount : ";
    cin >> v;

    mycoin(v);

}