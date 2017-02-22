#ifndef COMPONENTESCONEXAS_H
#define COMPONENTESCONEXAS_H

#include "Grafo.h"


class ComponentesConexas { //reciclado del año pasado
public:
	ComponentesConexas(Grafo const& G) : marked(G.V(), false), _id(G.V()),
		_size(G.V(), 0), _count(0) {
		for (auto v = 0; v < G.V(); ++v) {
			if (!marked[v]) { // se recorre una nueva componente conexa
				dfs(G, v);
				++_count;
			}
		}
	}
	// identificador de la componente que contiene a v
	size_t id(size_t v) const {
		return _id[v];
	}

	// tamaño de la componente que contiene a v
	size_t size(size_t v) const {
		return _size[_id[v]];
	}

	// número de componentes conexas
	size_t count() const {
		return _count;
	}

	// están v y w en la misma componente conexa?
	bool areConnected(size_t v, size_t w) const {
		return id(v) == id(w);
	}

private:
	std::vector<bool> marked;     // marked[v] = se ha visitado el vértice v?
	std::vector<size_t> _id;      // id[v] = identificador de la componente que contiene a v
	std::vector<size_t> _size;    // size[id] = número de vértices en la componente id
	size_t _count;                // número de componentes conexas

								  // recorrido en profundidad de la componente de v
	void dfs(Grafo const& G, size_t v) {
		marked[v] = true;
		_id[v] = _count;
		++_size[_count];
		for (auto w : G.adj(v)) {
			if (!marked[w]) {
				dfs(G, w);
			}
		}
	}

};

#endif