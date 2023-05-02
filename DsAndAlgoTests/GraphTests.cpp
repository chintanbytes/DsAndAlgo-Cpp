#include <gtest/gtest.h>
#include "../Graph/Graph.cpp"

TEST(GraphTest, Test1)
{
    const auto vertices = 4;
    auto graph = Graph(vertices);

    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(1, 3);

    int visited[vertices] = {0, 0, 0, 0};
    graph.dfs(0, visited);
};

TEST(GraphTest, Test2)
{
    const auto vertices = 7;
    auto graph = Graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 5);
    graph.addEdge(5, 4);
    graph.addEdge(3, 4);
    graph.addEdge(2, 3);
    graph.addEdge(2, 6);

    int visited[vertices] = {0, 0, 0, 0};
    graph.dfs(0, visited);
};

TEST(GraphTest, Test3)
{
    const auto vertices = 8;
    auto graph = Graph(vertices);

    graph.addEdge(0, 4);
    graph.addEdge(0, 5);
    graph.addEdge(4, 3);
    graph.addEdge(3, 2);
    graph.addEdge(3, 1);
    graph.addEdge(3, 6);
    graph.addEdge(2, 1);
    graph.addEdge(6, 5);
    graph.addEdge(6, 7);

    int visited[vertices] = {0, 0, 0, 0, 0, 0, 0, 0};

    std::cout << "DFS: ";
    graph.dfs(0, visited);
    std::cout << "\n";

    int visited1[vertices] = {0, 0, 0, 0, 0, 0, 0, 0};
    std::cout << "BFS: ";
    graph.bfs(0, visited1);
    std::cout << "\n";
};

TEST(GraphTest, Test4)
{
    const auto vertices = 8;
    auto graph = Graph(vertices);

    graph.addEdge(0, 2);
    graph.addEdge(0, 4);
    graph.addEdge(2, 4);
    graph.addEdge(2, 3);
    graph.addEdge(1, 5);
    graph.addEdge(6, 7);

    int visited[vertices] = {0, 0, 0, 0, 0, 0, 0, 0};

    std::cout << "DFS: ";
    graph.dfs(0, visited);
    std::cout << "\n";

    int visited1[vertices] = {0, 0, 0, 0, 0, 0, 0, 0};
    std::cout << "BFS: ";
    graph.bfs(0, visited1);
    std::cout << "\n";
};