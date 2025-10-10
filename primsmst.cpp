#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

void primMST(int V, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    key[0] = 0;
    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += key[u];

        for (auto& it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " (" << key[i] << ")\n";

    cout << "Total weight = " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    primMST(V, adj);
    return 0;
}
