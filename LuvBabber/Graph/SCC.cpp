// ! Strongly Connected Component only aplicable for directed graph
/**
 * Strongly connected component generally means that
 * you can reach from u to v as well as v to u by any other path
 *
 *        0         ssc-1 [0,1,2,3]  ssc-2 [4,5,6]  ssc-3 [7]
 *      /   /\
 *     \/    \
 *     1      3 -------> 4
 *       \     /\      /  /\
 *       \/    /      \/   \
 *          2        5---->6--->7
 */

//! Kosa-raju Algorithm

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
        for (auto i : adj)
        {
            cout << i.first << "-> { ";
            for (auto j : i.second)
            {

                cout << j << ", ";
            }
            cout << "}" << endl;
        }
    }

    void dfs1(int node, stack<int> &ordering, unordered_map<int, bool> &vis)
    {
        vis[node] = true;
        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                dfs1(nbr, ordering, vis);
            }
        }
        // wapas aate wakt stack me push
        ordering.push(node);
    }

    void dfs2(int node, unordered_map<int, list<int>> &newAdj, unordered_map<int, bool> &vis2)
    {
        vis2[node] = true;
        cout << node << ", ";
        for (auto nbr : newAdj[node])
        {
            if (!vis2[nbr])
            {
                dfs2(nbr, newAdj, vis2);
            }
        }
    }

    int getStronglyConnectedComponent(int n)
    {
        // Step-1 get the ordering of node in that we execute , generally on the basis of time. using ordering we can follow a path to count the disconnected or if there is any chance, it takes back to the already traversed nodes.
        stack<int> ordering;
        unordered_map<int, bool> vis;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs1(i, ordering, vis);
            }
        }
        // Step-2 Reverse Edges
        unordered_map<int, list<int>> newAdj;
        for (auto a : adj)
        {
            for (auto b : a.second)
            {
                int u = a.first;
                int v = b;
                // v->u ki entry create krni hai
                newAdj[v].push_back(u);
            }
        }
        // Step-3 Traverse using Ordering and count components

        int cnt = 0;
        unordered_map<int, bool> vis2;
        while (!ordering.empty())
        {
            int node = ordering.top();
            ordering.pop();
            if (!vis2[node])
            {
                cout << "SSC #" << cnt + 1 << ": ";
                dfs2(node, newAdj, vis2);
                cnt++;
                cout << endl;
            }
        }
        return cnt;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);

    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);

    g.addEdge(6, 7, 1);
    g.printAdj();
    int n = 8;
    int scc = g.getStronglyConnectedComponent(n);
    cout << "No. of Strongly connected Component is:  " << scc << endl;

    return 0;
}
