#include<bits/stdc++.h>
using namespace std;

struct Rail
{
    int arrival,departure;
};

bool cmp(const Rail &a,const Rail &b)
{
    return a.departure<b.departure;
}

double arrival(vector<Rail> &time)
{
    sort(time.begin(),time.end(),cmp);

    double ltrain = 0;
    double totaltrain =0;
    for(const Rail t : time)
    {
        if(t.arrival>ltrain)
        {
            totaltrain++;
            ltrain = t.departure;
        }
    }
    return totaltrain;

}

int main()
{
    
    vector<Rail> times = {{8,12},{6,9},{11,14},{2,7},{1,7},{12,20},{7,12},{13,19}};
    
    double res = arrival(times);

    cout << res << endl;
    return 0;
}