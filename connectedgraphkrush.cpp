#include <bits/stdc++.h>
using namespace std;

int findParent(int u, vector<int>& parent) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (pu == pv) return;
    if (rank[pu] < rank[pv]) swap(pu, pv);
    parent[pv] = pu;
    if (rank[pu] == rank[pv]) rank[pu]++;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        unionSets(u, v, parent, rank);
    }

    // Find unique parents
    set<int> uniqueParents;
    for (int i = 0; i < V; i++)
        uniqueParents.insert(findParent(i, parent));

    if (uniqueParents.size() == 1)
        cout << "Graph is connected.\n";
    else
        cout << "Graph is NOT connected.\n";

    return 0;
}
