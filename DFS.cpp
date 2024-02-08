// DFS (Depth First Search) in DSA

#include <iostream>
#include <map>
#include <list>

using namespace std;

// Graph class represents a directed graph
// using adjacency list representation

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int V);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int V)
{
    // Mark the current node as visited and
    // print it

    visited[V] = true;
    cout << V << " ";

    // Recur for all the vertices adjacent
    // to this vertex

    list<int>::iterator i;

    for (i = adj[V].begin(); i != adj[V].end(); i++)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";

    g.DFS(2);

    return 0;
}