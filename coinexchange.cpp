#include<bits/stdc++.h>
using namespace std;

void mycoin(int v)
{
    vector<int> coins = {1000,500,100,50,20,10,5,2,1};
    vector<int> result;

    for(int coin : coins)
    {
        if(v>=coin)
        {
            v -= coin;
            result.push_back(coin);
        }

    }
    cout << result.size() << " coins were taken " << endl;

    cout << "coins that are taken : ";
    for(int c : result)
    {
        cout << c << "" << ",";
       
    }


}
int main()
{
    int v;
    cout << "Enter the value : ";
    cin >> v;

    mycoin(v);
    return 0;
}