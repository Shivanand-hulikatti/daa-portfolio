#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> iPair;

void dijkstra(vector<vector<iPair>>& graph, int src) {
    int V = graph.size();
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V = 5;
    vector<vector<iPair>> graph(V);

    graph[0].push_back(make_pair(1, 9));
    graph[0].push_back(make_pair(2, 6));
    graph[0].push_back(make_pair(3, 5));
    graph[0].push_back(make_pair(4, 3));
    graph[2].push_back(make_pair(1, 2));
    graph[2].push_back(make_pair(3, 4));

    int src = 0;
    dijkstra(graph, src);

    return 0;
}