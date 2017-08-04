#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include "DirectedGraph.h"

/*
function BellmanFord(list vertices, list edges, vertex source)
::distance[],predecessor[]

// This implementation takes in a graph, represented as
// lists of vertices and edges, and fills two arrays
// (distance and predecessor) with shortest-path
// (less cost/distance/metric) information

//PSEUDO CODE AS FOUND ON WIKIPEDIA//

// Step 1: initialize graph
for each vertex v in vertices:
distance[v] := inf             // At the beginning , all vertices have a weight of infinity
predecessor[v] := null         // And a null predecessor

distance[source] := 0              // Except for the Source, where the Weight is zero

// Step 2: relax edges repeatedly
for i from 1 to size(vertices)-1:
for each edge (u, v) with weight w in edges:
if distance[u] + w < distance[v]:
distance[v] := distance[u] + w
predecessor[v] := u

// Step 3: check for negative-weight cycles
for each edge (u, v) with weight w in edges:
if distance[u] + w < distance[v]:
error "Graph contains a negative-weight cycle"
return distance[], predecessor[]

*/

void printDistance(const map<vertex*, int>& distance) 
{
	cout << "Distances on BellmanFord: " << endl;
	for (auto i : distance) 
		cout << " [" << i.first->name << "] -> " << i.second << endl;
	cout << endl;
}

map<vertex*, int> setDistance(const Graph& g)
{
	map<vertex*, int> temp;
	for (auto i : g.g)
		temp[i] = 999999999; // note: overflow if set as INT_MAX
	return temp;
}

map<vertex*, vertex*> setPredecessor(const Graph& g)
{
	map<vertex*, vertex*> temp;
	for (auto i : g.g)
		temp[i] = nullptr;
	return temp;
}

vertex* findSource(const Graph& g, const string& s)
{
	for (auto i : g.g)
		if (i->name == s)
			return i;
	return nullptr;
}

map<vertex*, int> BellmanFord(Graph& g, const string& source)
{
	// Initialize graph
	map<vertex*, int> distance = setDistance(g);
	map<vertex*, vertex*> predecessor = setPredecessor(g);
	vertex* s = findSource(g, source);
	if (s == nullptr)
	{
		cout << "Error [ BellmanFord ]: Source node " << source << " was not found while initializing the distance & predecessor maps." << endl;
		return distance;
	}
	distance[s] = 0;

	// Repatedly relax edges
	for (int i = 0; i < g.g.size(); i < i++) // iterate the relaxation for the number of vertices in graph
	{
		//printDistance(distance);
		for (auto j : g.g) 
		{
			for (map<vertex*, int>::iterator k = j->reachable.begin(); k != j->reachable.end(); k++)
			{
				if ((distance[j] + k->second) < distance[k->first])
				{
					distance[k->first] = (distance[j] + k->second);
					predecessor[k->first] = j;
				}
			}
		}
	}

	// Check for negative-weight cycles
	for (auto j : g.g)
		for (map<vertex*, int>::iterator k = j->reachable.begin(); k != j->reachable.end(); k++)
			if ((distance[j] + k->second) < distance[k->first])
				cout << "Error [ BellmanFord ] : Negative cycle exsists.";

	return distance;
}

#endif // !BELLMANFORD_H
