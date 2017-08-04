#ifndef JOHNSON_H
#define JOHNSON_H

#include "DirectedGraph.h"
#include "BellmanFord.h"
#include "Dijkstra.h"

/*
Algorithm description[edit]

Johnson's algorithm consists of the following steps:

First, a new node q is added to the graph, connected by zero-weight edges to each of the other nodes.
Second, the Bellman–Ford algorithm is used, starting from the new vertex q, to find for each vertex v the minimum weight h(v) of a path from q to v. If this step detects a negative cycle, the algorithm is terminated.
Third, the edges of the original graph are reweighted using the values computed by the Bellman–Ford algorithm: an edge from u to v, having length w(u,v), is given the new length w(u,v) + h(u) − h(v).
(Forth) Finally, q is removed, and Dijkstra's algorithm is used to find the shortest paths from each node s to every other vertex in the reweighted graph.
*/

void Johnson(Graph g) 
{
	//First: a new node q is added to the graph, conneced by zero-weight eddges to each of the other nodes.
	g.addVertex("Q");
	vertex* Q = g.findVertex("Q");
	for (auto i : g.g)
		g.addEdge(Q, i, 0);

	//Second: Relax edges with Bellman Ford starting at new node q.
	map<vertex*, int> distance = BellmanFord(g, "Q");
	
	//Third: Re-assign edge values.
	for (auto i : g.g)
		for (auto j : i->reachable)
			i->reachable[j.first] = j.second + (distance[i] - distance[j.first]);
	
	//Forth: q is removed. Now use Dijkstra's algorithm starting at each vertex as a source to find shortest path from s to every other node. 
	g.g.erase(Q);
	
	set < map< vertex*, tuple<bool, int, vertex*> > > solutionSet;
	for (auto v : g.g)
		solutionSet.insert(Dijkstra(g, v)); 

	//Helper: print solution
	cout << "Printing all paths from Johnson Algorithm: " << endl;
	for (set<map<vertex*, tuple<bool, int, vertex*>>>::iterator it = solutionSet.begin(); it != solutionSet.end(); it++)
		printVdp(*it);

}
#endif // !JOHNSON_H
