#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

    int V = 5;

    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<int> key(V, INT_MAX);
    vector<bool> mst(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        for (int v = 0; v < V; v++) {
            if (!mst[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        mst[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !mst[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "Minimum cost = " << totalCost << endl;

    return 0;
}
