#ifndef MINSPANTREE_H
#define MINSPANTREE_H

#include "Graph.h"
#include "vertex.h"

class MinSpanTree 
{
	private:
		Graph g; 
		/*helper methods for dijkstra's MST*/
		const void printDijkstra(std::map<vertex*, std::int64_t>&, std::map<vertex*, vertex*>&);
		vertex* getNext(std::map<vertex*, std::int64_t>&, std::map<vertex*,bool>&);
		void convertMSTtoDijkstra(std::map<vertex*, std::int64_t>&, std::map<vertex*, vertex*>&);

		/*helper for kruskal's MST*/
		typedef std::tuple<std::int64_t, vertex*, vertex*> kruskalsGuide;
		bool kruskalsBool(const kruskalsGuide &lhs, const kruskalsGuide &rhs);

	public:
		MinSpanTree(Graph g_);
		void dijkstra(vertex* s);
		void kruskal();
		void makeUndirectedConnection(std::string n1_, std::string n2_, std::int64_t);
		void pruneEdge(std::string n1_, std::string n2_);
		void print();
		vertex* findNode(std::string s_);
		
};

#endif