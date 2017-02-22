#ifndef CC_H_
#define CC_H_

#include "Grafo.h"
using namespace std;

/**
* Clase de Componentes Conexas
* Extraido de la pagina de los apuntes 126
*/
class CC {
public:
	/**
	* Constructora
	*/
	CC(Grafo const& G) : marked(G.V(), false), id(G.V()),
		_size(G.V(), 0), count(0) {
		for (auto v = 0; v < G.V(); ++v) {
			if (!marked[v]) {
				dfs(G, v);
				count++;
			}
		}
	}


	/**
	* Comprueban si estan en la misma componente conexa dos vertices
	*/
	bool connected(int v, int w) const {
		return id[v] == id[w];
	}

	/**
	* Numero de vertices que estan conectados con el vertice v
	*/
	int size(int v) const {
		return _size[id[v]];
	}


private:
	std::vector<bool> marked;	// Control de vertices visitados
	std::vector<int> id;		// Identificador de la componente que contiene al vertice(v)
	std::vector<int> _size;		// Número de vértices en la componente id
	int count;					// Número de componentes conexas

	/**
	* Recorrido en profundidad del vertice v
	*/
	void dfs(Grafo const& G, int v) {
		marked[v] = true;
		id[v] = count;
		_size[count]++;
		for (auto w : G.adj(v)) {
			if (!marked[w]) {
				dfs(G, w);
			}
		}
	}
};

#endif