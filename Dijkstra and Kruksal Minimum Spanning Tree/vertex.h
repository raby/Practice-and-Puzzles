#ifndef VERTEX_H
#define VERTEX_H

#include <set>
#include <string>
#include <iostream>

class vertex 
{
	private:
		std::string name;
		std::set < std::pair < vertex*, std::int64_t >> edges;
		
	public:
		vertex(std::string n);
		vertex(std::string n_, std::set<std::pair<vertex*, std::int64_t>> e_);
		std::set < std::pair < vertex*, std::int64_t >>& getEdges();
		const std::string& getName();
		void d_vertex();
		void setEdge(vertex* v_, std::int64_t c_);
		void pruneEdge(vertex* v_);
		void printEdges();

};

#endif // !VERTEX_H
