#include<bits/stdc++.h>

using namespace std;

class Disjointset{
    private :
        vector<int> parent;
        vector<int> rank;

    public :
        Disjointset(int n)
        {
            parent.resize(n);
            rank.resize(n,0);
            makeSet(n);
        }

        void makeSet(int n)
        {
            for(int i=0;i<n;i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int findset(int v)
        {
            if(v != parent[v]){
                parent[v] = findset(parent[v]);
            }
            return parent[v];
        }
        
        void unionsets(int a,int b)
        {
            a = findset(a);
            b = findset(b);
            if(a!=b)
            {
                if(rank[a] < rank[b])
                
                    swap(a,b);
                parent[b] = a;
                if(rank[a]==rank[b])
                {
                    rank[a]++;
                }
                
            }
        }
        void printparent()
        {
            cout << "parent array : ";
            for(int i=0;i<parent.size();i++)
            {
                cout << parent[i] << "";
            }
            cout << endl;
        }

};

int main()
{
    int n = 7;
    Disjointset ds(n);

    ds.unionsets(0,1);
    ds.unionsets(1,2);
    ds.unionsets(3,4);
    ds.unionsets(5,6);
    ds.unionsets(4,5);
    

    ds.printparent();

    cout << "Findset(2)" << ds.findset(2) << endl;

    cout << "Findset(6)" << ds.findset(6) << endl;

    if(ds.findset(2)==ds.findset(6))
    {
        cout << "2 and 6 belong to the same set" << endl;
    }
    else
    cout << "2 and 6 are from different sets" << endl;

    return 0;
}