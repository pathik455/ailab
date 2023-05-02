#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
    map<T, list<T>> m;

public:
    void addEdge(T x, T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }

    void dfsHelper(T src, map<T, bool> &visited, T goal)
    {
        if (src == goal)
            {
                // cout << src << "-> ";
                return;
            }
        if (m[src].size() == 1)
        {
            visited[src] == false;
            return;
        }

        else
        {
            visited[src] = true;
            // return;

        }
        

        for (auto nbr : m[src])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited, goal);
            }
        }
    }
    void DFS(T src, T goal)
    {
        map<T, bool> visited;
        for (auto p : m)
        {
            T node = p.first;
            visited[node] = false;
        }

        dfsHelper(src, visited, goal);

        for (auto i : visited)
        {
            if (i.second == true)
            {
                cout << i.first << "->";
            }
        }
        cout << endl;
    }
};

int main()
{
    graph<char> g;
    g.addEdge('a', 'b');
    g.addEdge('a', 'c');
    g.addEdge('d', 'f');
    g.addEdge('d', 'e');
    g.addEdge('b', 'd');
    g.addEdge('e', 'g');
    g.addEdge('g', 'h');

    cout << "the path from a to e is:" << endl;
    g.DFS('a', 'e');
    cout << "the path from a to h is:" << endl;
    g.DFS('a', 'h');


    return 0;
}