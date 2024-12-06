/**
 *
 * You are given the source vertex S and
 * You have to Find the shortest distance of all the vertex from the source vertex S.
 * You have to return a list of integers denoting the shortest distance between each node and
 * the Source vertex S.
 */

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // weights
    // direction
    // src node u
    // destination node v
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int wt, bool direction)
    {
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

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << ": {";
            for (auto nbr : adj[i.first])
            {
                cout << "(" << nbr.first << ", " << nbr.second << ") ";
            }
            cout << "} " << endl;
        }
    }

    void dijkstraShortestDistance(int n, int src, int dest)
    {
        vector<int> dist(n + 1, INT_MAX);

        set<pair<int, int>> st;
        // set<pair<dist,node>>st;

        // INITIAL STATE (srcDist,srcNode)
        st.insert({0, src});
        dist[src] = 0;

        // distance updation logic
        while (!st.empty())
        {
            auto topElement = st.begin();
            pair<int, int> topPair = *topElement;

            int topDist = topPair.first;
            int topNode = topPair.second;
            // remove the topElement from the set;

            st.erase(st.begin());

            // Update distance from nbr
            for (pair<int, int> nbrPair : adj[topNode])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if (topDist + nbrDist < dist[nbrNode])
                {
                    // FOUND A NEW SHORTER DISTANCE
                    // NOW UPDATE :
                    // SET KI ENTRY
                    // TO UPDATE THE ENTRY FIRST WE HAVE TO ERASE THE EXISTING NODE AND THEN ADD NEW ONE
                    auto previousEntry = st.find({dist[nbrNode], nbrNode});
                    if (previousEntry != st.end())
                    {
                        // entry present in a set
                        st.erase(previousEntry);
                    }

                    // DIST KA ARRAY
                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        for (int d = 1; d < dist.size(); d++)
        {
            cout << dist[d] << ", ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 7, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 6, 14, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(3, 6, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);

    g.printAdj();
    int n = 6;
    int src = 1;
    int dest = 4;
    g.dijkstraShortestDistance(n, src, dest);
    return 0;
}
