#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"

#include <vector>
#include <set>
#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#include <type_traits>

class Graph
{
	private:
		std::set<vertex*> g;
		vertex* findVertex(std::string n1_);
	public:
		void print();
		//Depreciated //void insertVertex(std::string n_);
		//Dereciated //void insertVertex(vertex* v_);
		
		template<typename...Args> void insertVertex(Args...args);
		template<typename T> void insertVertex(T v); 
		template<> void insertVertex<vertex*>(vertex* v);
		template<> void insertVertex<const char*>(const char* c_);
		
		void makeUndirectedConnection(std::string n1_, std::string n2_, std::int64_t c_);
		void makeUndirectedConnection(vertex* v1_, vertex* v2_, std::int64_t c_);
		void makeDirectedConnection(std::string n1_, std::string n2_, std::int64_t c_);
		void makeDirectedConnection(vertex* v1_, vertex* v2_, std::int64_t c_);
		void pruneEdge(std::string n1_, std::string n2_);
		void pruneTheForest();
		void d_graph();
		const std::set<vertex*>* getVertices();
		Graph copy();
};

#include "Graph.tpp"

#endif
