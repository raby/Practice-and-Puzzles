#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <set>
#include "vertex.h"

using namespace std;

class Graph
{

public:

	set<vertex*> g;
	void addVertex(const string& name_)
	{
		vertex* temp = new vertex(name_);
		g.insert(temp);
	}

	void addVertex(const string& name_, const map<vertex*, int>& edges_)
	{
		vertex* temp = new vertex(name_);
		temp->reachable = edges_;
		g.insert(temp);
	}

	vertex* findVertex(const string& name) 
	{
		vertex* temp = nullptr;
		for (auto i : g)
			if (i->name == name)
				temp = i;
		if (!temp)
			cout << "Error [ Directed Graph ] : finding vertex " << name << "  not found. Returning NULL";

		return temp;
	}
	
	void addEdge(vertex*& from, vertex*& to, const int& cost) 
	{
		from->reachable[to] = cost;
	}

	void addEdge(const string& from, const string& to, const int& cost)
	{
		vertex* fromTemp = nullptr;
		vertex* toTemp = nullptr;

		for (set<vertex*>::iterator i = g.begin(); i != g.end(); i++)
		{
			if ((*i)->name == from)
				fromTemp = *i;
			if ((*i)->name == to)
				toTemp = *i;
			if (fromTemp && toTemp)
				break;
		}

		if (!fromTemp)
			cout << "Error [ addEdge() ]: 1st parameter " << from << ", vertex FROM, was not defined in the graph." << endl;
		else if (!toTemp)
			cout << "Error [ addEdge() ]: 2nd paremeter " << to << ", vertex TO, was not defined in the graph." << endl;
		else
			fromTemp->reachable[toTemp] = cost;
	}

	//helper function for implimenting Dijkstra's test graph
	void addBidirectionalEdge(const string& from, const string& to, const int& cost) 
	{
		addEdge(from, to, cost);
		addEdge(to, from, cost);
	}

	void print()
	{
		cout << endl << "Printing Graph: " << endl;
		for (auto i : g)
		{
			cout << "Vertex: " << i->name;
			cout << " Edges: " << "[ ";
			for (auto j : i->reachable)
				cout << "(" << j.first->name << "," << j.second << ") ";
			cout << "]" << endl;
		}
		cout << endl;
	}

	int countEdges() 
	{
		int totalEdges = 0;
		for (auto i : g) 
			totalEdges += i->reachable.size();
		return totalEdges;
	}

};
#endif // !GRAPH_H
