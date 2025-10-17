#include<bits/stdc++.h>


using namespace std;

struct Edge {
    int u, v;
    double w;   
    int r_w; 
};

int findParent(int v, vector<int> &parent) {
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSets(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, log(w), w};
    }

    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    vector<pair<int, int>> mst;
    long double product = 1;
    int edgesUsed = 0;

    for (auto &e:edges) {
        if (edgesUsed == n - 1) break;
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);

        if (pu != pv) {
            unionSets(pu, pv, parent, rank);
            mst.push_back({e.u, e.v});
            product *= e.r_w;
            edgesUsed++;
        }
    }

    cout << "Edges:\n";
    for (auto &e : mst) {
        cout<<e.first<<"-"<< e.second<<"\n";
    }
    cout<< "Minimum product: " <<fixed<<setprecision(0)<< product << endl;
    return 0;
}
