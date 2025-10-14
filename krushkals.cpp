#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
};

// Compare function to sort edges by weight
bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

// Find parent with path compression
int findParent(int node, vector<int> &parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

// Union by rank
void unionSet(int u, int v, vector<int> &parent, vector<int> &rankv) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (pu == pv) return;

    if (rankv[pu] < rankv[pv]) parent[pu] = pv;
    else if (rankv[pu] > rankv[pv]) parent[pv] = pu;
    else {
        parent[pv] = pu;
        rankv[pu]++;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(V), rankv(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int totalWeight = 0;
    vector<pair<int, int>> mstEdges;

    for (auto &edge : edges) {
        int pu = findParent(edge.u, parent);
        int pv = findParent(edge.v, parent);

        if (pu != pv) {
            totalWeight += edge.w;
            mstEdges.push_back({edge.u, edge.v});
            unionSet(edge.u, edge.v, parent, rankv);
        }
    }

    cout << "\nTotal weight of MST (Kruskal's): " << totalWeight << endl;
    cout << "Edges in MST:\n";
    for (auto &e : mstEdges)
        cout << e.first << " - " << e.second << endl;

    return 0;
}
