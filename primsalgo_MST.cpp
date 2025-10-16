#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge;

int primMST(int V, vector<vector<pair<int, int>>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    priority_queue<edge, vector<edge>, greater<edge>> pq;

    key[0] = 0;
    pq.push({0, 0});

    int mstweight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        mstweight += key[u];

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " (weight " << key[i] << ")\n";
    }

    return mstweight;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    int totalWeight = primMST(V, adj);
    cout << "Total weight = " << totalWeight << endl;

    return 0;
}