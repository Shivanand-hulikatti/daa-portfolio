#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX

// Min-heap comparison for priority queue
struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

void dijkstra(int V, vector<vector<pair<int, int>>>& adj, int source) {
    vector<int> dist(V, INF);  // Distance array
    dist[source] = 0;  // Distance to source is 0

    // Priority queue to select the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({source, 0});  // Start with source vertex

    while (!pq.empty()) {
        int u = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        // If the distance is already greater, no need to process
        if (d > dist[u]) continue;

        // Relax all neighbors of vertex u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;  // Neighbor vertex
            int weight = neighbor.second;  // Edge weight

            // If the path through u offers a shorter distance, update it
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            cout << i << ": INF\n";
        } else {
            cout << i << ": " << dist[i] << "\n";
        }
    }
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Example graph with 5 vertices
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({0, 7});
    adj[3].push_back({2, 6});
    adj[4].push_back({1, 3});
    adj[4].push_back({3, 9});

    int source = 0;  // Start Dijkstra from vertex 0
    dijkstra(V, adj, source);

    return 0;
}
