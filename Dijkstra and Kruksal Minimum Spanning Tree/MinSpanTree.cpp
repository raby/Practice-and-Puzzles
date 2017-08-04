
#include "MinSpanTree.h"

#include <tuple>
#include <list>
#include <algorithm>

MinSpanTree::MinSpanTree(Graph g_) 
{
	g = g_.copy();
}

vertex* MinSpanTree::findNode(std::string s_) 
{
	std::set<vertex*>::iterator it = g.getVertices()->begin();
	for (it; it != g.getVertices()->end();it++)
		if (s_ == (*it)->getName())
			return *it;
}

const void MinSpanTree::printDijkstra(std::map<vertex*, std::int64_t>& dist, std::map<vertex*, vertex*>& prev) 
{
	std::map<vertex*, std::int64_t>::iterator distIT = dist.begin();
	std::map<vertex*, vertex*>::iterator prevIT = prev.begin();
	for (distIT; distIT != dist.end(); distIT++)
		std::cout << distIT->first->getName() << " costs: " << distIT->second << std::endl;
	std::cout << std::endl;
	for (prevIT; prevIT != prev.end(); prevIT++)
		std::cout << prevIT->first->getName() << " came from: " << prevIT->second->getName() << std::endl;
}

vertex* MinSpanTree::getNext(std::map<vertex*, std::int64_t>& dist, std::map<vertex*,bool>& visited) 
{
	int minDis = INT_MAX;
	vertex* next = nullptr;
	for (std::map<vertex*, std::int64_t>::iterator distIT = dist.begin(); distIT != dist.end(); distIT++)
	{
		if (distIT->second < minDis && visited[distIT->first] == 0)
		{
			minDis = distIT->second;
			next = distIT->first;
		}
	}
	return next;
}

void MinSpanTree::convertMSTtoDijkstra(std::map<vertex*, std::int64_t>& dist, std::map<vertex*, vertex*>&prev) 
{
	Graph temp;
	std::map<vertex*, std::pair<vertex*, vertex*>> conversionTable;
	//Initiaize new graph with vertices.
	for (std::map<vertex*, vertex*>::iterator verticesIT = prev.begin(); verticesIT != prev.end(); verticesIT++)
	{
		vertex* t = new vertex((*verticesIT).first->getName());
		temp.insertVertex(t);
		conversionTable[t].first = t;
		conversionTable[t].second = (*verticesIT).first;
	}
	//Make connections on new graph.
	for (std::set<vertex*>::iterator edgesIT = temp.getVertices()->begin(); edgesIT != temp.getVertices()->end(); edgesIT++)
		(*edgesIT)->setEdge(prev[conversionTable[(*edgesIT)].second], dist[conversionTable[(*edgesIT)].second]);


	//clear all edges;
	g.d_graph();
	//set MST to Dijkstra
	g = temp;
}

typedef std::tuple<std::int64_t, vertex*, vertex*> kruskalsGuide;
bool MinSpanTree::kruskalsBool(const kruskalsGuide &lhs, const kruskalsGuide &rhs)
{
	return std::get<0>(lhs) < std::get<0>(rhs);
}

