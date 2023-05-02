// Graph is a tree if it has no cycle
// Grph has vertices and edges
// Graph can be represented as adjacency matrix or adjacency list
#include <iostream>
#include <queue>

class Graph
{
private:
    int vertices;
    int edges;
    int **adjMatrix;

public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int u, int v);
    void addEdges(int n);
    void printGraph();
    void dfs(int start, int *visited);
    void bfs(int start, int *visited);
};

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    adjMatrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adjMatrix[i] = new int[vertices];

        for (int j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
}

void Graph::addEdge(int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void Graph::addEdges(int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the edge: ";
        int u, v;
        std::cin >> u >> v;
        addEdge(u, v);
    }
}

void Graph::printGraph()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::dfs(int start, int *visited)
{
    visited[start] = 1;
    std::cout << start << " ";
    for (int i = 0; i < vertices; i++)
    {
        if (adjMatrix[start][i] == 1 && visited[i] == 0)
        {
            dfs(i, visited);
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (visited[i] == 0)
            dfs(i, visited);
    }
}

void Graph::bfs(int start, int *visited)
{
    std::queue<int> q;

    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        auto cv = q.front();
        q.pop();
        std::cout << cv << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[cv][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (visited[i] == 0)
            bfs(i, visited);
    }
}
