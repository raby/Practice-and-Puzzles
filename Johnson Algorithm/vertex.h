#ifndef VERTEX_H
#define VERTEX_H

#include <map>
#include <string>

using namespace std;

struct vertex
{
	string name;
	map<vertex*, int> reachable;
	vertex(string s) :name(s), reachable() {};
};

#endif // !VERTEX_H

