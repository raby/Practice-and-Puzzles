#include "vertex.h"


vertex::vertex(std::string n_)
{
	vertex::name = n_;
}


vertex::vertex(std::string n_, std::set<std::pair<vertex*, std::int64_t>> e_)
{
	vertex::name = n_;
	edges = std::set<std::pair<vertex*, std::int64_t>>(e_);
}


std::set < std::pair < vertex*, std::int64_t >>& vertex::getEdges() 
{
	return edges;
}

const std::string& vertex::getName() 
{
	return name;
}

void vertex::setEdge(vertex* v, std::int64_t c_) 
{
	edges.insert(std::make_pair(v, c_));
}

void vertex::pruneEdge(vertex* v_) 
{
	std::set<std::pair<vertex*, std::int64_t>>::iterator it = edges.begin();
	while (it->first != v_)
		it++;
	edges.erase(it);
}

void vertex::printEdges() 
{
	std::set<std::pair<vertex*, std::int64_t>>::iterator it = edges.begin();
	for (it; it != edges.end(); it++)
		std::cout << "(" << it->first->getName() << " , " << it->second << ") ";
}

void vertex::d_vertex() 
{
	std::set<std::pair<vertex*,std::int64_t>>::iterator it = edges.begin();
	while(it != edges.end())
	{
		vertex* t = it->first;
		it++;
		delete t;
	}
	delete this;
}