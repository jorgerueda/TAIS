
//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda


#ifndef BFSCALCULADORA_H
#define BFSCALCULADORA_H

#include "GrafoDirigido.h"
#include <vector>

using namespace std;

class BFSCalculadora
{

public:
	BFSCalculadora(GrafoDirigido const& G, int origen, int destino) : marked(G.V(), false), distTo(G.V())
	{
		s = origen;
		v = destino;
		bfs(G);
	}

	int minDisTo()
	{
		return distTo[v];
	}

private:
	int s, v;
	vector<int> distTo;
	vector<bool> marked;		
	

	void bfs(GrafoDirigido const& G) {
		std::queue<int> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
		
		while (!q.empty()&& marked[v]==false) {
			int v = q.front(); q.pop();
			for (int w : G.adj(v)) {
				if (!marked[w]) {
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}


};
#endif