#ifndef PUENTES_H_
#define PUENTES_H_

#include "GrafoValorado.h"
#include "IndexPQ.h"
#include <vector>
#include <climits>
using namespace std;

class Puentes
{
public:

	Puentes(GrafoValorado<int> const& grafo) :		//constructora de la clase. En ella se lleva a cabo el cálculo del problema a la hora de construir la estructura.
													//Esto nos permite tener luego un acceso al mismo de coste constante.
		distancia(grafo.V(), INT_MAX),
		marked(grafo.V(), false),
		arista(grafo.V()),
		pq(grafo.V())

	{
		tamanho = grafo.V();
		costeTotal = 0;
		distancia[1] = 0;
		pq.push(1, 0);

		contador = 0;
		int vertice = 0;

		while (!pq.empty())
		{
			vertice = pq.top().elem;
			pq.pop();
			visitar(grafo, vertice);		//algoritmo Prim
		}
	}

	int precioPublico()
	{
		if (contador != tamanho - 1) //Tam(arbol de rec minimo) = vertices - 1; 
		{
			return costeTotal;
		}
		else return 0;
	}

private:

	// atributos privados

	vector<int> distancia;
	vector<bool> marked;
	vector<Arista<int>> arista;
	IndexPQ <int, less<int>> pq;
	int costeTotal, tamanho;
	int contador = 0;

	// función en la que efectuamos un algoritmo de Prim para calcular el arbol de recubrimiento mínimo.

	void visitar(GrafoValorado<int> const& grafo, int vertice)
	{
		costeTotal = costeTotal + distancia[vertice];	//sumamos al coste total el peso de la nueva arista
		marked[vertice] = true;						//marcamos el nuevo vértice;
		contador++;
		for (Arista<int> _arista : grafo.adj(vertice))		//iteramos sobre las aristas adyacentes al vértice en el que estamos
		{
			int vertice2 = _arista.otro(vertice);		//nodo al que accedemos por esa arista
			if (!marked[vertice2])					//no haber pasado por el nodo
			{
				if (_arista.valor() < distancia[vertice2])		//comprobamos si mejora la nueva arista a la existente
				{
					arista[vertice2] = _arista;
					distancia[vertice2] = _arista.valor();
					pq.update(vertice2, distancia[vertice2]);
				}
			}
		}

	}

	int precio()		//retorno del coste de hacer los puentes.
	{
		if (contador != tamanho - 1) //Tam(arbol de rec minimo) = vertices - 1; 
		{
			return costeTotal;
		}
		else return 0;

	}
};


#endif