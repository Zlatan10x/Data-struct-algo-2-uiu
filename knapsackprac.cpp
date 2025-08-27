#include<bits/stdc++.h>

using namespace std;

struct Item {
    double weight,value,index;
};

bool cmp(const Item& a,const Item& b)
{
    double r1 = a.value/a.weight;
    double r2 = b.value/b.weight;
    return r1>r2;
}

double fractionalknapsack(int w,vector<Item>& items)
{
    sort(items.begin(),items.end(),cmp);
    double totalvalue = 0.00;
    for(const Item& it : items)
    {
        if(w >= it.weight)
        {
            w -= it.weight;
            totalvalue += it.value;
        }

        else 
        {
            double fraction = (double) w/it.weight;
            totalvalue += it.value*fraction;
            w = 0;
            break;
        }
    }
    return totalvalue;
}

int main()
{
    int n;
    cout << "enter the number of items : ";

    cin >> n;

    int w;
    cout << "Enter how much weight can the bag take in total : ";
    cin >> w;

    vector<Item> items(n);
    cout << "Enter weight and value of each item (10 7) : ";
    for(int i=0;i<n;i++)
    {
        cin >> items[i].weight >> items[i].value;
        items[i].index = i+1;
    }

    double maxvalue = fractionalknapsack(w,items);
    cout << maxvalue << endl;  
    return 0;
}