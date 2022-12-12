#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int src, dest;
};

class Graph
{
public:
	vector<vector<int>> adj_list;

	Graph(vector<Edge>& edjes, int size)
	{
		adj_list.resize(size);

		for (auto& edge : edjes)
			adj_list[edge.src].push_back(edge.dest);	
	}
};

void PrintGraph(Graph& graph, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << "->";

		for (int v : graph.adj_list[i])
			cout << v << " ";
		cout << endl;
	}
}

vector<int> bfs(int s, int t, int size, Graph& graph)
{
    vector<int> dist(size, size);
    vector<int> p(size, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph.adj_list[v]) {
            if (dist[u] > dist[v] + 1) {
                p[u] = v;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    // если пути не существует, возвращаем пустой vector
    if (dist[t] == size) {
        return {};
    }

    vector<int> path;
    while (t != -1) {
        path.push_back(t);
        t = p[t];
    }

    // путь был рассмотрен в обратном порядке, поэтому его нужно перевернуть
    reverse(path.begin(), path.end());
    return path;
}

void show_vector(vector<int>& a)
{
    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
        cout << *it;
}