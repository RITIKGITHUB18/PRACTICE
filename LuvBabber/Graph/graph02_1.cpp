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

    bool checkCycleDirectedDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsTrack)
    {
        visited[src] = true;
        dfsTrack[src] = true;

        for (auto nbr : adjlist[src])
        {
            if (!visited[nbr])
            {
                bool ans = checkCycleDirectedDFS(nbr, visited, dfsTrack);
                if (ans)
                {
                    return true;
                }
            }
            if (visited[nbr] == 1 && dfsTrack[nbr] == 1)
            {
                return true;
            }
        }

        dfsTrack[src] = false;
        return false;
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 1);
    g.addEdge(7, 5, 1);

    int src = 1;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsTrack;
    int parent = -1;
    bool isCyclicDFS = g.checkCycleDirectedDFS(src, visited, dfsTrack);
    if (isCyclicDFS)
    {
        cout << "Cycle Present" << endl;
    }
    else
    {
        cout << "Cycle Absent" << endl;
    }

    return 0;
}