//TODO: reduce NUM lines.
void MinSpanTree::kruskal() 
{
	std::vector<kruskalsGuide> kruskalsSol;
	std::map<vertex*, bool> visited;
	std::map<vertex*, vertex*> oldtonew;
	std::int64_t c = g.getVertices()->size() - 1;

	for (std::set<vertex*>::iterator verticesIT = g.getVertices()->begin(); verticesIT != g.getVertices()->end(); verticesIT++)
		for (std::set<std::pair<vertex*, std::int64_t>>::iterator edgesIT = (*verticesIT)->getEdges().begin(); edgesIT != (*verticesIT)->getEdges().end(); edgesIT++)
			kruskalsSol.push_back(std::make_tuple((*edgesIT).second, (*edgesIT).first, *verticesIT));
	
	std::sort(kruskalsSol.begin(), kruskalsSol.end());
	
	Graph t;

	for (std::vector<kruskalsGuide>::iterator kruskalsSolIT = kruskalsSol.begin(); kruskalsSolIT != kruskalsSol.end(); kruskalsSolIT++)
	{
		if (visited[std::get<1>(*kruskalsSolIT)] == 0 && visited[std::get<2>(*kruskalsSolIT)] == 0)
		{
			vertex *v1_ = new vertex(std::get<1>(*kruskalsSolIT)->getName());
			vertex *v2_ = new vertex(std::get<2>(*kruskalsSolIT)->getName());
			oldtonew[std::get<1>(*kruskalsSolIT)] = v1_;
			oldtonew[std::get<2>(*kruskalsSolIT)] = v2_;

			//todo: make insert vertex take 1 to N vertices;
			t.insertVertex(v1_);
			t.insertVertex(v2_);
			
			t.makeUndirectedConnection(v1_,v2_,std::get<0>(*kruskalsSolIT));	
			visited[std::get<1>(*kruskalsSolIT)] = 1;
			visited[std::get<2>(*kruskalsSolIT)] = 1;
			c--;
		}
		else if(visited[std::get<1>(*kruskalsSolIT)] == 0)
		{
			vertex *v1_ = new vertex(std::get<1>(*kruskalsSolIT)->getName());
			oldtonew[std::get<1>(*kruskalsSolIT)] = v1_;
			std::set<vertex*> v = *t.getVertices();
			t.insertVertex(v1_);
			t.makeUndirectedConnection(v1_, ( *t.getVertices()->find(oldtonew[std::get<2>(*kruskalsSolIT)] ) ), std::get<0>(*kruskalsSolIT));
			visited[std::get<1>(*kruskalsSolIT)] = 1;
			c--;
		}
		else if (visited[std::get<2>(*kruskalsSolIT)] == 0) 
		{
			vertex *v2_ = new vertex(std::get<2>(*kruskalsSolIT)->getName());
			oldtonew[std::get<2>(*kruskalsSolIT)] = v2_;
			t.insertVertex(v2_);
			t.makeUndirectedConnection((*t.getVertices()->find(oldtonew[std::get<1>(*kruskalsSolIT)])) , v2_, std::get<0>(*kruskalsSolIT));
			visited[std::get<2>(*kruskalsSolIT)] = 1;
			c--;
		}
		if (c == 0)
			break;
	}
	g.d_graph();
	g = t;
}

void MinSpanTree::dijkstra(vertex* startingVertex) 
{
	
	std::map<vertex*, bool> visited;
	std::map<vertex*, vertex*> prev;
	std::map<vertex*, std::int64_t> dist;

	//Initialize distances to "infinity"
	for (std::set<vertex*>::iterator it = g.getVertices()->begin(); it != g.getVertices()->end(); it++) 
		dist[*it] = INT_MAX;
	
	dist[startingVertex] = 0;
	prev[startingVertex] = startingVertex;
	vertex* cur = startingVertex;
	while (cur) 
	{
		visited[cur] = 1;
		std::set<std::pair<vertex*,std::int64_t>>::iterator neighbors = cur->getEdges().begin();
		for (neighbors; neighbors != cur->getEdges().end(); neighbors++) 
			(dist[cur] + neighbors->second < dist[neighbors->first])  ? (dist[neighbors->first] = dist[cur] + neighbors->second, prev[neighbors->first] = cur): NULL;
		
		//finds smallest distance to next node that hasn't been visited.
		vertex* next = getNext(dist,visited);
		next ? cur = next : cur = nullptr;
	}
	printDijkstra(dist, prev);
	convertMSTtoDijkstra(dist,prev);
}

void MinSpanTree::makeUndirectedConnection(std::string n1_, std::string n2_, std::int64_t c_) 
{
	g.makeUndirectedConnection(n1_, n2_, c_);
}

void MinSpanTree::pruneEdge(std::string n1_, std::string n2_) 
{
	g.pruneEdge(n1_, n2_);
}

void MinSpanTree::print()
{
	g.print();
}
