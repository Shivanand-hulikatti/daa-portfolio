#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX  // Infinity value to represent no path

void floydWarshall(vector<vector<int>>& dist, int V) {
    // dist[i][j] will be the shortest distance from vertex i to vertex j
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k offers a shorter path from i to j, update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "Shortest distances between every pair of vertices: \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 4;  // Number of vertices in the graph
    vector<vector<int>> dist = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floydWarshall(dist, V);
    printSolution(dist, V);

    return 0;
}
