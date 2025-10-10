// N – The maximum unit of food you can buy each day.
// S – Number of days you are required to survive.
// M – Unit of food required each day to survive.
#include<bits/stdc++.h>
using namespace std;

void survival(int n,int s,int m)
{
    int totalfood = m*s;
    int shopday = s-s/7;
    int minshop = (totalfood+n-1)/n;
    if(minshop>shopday)
    {
        cout << "Survival not possible";
    }
    else 
    {
        cout << minshop << " days" << endl;
    }
}

int main()
{
    int n,s,m;
    cout << "enter the max unit of food you can buy each day :";
    cin >> n;
    cout << "enter the number of days you are required to survive :";
    cin >> s;
    cout << "enter the unit of food required each day :";
    cin >> m;

    survival(n,s,m);
}