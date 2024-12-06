#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<char, list<pair<char, int>>> adj;
    void addEdge(char u, char v, char wt, bool direction)
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

    void BellmonFord(int n, int src)
    {
        vector<int> dist(n, INT_MAX);
        dist[src - 'A'] = 0;

        // (n-1) times Relaxation

        for (int i = 1; i < n; i++)
        {
            for (auto i : adj)
            {
                for (auto j : i.second)
                {
                    char u = i.first;
                    char v = j.first;
                    int wt = j.second;

                    if (dist[u - 'A'] != INT_MAX && (dist[u - 'A'] + wt) < dist[v - 'A'])
                    {
                        dist[v - 'A'] = dist[u - 'A'] + wt;
                    }
                }
            }
        }

        // Yha tk shortest distance ready hai
        // check for negative cycle
        // we will run the relaxation for one more time
        bool negCycle = false;

        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                char u = i.first;
                char v = j.first;
                int wt = j.second;

                if (dist[u - 'A'] != INT_MAX && (dist[u - 'A'] + wt) < dist[v - 'A'])
                {
                    negCycle = true;
                    break;
                    dist[v - 'A'] = dist[u - 'A'] + wt;
                }
            }
        }

        if (negCycle)
        {
            cout << "Negative cycle is present" << endl;
        }
        else
        {
            cout << "No Negative cycle in graph" << endl;
            cout << "Printing Distance Array" << endl;
            for (auto i : dist)
            {
                cout << i << " ";
            }
        }

        // Printing distance array
    }

    void floydWarshal(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
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
                char u = a.first;
                char v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }

        // Main Logic- helper logic
        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int dest = 0; dest < n; dest++)
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
        }
        cout << endl;
    }
};
int main()
{
    Graph g;
    g.addEdge('A', 'B', -1, 1);
    g.addEdge('B', 'E', 3, 1);
    g.addEdge('B', 'C', 2, 1);
    g.addEdge('B', 'D', 2, 1);
    g.addEdge('C', 'D', -3, 1);
    g.addEdge('D', 'B', 1, 1);
    g.addEdge('D', 'E', 5, 1);
    g.addEdge('A', 'E', 4, 1);

    g.printAdj();
    // g.BellmonFord(5, 'A');

    return 0;
}
