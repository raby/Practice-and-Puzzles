#include "vertex.h"
#include "Dijkstra.h"
#include "DirectedGraph.h"
#include "BellmanFord.h"
#include "Johnson.h"

void BellmanFordTesting() 
{
	//From youtube video: https://www.youtube.com/watch?v=obWXjtg0L64
	Graph g;
	g.addVertex("S");
	g.addVertex("A");
	g.addVertex("B");
	g.addVertex("C");
	g.addVertex("D");
	g.addVertex("E");
	g.addEdge("S", "E", 8);
	g.addEdge("S", "A", 10);
	g.addEdge("A", "C", 2);
	g.addEdge("B", "A", 1);
	g.addEdge("C", "B", -2);
	g.addEdge("D", "C", -1);
	g.addEdge("D", "A", -4);
	g.addEdge("E", "D", 1);
	g.print();
	BellmanFord(g, "S");
	system("pause");

	//From youtube video: https://www.youtube.com/watch?v=iTW2yFYd1Nc
	Graph p;
	p.addVertex("S");
	p.addVertex("A");
	p.addVertex("B");
	p.addVertex("C");
	p.addVertex("D");
	p.addVertex("T");
	p.addEdge("S", "A", 5);
	p.addEdge("S", "C", -2);
	p.addEdge("C", "A", 2);
	p.addEdge("A", "B", 1);
	p.addEdge("B", "C", 2);
	p.addEdge("B", "D", 7);
	p.addEdge("C", "D", 3);
	p.addEdge("D", "T", 10);
	p.addEdge("B", "T", 3);
	p.print();
	BellmanFord(p, "S");
	system("pause");

	Graph j;
	j.addVertex("A");
	j.addVertex("B");
	j.addVertex("C");
	j.addEdge("A", "B", -1);
	j.addEdge("B", "C", -2);
	j.addEdge("C", "A", -3);
	j.print();
	BellmanFord(j, "A");
	system("pause");
}

void DijkstraTesting() 
{
	//Test from wikipedia graph. Found here: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
	Graph d;
	d.addVertex("1");
	d.addVertex("2");
	d.addVertex("3");
	d.addVertex("4");
	d.addVertex("5");
	d.addVertex("6");
	d.addBidirectionalEdge("1", "2", 7);
	d.addBidirectionalEdge("1", "3", 9);
	d.addBidirectionalEdge("1", "6", 14);
	d.addBidirectionalEdge("3", "6", 2);
	d.addBidirectionalEdge("3", "4", 11);
	d.addBidirectionalEdge("3", "2", 10);
	d.addBidirectionalEdge("2", "4", 15);
	d.addBidirectionalEdge("4", "5", 6);
	d.addBidirectionalEdge("6", "5", 9);
	printVdp(Dijkstra(d, d.findVertex("1")));
}

int main() 
{
	//BellmanFordTesting();
	DijkstraTesting();
	
	Graph g;
	g.addVertex("A");
	g.addVertex("B");
	g.addVertex("C");
	g.addVertex("X");
	g.addVertex("Y");
	g.addVertex("Z");
	g.addEdge("A", "B", -2);
	g.addEdge("B", "C", -1);
	g.addEdge("C", "A", 4);
	g.addEdge("C", "X", 2);
	g.addEdge("C", "Y", -3);
	g.addEdge("Z", "X", 1);
	g.addEdge("Z", "Y", -4);
	g.print();

	Johnson(g);

	system("pause");

}
