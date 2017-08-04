//Created by David Pynes
#include<set>
#include<iostream>
#include<string>
using namespace std;


struct node
{
	string name;
	set<node*> reachable;
	node(string n_, set<node*> r_) :name(n_), reachable(r_) {  };
	node(string n_) :name(n_) { };
};

class Graph 
{
	private:
	public:
		set<node*> g;

		void createNode(string n, set<node*> r) 
		{
			node* t = new node(n, r);
			g.insert(t);
		}
		void createNode(string n) 
		{
			node *t = new node(n);
			g.insert(t);
		}
		void createConnection(string n1_, string n2_) 
		{
			node *t1 = nullptr;
			node *t2 = nullptr;
			for (auto i : g) 
			{
				if (i->name == n1_)
					t1 = i;
				else if (i->name == n2_)
					t2 = i;
				if (t1 != nullptr && t2 != nullptr)
					break;
			}
			t1->reachable.insert(t2);
			t2->reachable.insert(t1);
		}

		void print() 
		{
			cout << "Displaying Graph: " << endl;
			set<node*>::iterator it = g.begin();
			for (it; it != g.end(); it++) 
			{
				cout <<"Vertex: "<< (*it)->name<< " Connects to: [ ";
				for (set<node*>::iterator jt = (*it)->reachable.begin(); jt != (*it)->reachable.end(); jt++)
					cout << (*jt)->name<<" ";
				cout << "]" << endl;
			}
			cout << endl;
		}

		void clear() 
		{
			for (auto i : g)
			{
				i->reachable.clear();
				delete i;
			}
			g.clear();
		}
};