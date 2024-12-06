/**
 * To find minimum spanning tree
 * spanning tree
 * convert graph to a tree(no cycle)
 * In tree every node should be reachable by every other node
 * Tree would have 'n' node & 'n-1' edge
 *  minimum spanning tree is the tree present in the set of all the tree formed by the graph with minimum sum of available Weights
 *
 */

/**
 * Prism algorithm
 * we don't remove the edges from the graph we will be building the tree from very scratch
 * Here we required with 3 data structure
 * 1. Contains value of each node [Key array- [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]]
 * 2.Tracks which node has been included in MST as of Now MST [MST Array [f,f,f,f,f]]
 * 3.Then there will be Parent Array which stores the final structure of MST [Parent Array- [-1,-1,-1,-1,-1]]
 *
 *
 *
 * Step-1
 * find min value node from key u=0;
 * mst[u] = mst[0]=true
 * get all the adj's node of u
 * v=adj node
 * w=weight of adj node
 * if(mst[v]==f && w<key[v]){
 *      key[v] = w;
 *      parent[v] = u;
 * }
 *
 *
 * Stopping condition: If all the node is added to the MST i.e is mst array is fully marked with true
 *
 */

//! Luv babbar
/*
#include <bits/stdc++.h>
using namespace std;

class Graph
{

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

    int getMinValueNodeFromKey(vector<int> &key, vector<bool> &mst)
    {
        int index = -1; // HERE Index represent the actual value of node
        int temp = INT_MAX;
        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] < temp && mst[i] == false)
            {
                temp = key[i];
                index = i;
            }
        }

        return index;
    }

    int minimumSpanningTree(int node)
    {
        vector<int> key(node, INT_MAX);
        vector<bool> mst(node, false);
        vector<int> parent(node, -1);

        key[0] = 0;

        while (true)
        {
            // step-1
            int u = getMinValueNodeFromKey(key, mst);
            // stopping condition
            if (u == -1)
            {
                break;
            }

            // step-2 mark the mst to true;
            mst[u] = true;

            // step-3 get all the adj node of u
            for (auto edge : adjList[u])
            {
                int v = edge.first;
                int wt = edge.second;

                if (mst[v] == false && wt < key[v])
                {
                    parent[v] = u;
                    key[v] = wt;
                }
            }
        }

        int sum = 0;
        for (int u = 0; u < parent.size(); u++)
        {
            if (u == -1)
                continue;
            for (auto edge : adjList[u])
            {
                int v = edge.first;
                int wt = edge.second;
                if (v == parent[u])
                {
                    sum += wt;
                }
            }
        }
        return sum;
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
*/

// ! Striver

/*
    intuition :-
    data structure used here is
    min-heap-[wt,node,parent]
    mst- list[edge between the node]
    visited array to track the node

    step-1:
        insert 0,0,-1 at very first in the min-heap but don't marked it in mst
        take out the min of all present in the min-heap by the weight
    step-2:
        check node is marked visited or not
            if not visited marked it visited
            if visited don't perform any furthur action
    step-3:
        insert u->v in mst list to track the edge between the node
        and addup the weight to the sum
    step-4:
        insert all adjacent nbr to the min-heap
        and repeat the process till min-heap is not empty.


*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{

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
    int minimumSpanningTree(int nodes)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        //{wt,{u,parent}}
        vector<bool> vis(nodes, false);
        vector<pair<int, int>> mst;

        int mstWeight = 0;

        // starts from node 0 with weight 0 and parent =-1

        minHeap.push({0, {0, -1}});

        while (!minHeap.empty())
        {
            // Get the node with the smallest edge weight
            int weight = minHeap.top().first;
            int u = minHeap.top().second.first;
            int parent = minHeap.top().second.second;

            minHeap.pop();

            // if node is already visited, skip it
            if (vis[u])
            {
                continue;
            }

            vis[u] = true;
            if (parent != -1)
            {
                mst.push_back({parent, u});
            }

            mstWeight += weight;

            for (auto nbr : adjList[u])
            {
                int v = nbr.first;
                int wt = nbr.second;
                if (!vis[v])
                {
                    minHeap.push({wt, {v, u}});
                }
            }
        }

        // print the MST edges
        cout << "Edges in MST: " << endl;
        for (auto edge : mst)
        {
            cout << edge.first << "-" << edge.second << endl;
        }

        return mstWeight;
    }
};

int main()
{
    Graph g;
    g.createGraph(0, 1, 5, 0);
    g.createGraph(0, 2, 1, 0);
    g.createGraph(1, 2, 3, 0);
    g.createGraph(1, 3, 7, 0);
    g.createGraph(2, 3, 2, 0);

    cout << "Graph adjacency list:" << endl;
    g.printGraph();

    int nodes = 4; // Number of nodes in the graph
    int minimumTreeWeight = g.minimumSpanningTree(nodes);
    cout << "Weight of minimum spanning tree is: " << minimumTreeWeight << endl;

    return 0;
}
