

template<typename...Args> void Graph::insertVertex(Args...args) {
	for (auto i : { args... })
		insertVertex(i);
}

template<typename T> void Graph::insertVertex(T v_)
{
	std::cout << "Object passed as a vertex in the Graph is not an acceptable input." << std::endl;
}

template<> void Graph::insertVertex<vertex*>(vertex* v_)
{
	g.insert(v_);
}

template<> void Graph::insertVertex<const char*>(const char* s_)
{
	std::string t(s_);
	vertex *v = new vertex(t);
	g.insert(v);
}