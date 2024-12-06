// node - time - curr Time ->tin=time of insertion
//         |_    low ->Lowest time to reach this node

#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        if (direction)
        {
            adj[u].push_back(v);
        }
        else
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for (auto a : adj)
        {
            cout << a.first << "->{ ";
            for (auto b : a.second)
            {
                cout << b << ", ";
            }
            cout << "}" << endl;
        }
    }

    void solve(int src, int parent, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis, int &timer)
    {
        // tin= dfs time insertion
        // low = min lowest time insertion of all adjacent node apart from parent
        tin[src] = timer;
        low[src] = timer;
        vis[src] = true;
        timer++;

        for (auto nbr : adj[src])
        {
            if (nbr == parent)
            {
                continue;
            }
            if (!vis[nbr])
            {
                // step-1
                solve(nbr, src, tin, low, vis, timer);
                // step-2: update the low of parent based on its child
                low[src] = min(low[src], low[nbr]);
                // step-3:bridge testing
                if (low[nbr] > tin[src])
                {
                    cout << "src: " << src << " nbr: " << nbr << endl;
                }
            }
            else
            {
                // If nbr is already visited it means we got one more path,
                // It means no need to test for bridge,
                // Just only update the low,
                low[src] = min(low[src], low[nbr]);
            }
        }
    }

    void bridgeInGraph(int n)
    {
        unordered_map<int, bool> vis;
        int timer = 0;
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        int src = 0;
        int parent = -1;

        solve(src, parent, tin, low, vis, timer);
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 0, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(2, 5, 0);

    g.printAdj();
    int n = 4;
    g.bridgeInGraph(n);
    return 0;
}
