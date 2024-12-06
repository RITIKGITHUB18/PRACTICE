#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, list<int>> revAdjlist;

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

    void revAdj()
    {

        for (auto src : adjlist)
        {
            int u = src.first;
            for (auto v : src.second)
            {
                revAdjlist[v].push_back(u);
            }
        }
    }

    void printRevAdjList()
    {
        for (auto i : revAdjlist)
        {
            cout << i.first << "-> {";
            for (auto neighbour : i.second)
            {
                cout << neighbour << ", ";
            }
            cout << "}" << endl;
        }
    }

    vector<int> eventualSafeNode(int start, int end)
    {
        map<int, int> indeg;

        for (auto i : revAdjlist)
        {
            indeg[i.first];
            for (auto nbr : i.second)
            {
                indeg[nbr]++;
            }
        }

        for (auto i : indeg)
        {
            cout << "Indegree of " << i.first << " is " << i.second << endl;
        }

        queue<int> q;
        vector<int> safeNode;
        for (int i = start; i <= end; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : revAdjlist[frontNode])
            {
                indeg[nbr]--;
                if (indeg[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
            safeNode.push_back(frontNode);
        }

        sort(safeNode.begin(), safeNode.end());
        return safeNode;
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

    int V = 8;

    g.printAdjList();
    cout << "After reversing" << endl;
    g.revAdj();
    g.printRevAdjList();
    int start = 1;
    int end = 8;
    vector<int> ans = g.eventualSafeNode(start, end);

    cout << "Eventual Safe Node" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
