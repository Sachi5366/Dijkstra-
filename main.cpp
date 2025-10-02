#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (distance, node)

// Dijkstra function
void dijkstra(int V, vector<vector<pii>>& adj, int source) {
    vector<int> dist(V, INT_MAX); // Distance array
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source}); // (distance, node)

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If this distance is already bigger, skip
        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print distances
    cout << "Vertex\tDistance from Source " << source << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << dist[i] << endl;
    }
}

// Main function
int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Example graph edges: (u, v, weight)
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({0, 7});
    adj[3].push_back({2, 6});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}
