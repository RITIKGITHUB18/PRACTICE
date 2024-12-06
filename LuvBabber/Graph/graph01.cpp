// #include <bits/stdc++.h>
// using namespace std;

// class Graph
// {
// public:
//     unordered_map<int, list<int>> adjlist;

//     void addEdge(int u, int v, bool direction)
//     {
//         // direction->0->Undirected
//         // direction->1-> directed

//         if (direction == 1)
//         {

//             // u se v ki taraf ek edge hai
//             // u -> v
//             adjlist[u].push_back(v);
//         }
//         else
//         {
//             // direction == 0 in this we have to connect both back and fro
//             // u --> v
//             adjlist[u].push_back(v);
//             // u <-- v;
//             adjlist[v].push_back(u);
//         }
//         cout << "\nPrinting AdjList" << endl;
//         printAdjList();
//         cout << "\n";
//     }

//     void printAdjList()
//     {
//         for (auto i : adjlist)
//         {
//             cout << i.first << "-> {";
//             for (auto neighbour : i.second)
//             {
//                 cout << neighbour << ", ";
//             }
//             cout << "}" << endl;
//         }
//     }
// };

// int main()
// {
//     Graph g;
//     g.addEdge(0, 1, 0);
//     g.addEdge(1, 2, 0);
//     g.addEdge(1, 3, 0);
//     g.addEdge(2, 3, 0);

//     return 0;
// }

// GRAPH - WITH WEIGHTS

#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<pair<T, T>>> adjList;

    void addEdge(T u, T v, int wt, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        if (direction == 1)
        {
            // u->v;
            adjList[u].push_back(make_pair(v, wt));
        }
        else
        {
            // direction =0
            // u-----v
            // u ---> v
            adjList[u].push_back({v, wt});
            // u <--- v
            adjList[v].push_back({u, wt});
        }

        cout << "\n Printing adjList with weights\n";
        printAdjList();
        cout << "\n";
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> { ";
            for (pair<T, int> p : i.second)
            {
                cout << "{ " << p.first << ", " << p.second << "}, ";
            }

            cout << "}\n";
        }
    }

    void bfsTraversal(T srcNode)
    {
        // adjlist already data member m hai
        // visited array
        unordered_map<T, bool> vis;
        // Queue
        queue<T> q;
        q.push(srcNode);
        vis[srcNode] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            // go to neighbour
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;

                if (!vis[nbrData])
                {
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }

    void disBfsTraversal(T srcNode, unordered_map<T, bool> &visi)
    {
        // adjlist already data member m hai

        // Queue
        queue<T> q;
        q.push(srcNode);
        visi[srcNode] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            // go to neighbour
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;

                if (!visi[nbrData])
                {
                    q.push(nbrData);
                    visi[nbrData] = true;
                }
            }
        }
    }

    // !DFS
    void dfs(T src, unordered_map<char, bool> &visi)
    {
        visi[src] = true;
        cout << src << " ";

        for (auto nbr : adjList[src])
        {
            T nbrData = nbr.first;
            if (!visi[nbrData])
            {
                dfs(nbrData, visi);
            }
        }
    }
};

int main()
{
    Graph<char> g;
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a', 'c', 3, 0);
    g.addEdge('c', 'd', 20, 0);
    g.addEdge('c', 'e', 8, 0);
    g.addEdge('d', 'e', 8, 0);
    g.addEdge('e', 'f', 8, 0);

    g.bfsTraversal('a');

    cout << "\n Printing DFS: " << endl;
    unordered_map<char, bool> visi;
    g.dfs('a', visi); //* By same way we can call it for disconnected graph as given below

    // above code will get failed in case of disconnected graph
    // for example;
    // cout << "\n Disconnected graph " << endl;

    // g.addEdge('a', 'b', 5, 0);
    // g.addEdge('b', 'c', 10, 0);

    // g.addEdge('d', 'e', 5, 0);

    // g.addEdge('f', 'g', 50, 0);

    // unordered_map<char, bool> visi;
    // for (char srcNode = 'a'; srcNode <= 'f'; srcNode++)
    // {
    //     if (!visi[srcNode])
    //     {
    //         g.disBfsTraversal(srcNode, visi);
    //     }
    // }
    return 0;
}
