#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

int findParent(int u, vector<int>& parent) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u], parent);
}

bool unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (pu == pv) return true; // cycle found

    if (rank[pu] < rank[pv]) swap(pu, pv);
    parent[pv] = pu;
    if (rank[pu] == rank[pv]) rank[pu]++;
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v;

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    bool hasCycle = false;
    for (auto& e : edges) {
        if (unionSets(e.u, e.v, parent, rank)) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) cout << "Cycle detected!\n";
    else cout << "No cycle in the graph.\n";

    return 0;
}
