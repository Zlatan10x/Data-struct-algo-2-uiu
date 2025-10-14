#include<bits/stdc++.h>

using namespace std;

struct Edge{
    int a,b;
    int w;

    double log_weight;
};

int findparent(int b,vector<int>& parent)
{
    if(b==parent[b]) return b;
    return parent[b] = findparent(parent[b],parent);
}

void unionset(int a,int b,vector<int> &parent,vector<int> &rank)
{
    a= findparent(a,parent);
    b= findparent(b,parent);

    if(a!=b)
    {
        if(rank[a]<rank[b]) swap(a,b);
        parent[b] = a;
        if(rank[a]==rank[b]) rank[a]++;
    }
}


int main()
{
    int n,m;
    cout << "Give the number of vertices : ";
    cin >> n;
    cout << "Give the number of edges : ";
    cin >> m;
    vector<Edge> edges(m);

    cout << "Now add Starting point and ending point of connected Edges :" << endl;
    cout << "Like 1 2 3(use space)\n";
    for(int i=0;i<m;i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].log_weight = log(edges[i].w);
    }

    sort(edges.begin(),edges.end(),[](Edge a,Edge b)
    {
        return a.log_weight < b.log_weight;
    });

    vector<int> parent(n),rank(n,0);
    for(int i=0;i<n;i++) parent[i] = i;

    vector<pair<int,int>> mst;
    long double product = 1;
    int edgec = 0;


    for(int i=0;i<m && edgec < n-1;i++)
    {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;

        int pa = findparent(a,parent);
        int pb = findparent(b,parent);

        if(pa!=pb)
        {
            unionset(pa,pb,parent,rank);
            mst.push_back({a,b});
            product *= w;
            edgec++;
        }
    }

    cout << "edges :\n";
    for(auto e : mst)
    {
        cout << e.first << "-" << e.second << "\n";
    }
    cout << "Minimun Product : " << product << "\n" << endl;



    return 0;

}