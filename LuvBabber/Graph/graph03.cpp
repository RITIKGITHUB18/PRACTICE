#include <bits/stdc++.h>
using namespace std;

// * Topological sort:- A linear ordering of vertices such that for edge u->v, u comes before v in that ordering
// * And topological sort can only be executed over Directed Acyclic graph(DAG)

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // Direction-> 0 undirected
        // Direction-> 1 directed
        if (direction == 1)
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
        for (auto i : adj)
        {
            cout << i.first << "-> { ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << "} " << endl;
        }
    }

    void topSortDfs(int src, map<int, bool> &vis, stack<int> &st)
    {
        vis[src] = true;

        for (auto nbr : adj[src])
        {
            if (!vis[nbr])
            {
                topSortDfs(nbr, vis, st);
            }
        }

        st.push(src);
    }

    //* Topological ordering using BFS here we have to maintain the degree chart of each node
    //* and we will only push that node whose in-degree is 0 (i.e. Independent Node) in the queue,
    //* so initially root node is having the 0 in-degree and after that we will reduce the degree of its immidiate child node by 1

    void topSortBfs(int n)
    {
        queue<int> q;
        map<int, int> indegree;

        // Initialize the indegree
        for (auto i : adj)
        {
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // By printing the indegree the degree of each node
        for (auto i : indegree)
        {
            cout << i.first << "->" << i.second << endl;
        }

        // Now push all zero indegree wali node into queue
        for (int node = 0; node < n; node++)
        {
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }

        // BFS chalate hai
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            for (auto nbr : adj[frontNode])
            {
                indegree[nbr]--;

                // check for zero
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }

    // Shortest Path
    void shortestPathBfs(int src, int dest)
    {
        queue<int> q;
        map<int, bool> vis;
        map<int, int> parent;

        // initial state
        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for (auto nbr : adj[frontNode])
            {
                if (!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }

        // parent araay tyaar hoga
        vector<int> ans;
        while (dest != -1)
        {
            ans.push_back(dest);
            dest = parent[dest];
        }

        reverse(ans.begin(), ans.end());

        for (auto i : ans)
        {
            cout << i << ", ";
        }
    }
};

int main()
{
    Graph g;
    // for topological sort
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(5, 7, 1);

    g.printAdj();
    int n = 8;
    g.topSortBfs(n);
    cout << endl;

    // * Topological sort using DFS
    // int n = 8;
    // map<int, bool> vis;
    // stack<int> st;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!vis[i])
    //     {
    //         g.topSortDfs(i, vis, st);
    //     }
    // }

    // cout << "Printing the toplogical order:";
    // while (!st.empty())
    // {
    //     cout << st.top() << ", ";
    //     st.pop();
    // }

    //* Finding the shortest path
    Graph g1;
    g1.addEdge(0, 5, 0);
    g1.addEdge(5, 4, 0);
    g1.addEdge(4, 3, 0);
    g1.addEdge(0, 6, 0);
    g1.addEdge(6, 3, 0);
    g1.addEdge(0, 1, 0);
    g1.addEdge(1, 2, 0);
    g1.addEdge(2, 3, 0);
    g1.printAdj();
    int node = 7;
    int src = 0;
    int dest = 3;
    cout << "Printing Shortest path using BFS: " << endl;
    g1.shortestPathBfs(src, dest);

    return 0;
}
