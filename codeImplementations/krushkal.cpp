#include <iostream>
#include <vector>
#include <algorithm>

#define NUM_VERTICES 4

using namespace std;

class Edge {
    public:
        int src, dest, weight;
    };

    class Graph {
    public:
        int numVertices, numEdges;
        vector<Edge> edges;

        Graph(int numVertices, int numEdges) {
            this->numVertices = numVertices;
            this->numEdges = numEdges;
        }

        void addEdge(int u, int v, int w) {
            Edge edge;
            edge.src = u;
            edge.dest = v;
            edge.weight = w;
            edges.push_back(edge);
        }

        int find(vector<int>& parent, int i) {
            if (parent[i] == i)
                return i;
            return find(parent, parent[i]);
        }

        void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
            int xroot = find(parent, x);
            int yroot = find(parent, y);

            if (rank[xroot] < rank[yroot])
                parent[xroot] = yroot;
            else if (rank[xroot] > rank[yroot])
                parent[yroot] = xroot;
            else {
                parent[yroot] = xroot;
                rank[xroot]++;
            }
        }

        void KruskalMST() {
            vector<Edge> result;
            int e = 0;
            int i = 0;

            sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
                return a.weight < b.weight;
            });

            vector<int> parent(numVertices);
            vector<int> rank(numVertices, 0);

            for (int v = 0; v < numVertices; ++v)
                parent[v] = v;

            while (e < numVertices - 1 && i < edges.size()) {
                Edge next_edge = edges[i++];

                int x = find(parent, next_edge.src);
                int y = find(parent, next_edge.dest);

                if (x != y) {
                    result.push_back(next_edge);
                    Union(parent, rank, x, y);
                    e++;
                }
            }

            cout << "Following are the edges in the constructed MST\n";
            for (auto edge : result)
                cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        }
};

int main() {
    int graph[NUM_VERTICES][NUM_VERTICES] = {
        {0, 1, 3, 0},
        {1, 0, 3, 6},
        {3, 3, 0, 2},
        {0, 6, 2, 0}
    };

    Graph g(NUM_VERTICES, 0);

    for (int i = 0; i < NUM_VERTICES; ++i) {
        for (int j = i + 1; j < NUM_VERTICES; ++j) {
            if (graph[i][j] != 0) {
                g.addEdge(i, j, graph[i][j]);
            }
        }
    }

    g.KruskalMST();

    return 0;
}

