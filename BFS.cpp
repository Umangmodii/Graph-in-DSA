// Breadth First Search Algorithms in DSA

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// Create a new class
class Graph
{
    int V;

    // Pointer to an array containing adjacency lists
    vector<list<int>> adj;

public:
    // Constructor
    Graph(int V);

    // Function to add an edge to graph
    void addEdge(int source, int destination);

    // Prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;

    // Store the Element in adj add V
    adj.resize(V);
}

void Graph::addEdge(int source, int destination)
{
    // Add w to v’s list.
    adj[source].push_back(destination);
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it

        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main()
{
    // Create a new Graph
    Graph g(4);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";

    g.BFS(2);

    return 0;
}

// Time Complexity: O(V+E), where V is the number of nodes and E is the number of edges.
// Auxiliary Space: O(V)