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
    cout << "Graph:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << "->";
		for (int v : graph.adj_list[i])
			cout << v << " ";
		cout << endl;
	}
}

int ScanSatellite(const char* str, int size)
{
    int satellite;
    cout << "Input " << str << " [0," << size - 1 << "]:";
    do{
        cin >> satellite;
    } while (satellite > size - 1 || satellite < 0);
    return satellite;
}

void DistBetwSatellites(Graph& graph, int size)
{
    int first_satellite = ScanSatellite("first satellite", size);
    int second_satellite = ScanSatellite("second satellite", size);

    vector<int> dist(size, size);
    vector<int> p(size, -1);
    dist[first_satellite] = 0;

    queue<int> q;
    q.push(first_satellite);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : graph.adj_list[v])
        {
            if (dist[u] > dist[v] + 1)
            {
                p[u] = v;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    if (dist[second_satellite] == size)
    {
        cout << "There is no path!";
        return;
    }

    vector<int> path;
    while (second_satellite != -1)
    {
        path.push_back(second_satellite);
        second_satellite = p[second_satellite];
    }

    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (vector<int>::iterator it = path.begin(); it != path.end(); it++)
        cout << *it;
}

void LoopGraph(Graph& graph, int size)
{
    int choose;
    while (true)
    {
        cout << "1 - Print the graph; 2 - The path between two satellites; 3 - Clear the console; 4 - Exit.\nChoise:";
        do {
            cin >> choose;
        } while (choose < 1 || choose>4);
        cout << endl;
        
        switch (choose)
        {
        case 1:
            PrintGraph(graph, size);
            cout << endl;
            break;
        case 2:
            DistBetwSatellites(graph, size);
            cout << endl;
            break;
        case 3:
            system("cls");
            break;
        case 4:
            return;
        }
    }
}