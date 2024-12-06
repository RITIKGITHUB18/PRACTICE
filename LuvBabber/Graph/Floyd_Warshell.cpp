
#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adj;
    void addEdge(T u, T v, T wt, bool direction)
    {
        if (direction)
        {
            adj[u].push_back({v, wt});
        }
        else
        {
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> { ";
            for (auto j : adj[i.first])
            {
                cout << "(" << j.first << ",";
                cout << j.second << "), ";
            }
            cout << "}" << endl;
        }
    }

    void floydWarshal(T n)
    {
        vector<vector<T>> dist(n, vector<T>(n, 1e9));
        // diagonal pr 0
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        // kuch weights graph k andr bhi given honge
        // update dist array accordingly

        for (auto a : adj)
        {
            for (auto b : a.second)
            {
                T u = a.first;
                T v = b.first;
                T wt = b.second;
                dist[u][v] = wt;
            }
        }

        // Main Logic- helper logic
        for (T helper = 0; helper < n; helper++)
        {
            for (T src = 0; src < n; src++)
            {
                for (T dest = 0; dest < n; dest++)
                {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 3, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(3, 2, 2, 1);
    g.addEdge(2, 1, 1, 1);

    g.printAdj();
    g.floydWarshal(4);
    return 0;
}
