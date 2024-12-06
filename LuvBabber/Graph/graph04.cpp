#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction -1 - directed
        //  direction - 0 -undirected

        if (direction == 1)
        {
            adj[u].push_back({v, wt});
        }
        else
        {
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << ": { ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    void topoOrderDfs(int src, stack<int> &topo, unordered_map<int, bool> &vis)
    {
        vis[src] = true;

        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;

            if (!vis[nbrNode])
            {
                topoOrderDfs(nbrNode, topo, vis);
            }
        }

        topo.push(src);
    }

    void shortestPathDfs(stack<int> &topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        // initially, maintain src
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        // update nbr distance for this src node
        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        // Apply the same above concept for all the remaining node
        // in the topo ordering
        while (!topoOrder.empty())
        {
            int src = topoOrder.top();
            topoOrder.pop();

            for (auto nbrPair : adj[src])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (dist[src] + nbrDist < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }

        // add mera distance array ekdum tyaar hai
        cout << "Printing the distcance array:" << endl;
        for (auto i : dist)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);

    g.printAdjList();

    int src = 0;
    stack<int> topoOrder;
    unordered_map<int, bool> vis;
    g.topoOrderDfs(src, topoOrder, vis);

    // cout << "Printing topo order" << endl;
    // while (!topoOrder.empty())
    // {
    //     cout << topoOrder.top() << " ";
    //     topoOrder.pop();
    // }

    int n = 5;
    g.shortestPathDfs(topoOrder, n);

    return 0;
}
