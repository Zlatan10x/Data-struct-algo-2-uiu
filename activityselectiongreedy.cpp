#include<bits/stdc++.h>
using namespace std;

struct Active
{
    int start,finish,index;
};

bool cmp(const Active& a,const Active& b)
{
    return a.finish < b.finish;
}

vector<int> selection(vector<Active> activities)
{
    sort(activities.begin(),activities.end(),cmp);

    vector<int> selected;
    int lastfinish = 0;

    for(const Active act : activities)
    {
        if(act.start>=lastfinish)
        {
            selected.push_back(act.index);
            lastfinish = act.finish;
        }
    }
    return selected;

}

int main()
{
     int n;
    cout << "enter the number of activies : ";

    cin >> n;

    vector<Active> activities(n);
    cout << "Enter start and finish of each activity (0 3) : ";
    for(int i=0;i<n;i++)
    {
        cin >> activities[i].start >> activities[i].finish;
        activities[i].index = i+1;
    }

    vector<int> maxvalue = selection(activities);
    cout << "Selected activities :";
    for(int idx : maxvalue)
    {
        cout << idx << "" ;
     cout << endl;
    }
    return 0;
}