#include "Graph.h"
#include "vertex.h"

Graph Graph::copy()
{
	Graph c;
	std::map<vertex*, vertex*> visited;
	std::set<vertex*>::iterator it = g.begin();
	for (it; it != g.end(); it++)
	{
		if (!visited[*it])
		{
			vertex *tv = new vertex((*it)->getName());
			c.g.insert(tv);
			visited[*it] = tv;
		}
		std::set<std::pair<vertex*, std::int64_t>>::iterator ip = (*it)->getEdges().begin();
		for (ip; ip != (*it)->getEdges().end(); ip++)
		{
			vertex *te;
			if (!visited[ip->first])
			{
				te = new vertex(ip->first->getName());
				c.g.insert(te);
				visited[ip->first] = te;
			}
			c.makeUndirectedConnection(visited[*it]->getName(), visited[ip->first]->getName(), ip->second);
		}
	}
	return c;
}

const std::set<vertex*>* Graph::getVertices()
{
	std::set<vertex*>* g_ = &g;
	return g_;
}

/*
void Graph::insertVertex(std::string n_)
{
	vertex *v = new vertex(n_);
	g.insert(v);
}

void Graph::insertVertex(vertex* v_)
{
	g.insert(v_);
}
*/

vertex* Graph::findVertex(std::string n1_)
{
	std::set<vertex*>::iterator it = g.begin();
	for (it; it != g.end(); it++)
		if ((*it)->getName() == n1_)
			return *it;
	return nullptr;
}

void Graph::makeDirectedConnection(vertex* v1_, vertex* v2_, std::int64_t c_)
{
	if (v1_ != nullptr && v2_ != nullptr)
		v2_->setEdge(v1_, c_);
	else
		std::cout << "Error:One or more vertices v are null." << std::endl;
}

void Graph::makeUndirectedConnection(vertex* v1_, vertex* v2_, std::int64_t c_)
{
	if (v1_ != nullptr && v2_ != nullptr)
	{
		v1_->setEdge(v2_, c_);
		v2_->setEdge(v1_, c_);
	}
	else
		std::cout << "Error:One or more vertices v are null." << std::endl;
}


void Graph::makeDirectedConnection(std::string n1_, std::string n2_, std::int64_t c_)
{
	vertex* v1_ = findVertex(n1_);
	vertex* v2_ = findVertex(n2_);
	if (v1_ != nullptr && v2_ != nullptr)
		v1_->setEdge(v2_, c_);
	else
		std::cout << "Error: One or more vertices v not in Graph g." << std::endl;
}

void Graph::makeUndirectedConnection(std::string n1_, std::string n2_, std::int64_t c_)
{
	vertex* v1_ = findVertex(n1_);
	vertex* v2_ = findVertex(n2_);
	if (v1_ != nullptr && v2_ != nullptr)
	{
		v1_->setEdge(v2_, c_);
		v2_->setEdge(v1_, c_);
	}
	else
		std::cout << "Error: One or more vertices v not in Graph g." << std::endl;
}

void Graph::pruneEdge(std::string n1_, std::string n2_)
{

	std::set<vertex*>::iterator it = g.begin();
	vertex* v1_ = nullptr;
	vertex* v2_ = nullptr;

	for (it; it != g.end(); it++)
	{
		if ((*it)->getName() == n1_)
			v1_ = *it;
		else if ((*it)->getName() == n2_)
			v2_ = *it;
		if (v1_ && v2_)
			break;
	}
	if (v1_ != nullptr && v2_ != nullptr)
	{
		v1_->pruneEdge(v2_);
		v2_->pruneEdge(v1_);
	}
	else
		std::cout << "Error: One or more vertices v not in Graph g." << std::endl;
}

void Graph::pruneTheForest()
{
	std::set<vertex*>::iterator it = g.begin();
	for (it; it != g.end(); it++)
		(*it)->getEdges().clear();

}

void Graph::print()
{
	std::set<vertex*>::iterator it = g.begin();
	for (it; it != g.end(); it++)
	{
		std::cout << "[ " << (*it)->getName() << " ]  - >  [ ";
		(*it)->printEdges();
		std::cout << " ]" << std::endl;
	}
}

void Graph::d_graph()
{
	g.erase(g.begin(), g.end());
}
