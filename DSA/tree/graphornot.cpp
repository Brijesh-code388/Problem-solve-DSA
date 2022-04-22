#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    bool isCyclic(int v, bool visited[], int parent);

public:
    Graph(int v);
    void addEdge(int v, int w);
    bool isTree();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclic(int v, bool visited[], int parent)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            if (isCyclic(*i, visited, v))
            {
                return true;
            }
            else if (*i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool Graph::isTree()
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    if (isCyclic(0, visited, -1))
    {
        return false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";
    return 0;
}
