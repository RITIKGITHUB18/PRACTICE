/**
 * Disjoint Set:- Data structure to find two nodes are in same component or not
 * in disjoint set there are two operation:
 *  1. Find parent or find set
 *  2. Find union or union set
 * union can be done by method called
 *  union by rank & path compression
 * init, every component as its own parent
 *  rank     [0,2,0,0,3,0,1,0,0]
 *  index     0 1 2 3 4 5 6 7 8
 *
 *  union (1,2)
 *  union (2,3)
 *  union (4,5)
 *  union (6,7)
 * union (5,6)
 * union(3,7)
 * NODE | PARENT | Rank of parent
 *  1       1           0
 *  2       2           0
 *  1,2     1           1->2 union(1,2)
 *  3       3           0
 *  1,2,3   1           0    union(2,3)
 *  4       4           0
 *  5       5           0
 *  6       6           0
 *  7       7           0
 *  4,5     4           1->2  union(4,5)
 *  6,7     6           1     union(6,7)
 *  5,6     4           2     union(5,6) // 4,5,6,7
 *  3,7     4           3     union(3,7) // 1,2,3,4,5,6,7
 *
 *
 * in kruskal we don't want adjlist we need linear data structure
 * (w,u->v) -> edge with weights
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    static bool mycmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

public:
    unordered_map<int, list<pair<int, int>>> adjList;

    // graph creation

    void createGraph(int u, int v, int w, bool direction)
    {
        // direction = 0 undirected graph
        // direction = 1 directed graph

        if (direction == 1)
        {
            adjList[u].push_back({v, w});
        }
        else
        {
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
    }

    void printGraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> {";
            for (pair<int, int> nbr : i.second)
            {
                cout << "(" << nbr.first << "," << nbr.second << "), ";
            }

            cout << "}" << endl;
        }
    }

    int findParent(vector<int> &parent, int node)
    {
        // Base case
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent, parent[node]); // path compression
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) // Time complexity of union is O(4alpha) and alpha is very close to 1. Not required to know about alpha
    {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (rank[u] < rank[v])
        {
            parent[u] = v;
            rank[v]++;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    // A spanning tree is a tree in which we have N nodes(i.e. All the nodes present in the original graph) and N-1 edges and all nodes are reachable from each other.

    int minimumSpanningTree(int node)
    {
        vector<int> parent(node);
        vector<int> rank(node, 0);

        // make all nodes as individual component by setting up them as a parent of their own node
        for (int u = 0; u < node; u++)
        {
            parent[u] = u;
        }

        // make edges to weight list and store it in linear DS
        vector<vector<int>> edges;
        for (int u = 0; u < node; u++)
        {
            for (auto edge : adjList[u])
            {
                int v = edge.first;
                int w = edge.second;
                edges.push_back({u, v, w});
            }
        }

        // Now sort the edges list in increasing order of their weight
        sort(edges.begin(), edges.end(), mycmp);
        int totalwt = 0;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            u = findParent(parent, u);
            v = findParent(parent, v);
            if (u != v)
            {
                // union
                unionSet(u, v, parent, rank);
                totalwt += w;
            }
        }
        return totalwt;
    }
};

int main()
{
    Graph g;
    g.createGraph(0, 1, 5, 0);
    g.createGraph(0, 2, 1, 0);
    g.createGraph(1, 2, 3, 0);
    g.printGraph();
    int node = 3;
    int minimumTree = g.minimumSpanningTree(node);
    cout << "Weight of minimum spanning tree is: " << minimumTree << endl;
}