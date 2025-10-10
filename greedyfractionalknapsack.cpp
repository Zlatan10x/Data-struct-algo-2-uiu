#include<bits/stdc++.h>

using namespace std;

struct Item{
    int weight,value,index;
};

bool cmp(const Item& a,const Item& b)
{
    double r1 = (double) a.value/(double) a.weight;
    double r2 = (double) b.value/(double) b.weight;

    return r1>r2;
}

double fracknap(int w,vector<Item>& items)
{
    sort(items.begin(),items.end(),cmp);
    double  totalvalue = 0.0;

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
    cin >> n ;
    int w;
    cout << "enter the space of the bag : ";
    cin >> w;

    vector <Item> items(n);

    cout << "enter the weight and the value of the items use space and enter after initiating one item";
    for(int i=0;i<n;i++)
    {
        cin >> items[i].weight >> items[i].value;
        items[i].index = i+1;

    }
    double maxvalue = fracknap(w, items);
    cout << maxvalue << endl;

    return 0;
}


