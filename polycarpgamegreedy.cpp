#include<bits/stdc++.h>
using namespace std;

bool makesword(int &a,int &b)
{
    if(a>=2 && b>=1)
    {
        a-=2;
        b-=1;
        return true;
    }
    else
    {
        return false;
    }
}
bool makeshovel(int &a,int &b)
{
    if(a>=1 && b>=2)
    {
        a -= 1;
        b -= 2;
        return true;
    }
    else 
    {
        return false;
    }
}

int tools(int a,int b)
{
    int tool = 0;
    while(a>=1 && b>=1 && a+b>=3)
    {
        if(a>b)
        {

            if(makesword(a,b)) tool++;
            else if(makeshovel(a,b)) tool++;
        }
        else 
        {
            if(makeshovel(a,b)) tool++;
            else if (makesword(a,b)) tool++;
        }
    }
    return tool;
}

int main()
{
    int a,b;
    cout << "enter the number of diamonds : ";
    cin >> a;
    cout << " Enter the number of sticks : ";
    cin >> b;

    int res = tools(a,b);
    cout << res << "dollars were made " << endl;
}