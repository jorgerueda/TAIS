
#ifndef PRISM_H_
#define PRISM_H_


#include <vector>
#include "GrafoValorado.h"
#include "IndexPQ.h"
#include <climits>
using namespace std;



class Prism {
public:
	
	Prism(GrafoValorado<int> const& G) :
		edgeTo(G.V()),
		distTo(G.V(), INT_MAX),
		marked(G.V(), false),
		pq(G.V())
	{
		tamaño = G.V();
		distTo[1] = 0;
		costeTotal = 0;
		contador = 0;
		pq.push(1, 0); // Initialize pq with 0, weight 0.
		int vertice=0;
		while (!pq.empty()) {
			vertice = pq.top().elem;
			pq.pop();
			visit(G, vertice); // Add closest vertex to tree.
		}
	}

	int coste() {
		if (contador != tamaño-1) {
			return costeTotal;

		}
		else return 0;
	}
private:
	vector <Arista<int>> edgeTo; // shortest edge from tree vertex
	vector<int> distTo; // distTo[w] = edgeTo[w].weight()
	vector <bool> marked; // true if v on tree
	IndexPQ<int,less<int>> pq; // eligible crossing edges
	int contador=0;
	int costeTotal;
	int tamaño;


	 void visit(GrafoValorado<int> const& G, int v)
	{ // Add v to tree; update data structures.
		costeTotal = costeTotal+ distTo[v];
		marked[v] = true;
		contador++;
		
		for (Arista<int> e : G.adj(v))
		{
			int w = e.otro(v);
			if (!marked[w]){ // v-w is ineligible.
				if (e.valor() < distTo[w])
				{ // Edge e is new best connection from tree to w.
					edgeTo[w] = e;
					distTo[w] = e.valor();
					pq.update(w, distTo[w]);
				}
		}
		}
	}

};




#endif 

