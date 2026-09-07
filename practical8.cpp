#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> graph;

public:

    Graph(int v)
    {
        V = v;
        graph.resize(V);
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // DFS
    void DFS(int start, vector<bool>& visited)
    {
        visited[start] = true;
        cout << start << " ";

        for (int i : graph[start])
        {
            if (!visited[i])
                DFS(i, visited);
        }
    }

    // BFS
    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int i : graph[node])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    vector<bool> visited(6, false);

    cout << "DFS Traversal: ";
    g.DFS(0, visited);

    cout << "\nBFS Traversal: ";
    g.BFS(0);

    return 0;
}
