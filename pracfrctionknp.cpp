#include<bits/stdc++.h>
using namespace std;

struct Knap
{
    int weight,value;
};

bool cmp(const Knap &a,const Knap &b)
{
    double r1 = (double) a.weight/a.value;
    double r2 = (double) b.weight/b.value;
    return r1<r2;
}

double knapsack(int w,vector<Knap> items)
{
    sort(items.begin(),items.end(),cmp);
    double totalvalue = 0.0;

    for(const Knap it : items)
    {
        if(w>it.weight)
        {
            w -= it.weight;
            totalvalue += it.value;
        }
        else
        {
            double fraction =(double) w/it.weight;
            totalvalue += it.value*fraction;
            w = 0;
            break;
        }

    }
    return totalvalue;
}

int main()
{
    int w,n;
    cout << "Enter the size of the bag : ";
    cin >> w;
    cout << "enter the number of items you wanna check : ";
    cin >> n;

    vector<Knap> items(n);
    cout << "Enter the weight and value of the items(10 15) : ";
    for(int i=0;i<n;i++)
    {
        cin >> items[i].weight >> items[i].value;
    }

    double res = knapsack(w,items);
    cout << res << endl;
    return 0;
}