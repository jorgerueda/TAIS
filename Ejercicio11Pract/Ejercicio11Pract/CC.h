#ifndef CC_H
#define CC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Grafo.h"
using namespace std;

class CC {

public:

	CC(Grafo const& G): marked(G.V(),false), id(G.V()), _size(G.V(),0)  {
		for (int v = 0; v < G.V(); v++)
		{
			if (!marked[v])
			{
				dfs(G, v);
				count++;
			}
		}

	}

	 bool connected(int v, int w)
	{
		return id[v] == id[w];
	 };

	 int size(int v) {
		 return _size[id[v]];
	 };


private:
	vector <bool> marked;
	vector<int> id;
	vector <int> _size;

	int count;

	 void dfs(Grafo G, int v)
	{
		marked[v] = true;
		id[v] = count;
		_size[count]++;
		for (int w : G.adj(v)) {
			if (!marked[w])
				dfs(G, w);
		}
	 };

};

#endif // !

