#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjlist;

    void addEdge(int u, int v, bool direction)
    {
        // direction->0->Undirected
        // direction->1-> directed

        if (direction == 1)
        {

            // u se v ki taraf ek edge hai
            // u -> v
            adjlist[u].push_back(v);
        }
        else
        {
            // direction == 0 in this we have to connect both back and fro
            // u --> v
            adjlist[u].push_back(v);
            // u <-- v;
            adjlist[v].push_back(u);
        }
        cout << "\nPrinting AdjList" << endl;
        printAdjList();
        cout << "\n";
    }

    void printAdjList()
    {
        for (auto i : adjlist)
        {
            cout << i.first << "-> {";
            for (auto neighbour : i.second)
            {
                cout << neighbour << ", ";
            }
            cout << "}" << endl;
        }
    }

    bool checkCycleUndirectedBFS(int src)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjlist[frontNode])
            {
                if (parent[frontNode] == nbr)
                {
                    continue;
                }
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if (visited[nbr] == true)
                {
                    // cyclic condition
                    return true;
                }
            }
        }
        return false; // i.e cycle not present
    }

    bool checkCycleUndirectedDFS(int src, unordered_map<int, bool> &visited, int parent)
    {

        visited[src] = true;
        for (auto nbr : adjlist[src])
        {
            if (nbr == parent)
            {
                continue;
            }
            if (!visited[nbr])
            {
                if (checkCycleUndirectedDFS(nbr, visited, src))
                {
                    return true;
                };
            }
            else if (visited[nbr] == true)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 6, 0);
    int src = 1;

    // bool isCyclic = g.checkCycleUndirectedBFS(src);

    // if (isCyclic)
    // {
    //     cout << "Cycle Present" << endl;
    // }
    // else
    // {
    //     cout << "Cycle Absent" << endl;
    // }

    unordered_map<int, bool> visited;
    int parent = -1;
    bool isCyclicDFS = g.checkCycleUndirectedDFS(src, visited, parent);
    if (isCyclicDFS)
    {
        cout << "Cycle Present" << endl;
    }
    else
    {
        cout << "Cycle Absent" << endl;
    }

    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(2, 4, 0);
    // g.addEdge(3, 4, 0);
    // g.addEdge(2, 5, 0);
    // int src = 0;
    // bool isCyclic = g.checkCycleUndirectedBFS(src);

    // if (isCyclic)
    // {
    //     cout << "Cycle Present" << endl;
    // }
    // else
    // {
    //     cout << "Cycle Absent" << endl;
    // }

    return 0;
}
