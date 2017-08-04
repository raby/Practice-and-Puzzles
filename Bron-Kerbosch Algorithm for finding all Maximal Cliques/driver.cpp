//Created by David Pynes
#include<set>
#include<algorithm>
#include<vector>
#include<iterator>
#include "graph.cpp"
using namespace std;

/*
PSEUDO CODE:

WITHOUT PIVOTING:

BronKerbosch1(R, P, X) :
	if P and X are both empty :
report R as a maximal clique
for each vertex v in P :
	BronKerbosch1(R U{ v }, P n N(v), X n N(v))
	P : = P \ {v}
	X: = X U {v}

WITH PIVOT
BronKerbosch2(R,P,X):
    if P and X are both empty:
        report R as a maximal clique
    choose a pivot vertex u in P U X
    for each vertex v in P \ N(u):
        BronKerbosch2(R U {v}, P n N(v), X n N(v))
        P := P \ {v}
        X := X U {v}
*/

//helper functions//

/* P U X */
node* PunionX(set<node*> R, set<node*> P, set<node*> X)
{
	set<node*> u;
	set_union(P.begin(), P.end(), X.begin(), X.end(), inserter(u, u.end()));
	if (u.empty())
		return nullptr;
	else
		return *u.begin();
}

/* P \ N(u) */
set<node*> PremoveNeighborsofU(set<node*> R, set<node*> P, set<node*> X, node* u) 
{
	set<node*> Ptemp;
	set_difference(P.begin(), P.end(), u->reachable.begin(), u->reachable.end(), inserter(Ptemp, Ptemp.end()));
	return Ptemp;
}

/* X n N(v) */
set<node*> XintersectNeighborsofV(set<node*> R, set<node*> P, set<node*> X, set<node*> v)
{
	set<node*> Xtemp;
	for (auto i : v)
		set_intersection(X.begin(), X.end(), i->reachable.begin(), i->reachable.end(), inserter(Xtemp, Xtemp.end()));
	return Xtemp;
}

/* P n N(v) */
set<node*> PinstersectNeighborsofV( set<node*> R, set<node*> P,  set<node*> X, set<node*> v)
{
	set<node*> Ptemp;
	for (auto i : v)//for each node in V visit the neighbors and see if they intersect with P
		set_intersection(P.begin(), P.end(), i->reachable.begin(), i->reachable.end(), inserter(Ptemp, Ptemp.end()));
	return Ptemp;
}

/* X U {v} */
set<node*> XunionV(set<node*> R, set<node*> P, set<node*> X, set<node*> v)
{
	set<node*> Xtemp;
	set_union(X.begin(), X.end(), v.begin(), v.end(), inserter(Xtemp, Xtemp.end()));
	return Xtemp;
}

/* P \ {v} */
set<node*> PremoveV(set<node*> R, set<node*> P, set<node*> X, set<node*> v)
{
	set<node*> Ptemp;
	set_difference(P.begin(), P.end(), v.begin(), v.end(), inserter(Ptemp, Ptemp.end()));
	return Ptemp;
}

/* R U {v} */
set<node*> RunionV(set<node*> R, set<node*> P, set<node*> X, set<node*> v)
{
	set<node*> Rtemp;
	set_union(R.begin(), R.end(), v.begin(), v.end(), inserter(Rtemp, Rtemp.end()));
	return Rtemp;
}

void printR(set<node*> R) 
{
	cout << "Maximal Clique found: " << endl;
	cout << "[ ";
	for (set<node*>::iterator rt = R.begin(); rt != R.end(); rt++)
		std::cout << (*rt)->name << " ";
	cout << "] "<<  endl;
}

