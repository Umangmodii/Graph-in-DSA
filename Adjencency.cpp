// Graph in Adjacency List 

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// Create a class
class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // Direction = 0 -> Undirected Graph
        // Direction = 1 -> Directed Graph

        adj[u].push_back(v);

        // Check Direction;

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // Print Adj List

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";

            for (auto j : i.second)
            {
                cout << j << ", ";
            }

            cout << endl;
        }
    }
};

// Create a Unordered_map

int main()
{
    int n;

    cout << "Enter the Number of Nodes : " << endl;
    cin >> n;

    int m;

    cout << "Enter the Number of Edges : " << endl;
    cin >> m;

    // Create a Graph
    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;

        cin >> u >> v;

        // Creating an Undireced Graph

        g.addEdge(u, v, 0);
    }

    // Printing graph
    g.printAdjList();

    return 0;
}


// Output 

// Enter the Number of Nodes : 
// 5 
// Enter the Number of Edges : 
// 5
// 0 1
// 1 2
// 2 3
// 4 5
// 6 2

// Adjacency List Representation:

// 6 -> 2,
// 5 -> 4,
// 4 -> 5,
// 0 -> 1,
// 1 -> 0, 2,
// 2 -> 1, 3, 6,
// 3 -> 2,