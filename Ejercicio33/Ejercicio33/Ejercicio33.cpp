//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda

/*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Matriz.h"

using namespace std;



const int INF = 1000000000;

int resultado(Matriz <int> const& C, int n) {
	int max = 0;
	for (size_t k = 1; k <= n; ++k) {
		for (size_t i = 1; i <= n; ++i) {
			if (C[k][i] == INF) {
				return -1;
			}
			else if (C[k][i] > max) max = C[k][i];
		}
	}
	return max;
}
void Floyd(Matriz <int> const& G, Matriz <int>& C, Matriz<size_t> & camino, int & max) {
	size_t n = G.numfils() - 1;
	//inicializamos
	C = G;
	camino = Matriz<size_t>(n + 1, n + 1, 0);
	//actualizaciones de la maatriz
	for (size_t k = 1; k <= n; ++k)
		for (size_t i = 1; i <= n; ++i)
			for (size_t j = 1; j <= n; ++j) {
				int temp = C[i][k] + C[k][j];
				
				if (temp < C[i][j]) { // es mejor pasar por k
					C[i][j] = temp;
					camino[i][j] = k;
				}
				
			}
	max = resultado(C,n);
}



int convertirNombre(string nombre, vector <string>& nombres, int &index) {
	int u=0;
	for (int j = 1; j < nombres.size(); ++j) {
		if (nombre.compare(nombres[j])==0) {
			u = j;
			return u;
		}

	}
	if (u == 0) {
		
		index++;
		nombres[index] = nombre;
		u= index;
	}
	return u;
}

void leerGrafo(size_t V, size_t E) {

	Matriz<int> grafo(V + 1, V + 1, INF);
	std::vector<string> nombres(V + 1);
	for (size_t i = 1; i <= V; ++i)
		grafo[i][i] = 0;
	int u, v, max; int coste;
	string nombre;
	int indx = 0;
	for (size_t i = 1; i <= E; ++i) { // leer aristas
		cin >> nombre;
		u = convertirNombre(nombre, nombres, indx);
		cin >> nombre;
		v = convertirNombre(nombre, nombres, indx);
		if (u != v) {
			grafo[u][v] = 1;
			grafo[v][u] = 1;
		}

	}
	Matriz<int> C(0, 0); Matriz<size_t> camino(0, 0);
	if (V == 1) {
		cout << 0 << endl;
	}
	else {
	Floyd(grafo, C, camino, max);
	if (max!=-1) {
		cout << max << endl;
	}
	else cout << "DESCONECTADA" << endl;
	}
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int V, E;
	std::cin >> V;
	std::cin >> E;
	while (std::cin) {
		leerGrafo(V,E);
		std::cin >> V;
		std::cin >> E;
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}