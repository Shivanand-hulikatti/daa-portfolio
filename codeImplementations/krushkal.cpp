#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Initially, each node is its own parent
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // Path compression
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Union by rank: Attach smaller rank tree under larger rank tree
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Kruskal's Algorithm to find MST
int kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.weight < b.weight;  // Sort edges by their weights
    });

    DisjointSet ds(V);
    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (const auto& edge : edges) {
        int u = edge.u, v = edge.v, weight = edge.weight;

        // If u and v are in different sets, include this edge in MST
        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            mstEdges.push_back(edge);
            mstWeight += weight;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (const auto& e : mstEdges) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    return mstWeight;
}

int main() {
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mstWeight = kruskal(V, edges);
    cout << "Weight of the Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}
