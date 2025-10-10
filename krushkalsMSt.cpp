#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int findParent(int u, vector<int>& parent) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u], parent); // Path compression
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end());

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int totalWeight = 0;
    cout << "\nEdges in MST:\n";

    for (auto& e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);
        if (pu != pv) {
            cout << e.u << " - " << e.v << " (" << e.w << ")\n";
            totalWeight += e.w;
            unionSets(pu, pv, parent, rank);
        }
    }

    cout << "Total weight of MST = " << totalWeight << endl;
    return 0;
}
