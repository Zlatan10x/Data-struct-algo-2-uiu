#include<bits/stdc++.h>
using namespace std;

struct Knap{
    double weight,value;
};

bool cmp(const Knap &a,const Knap &b)
{
    double r1 = (double) a.weight/a.value;
    double r2 = (double) b.weight/b.value;

    return r1<r2;
}

double Knapsack(int w,vector<Knap> items)
{
    sort(items.begin(),items.end(),cmp);

    double total = 0.0;

    for(const Knap it : items)
    {
        if(w>it.weight)
        {
            w -= it.weight;
            total += it.value;
        }
        else
        {
            double fraction = (double) w/it.weight;
            total += it.value*fraction;
            w = 0;
            break;
        }
    }
    return total;
}

int main()
{
    int w,n;
    cout << "enter the size of the bag : ";
    cin >> w;
    cout << "enter the number of items :";
    cin >> n;
    vector<Knap> items(n);
    cout << "enter the weight and the value of each itmes (10 5) :";
    for(int i=0;i<n;i++)
    {
        cin >> items[i].weight >> items[i].value;
    }
    double totalvalue = Knapsack(w,items);

    cout << totalvalue << endl;
    
    return 0;
}