//bronkerbosch w/o pivot//
void BronKerbosch1(set<node*> R, set<node*> P, set<node*> X, int& recursiveCallCount) 
{
	if (P.size() == 0 && X.size() == 0)
		printR(R);
	for (set<node*>::iterator v = P.begin(); v != P.end();v)
	{
		set<node*> v_;	//create a singleton set {v}
		v_.insert(*v);
		
		v++; //now advance iterator

		/* BronKerbosch1(R U {v}, P n N(v), X n N(v)) */
		BronKerbosch1(RunionV(R, P, X, v_), PinstersectNeighborsofV(R, P, X, v_), XintersectNeighborsofV(R, P, X, v_), ++recursiveCallCount);
		P = PremoveV(R, P, X, v_); // P = P / {v}
		X = XunionV(R, P, X, v_);  // X = X + P; //X = X U {v} 
		
		if (P.empty())
			return;
		else
			v = P.begin();
	}
}

//Bronkerbosch w/ pivot//
void BronKerbosch2(set<node*> R, set<node*> P, set<node*> X, int& recursiveCallCount) 
{
	if (P.size() == 0 && X.size() == 0)
		printR(R);
	node* u = PunionX(R, P, X);
	set<node*> Pbutnotneighborswithu;
	if(u)
		Pbutnotneighborswithu = PremoveNeighborsofU(R, P, X, u);
	for (set<node*>::iterator v = Pbutnotneighborswithu.begin(); v != Pbutnotneighborswithu.end(); v)
	{
		set<node*> v_;	//create a singleton set {v}
		v_.insert(*v);

		v++; //now advance iterator

		BronKerbosch2(RunionV(R, P, X, v_), PinstersectNeighborsofV(R, P, X, v_), XintersectNeighborsofV(R, P, X, v_), ++recursiveCallCount);
		P = PremoveV(R, P, X, v_); // P = P / {v}
		X = XunionV(R, P, X, v_);  // X = X + P; //X = X U {v} 
	}
}


int main() 
{
	Graph graph;

	graph.createNode("a");
	graph.createNode("b");
	graph.createNode("c");
	graph.createNode("d");
	graph.createConnection("a", "b");
	graph.createConnection("a", "c");
	graph.createConnection("a", "d");
	graph.createConnection("b", "c");
	graph.createConnection("b", "d");
	graph.createConnection("c", "d");
	graph.print();
	
	//Initialize R & X to empty sets. Then set P to all verticies of the Graph.
	set<node*> R;
	R.clear();
	set<node*> X;
	X.clear();
	set<node*> P = graph.g; //g is the set of vertices in graph. 
	
	int ans = 1; //variable specific to HW counting recursive calls.
	BronKerbosch1(R, P, X, ans);
	cout << "The total number of recursive calls upon BronKerbosch1 "<< ans << endl << endl;
	
	R.clear();
	X.clear();
	P.clear();
	P = graph.g;  
	ans = 1; 
	BronKerbosch2(R, P, X, ans);
	cout << "The total number of recursive calls upon BronKerbosch2 " << ans << endl << endl;

	graph.clear();
	
	////////////////////////////////////////////////////
	///////TESTING 2 (graph from wikipedia page)////////
	////////////////////////////////////////////////////

	graph.createNode("6"); 
	graph.createNode("4");
	graph.createNode("3");
	graph.createNode("1");
	graph.createNode("2");
	graph.createNode("5");
	graph.createConnection("1", "5");
	graph.createConnection("1", "2");
	graph.createConnection("2", "5");
	graph.createConnection("2", "3");
	graph.createConnection("3", "4");
	graph.createConnection("5", "4");
	graph.createConnection("6", "4");
	
	graph.print();

	R.clear();
	X.clear();
	P.clear();
	P = graph.g; 
	ans = 1;

	cout << "Without pivot..." << endl;
	BronKerbosch1(R, P, X, ans);
	cout << "The total number of recursive calls upon BronKerbosch1 " << ans << endl << endl;

	R.clear();
	X.clear();
	P.clear();
	P = graph.g;
	ans = 1;

	cout << "Now with pivot..." << endl;
	BronKerbosch2(R, P, X, ans);
	cout << "The total number of recursive calls upon BronKerbosch2 " << ans << endl << endl;

	system("pause");
} 
