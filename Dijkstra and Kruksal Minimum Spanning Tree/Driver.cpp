#include "MinSpanTree.h"
#include "vertex.h"
#include <string>

void fromClass462016() 
{
	Graph g;
	//Insert as a variadic function
	g.insertVertex("a","b","c","d","e","f");

	g.makeUndirectedConnection("a", "b", 10);
	g.makeUndirectedConnection("a", "c", 20);
	g.makeUndirectedConnection("a", "d", 60);
	g.makeUndirectedConnection("b", "c", 10);
	g.makeUndirectedConnection("b", "f", 100);
	g.makeUndirectedConnection("c", "e", 90);
	g.makeUndirectedConnection("c", "f", 15);
	g.makeUndirectedConnection("e", "f", 30);

	std::cout << "Printing Graph g: " << std::endl;
	g.print();
	MinSpanTree *s = new MinSpanTree(g);
	s->kruskal();
	std::cout << "Printing Kruskal: " << std::endl;
	s->print();

	system("pause");
}

void fromClass4182016()
{
	Graph g;

	//Insert as a variadic function
	g.insertVertex("a","b","c","d","e","f","g","s");

	g.makeUndirectedConnection("s", "a", 10);
	g.makeUndirectedConnection("s", "b", 20);
	g.makeUndirectedConnection("s", "c", 30);
	g.makeUndirectedConnection("a", "d", 21);
	g.makeUndirectedConnection("a", "e", 14);
	g.makeUndirectedConnection("b", "d", 7);
	g.makeUndirectedConnection("b", "e", 35);
	g.makeUndirectedConnection("b", "f", 42);
	g.makeUndirectedConnection("c", "f", 28);
	g.makeUndirectedConnection("d", "g", 3);
	g.makeUndirectedConnection("e", "g", 6);
	g.makeUndirectedConnection("f", "g", 9);

	std::cout << "Printing Graph g: " << std::endl;
	g.print();
	MinSpanTree *s = new MinSpanTree(g);
	s->dijkstra(s->findNode("s"));
	std::cout << "Printing Dijkstra: " << std::endl;
	s->print();

	system("pause");
}

int main() 
{
	
	std::cout << "Case 1: ";
	fromClass462016();

	std::cout << "\n\n\n\nCase 2: ";
	fromClass4182016();

	
	system("pause");
}

