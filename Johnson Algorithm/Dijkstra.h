#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "DirectedGraph.h"
#include <vector>
#include <queue>

/*
PSEUDO CODE:

function Dijkstra(Graph, source):

      create vertex set Q

      for each vertex v in Graph:            // Initialization
          dist[v] = INFINITY                  // Unknown distance from source to v
          prev[v] = UNDEFINED                 // Previous node in optimal path from source
          add v to Q                         // All nodes initially in Q (unvisited nodes)

      dist[source] = 0                        // Distance from source to source

      while Q is not empty:
          u <- vertex in Q with min dist[u]    // Source node will be selected first
          remove u from Q

          for each neighbor v of u:           // where v is still in Q.
              alt <- dist[u] + length(u, v)
              if alt < dist[v]:               // A shorter path to v has been found
                  dist[v] <- alt
                  prev[v] <- u

      return dist[], prev[]
*/

void printVdp(map<vertex*, tuple<bool, int, vertex*>> vdp)
{
	cout << "Printing results of Dijkstra: " << endl;
	cout << "Vertex: \tVisited: \tDistance: \tPrevious: " << endl;
	for (map < vertex*, tuple<bool, int, vertex*>>::iterator i = vdp.begin(); i != vdp.end();i++)
	{
		cout << i->first->name << "\t\t" << get<0>(i->second) << "\t\t" << get<1>(i->second);
		(get<1>(i->second) > 199999999) ? cout << "\t" : cout << "\t\t"; //formating for large numbers;
		get<2>(i->second) ? cout << get<2>(i->second)->name << endl : cout << "NULL" << endl;
	}
	cout << endl;
}

vertex* findMin(map<vertex*,tuple<bool, int, vertex*>>& vdp)
{
	vertex* temp = nullptr;
	int min = INT_MAX;
	for (auto i : vdp)
	{
		if (get<0>(i.second)==0 && get<1>(i.second) < min )
		{
			temp = i.first;
			min = get<1>(i.second);
		}
	}
	if (temp)
	{
		get<0>(vdp[temp]) = true;
		return temp;
	}
}

map<vertex*, tuple<bool, int, vertex*>> Dijkstra(const Graph& g, vertex* s) 
{
	map<vertex*,tuple<bool,int,vertex*> > vdp;
	for (auto v : g.g)
		vdp[v] = make_tuple(false, INT_MAX, nullptr);
	get<1>(vdp[s]) = 0;
	for (auto x : g.g )
	{
		if (vertex* u = findMin(vdp))
		{
			for (map<vertex*, int>::iterator v = u->reachable.begin(); v != u->reachable.end(); v++)
			{
				if (get<1>(vdp[v->first]) > get<1>(vdp[u]) + v->second)
				{
					get<1>(vdp[v->first]) = get<1>(vdp[u]) + v->second;
					get<2>(vdp[v->first]) = u;
				}
			}
		}
		//else
			//cout << "Notice [ Dijkstra ] : A vertex was not selected on iteration of Dijkstra." << endl;
	}
	//printVdp(vdp);
	return vdp;
}

#endif // !DIJKSTRA_H

