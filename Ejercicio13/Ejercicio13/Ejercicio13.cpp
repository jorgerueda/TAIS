
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "GrafoDirigido.h"

using namespace std;



struct Salto
{
	int origen;
	int destino;

};

Salto getAtajo(int origen, vector<Salto> const& saltos) {
	for (Salto salto : saltos) {
		if (salto.origen == origen) {
			return salto;
		}

	}

 }
// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N,K,S,E,destino,origen;
	int dimension;
	Salto salto;
	
	cin >> N>>K>>S>>E;

	if (N == 0 && K == 0 && S==0 & E==0) // no hay más casos
		return false;

	dimension = N*N;
	vector<bool> haySalto(dimension,false);
	vector<Salto> saltos;
	
	for (int i= 0; i < S + E; i++) {

		cin >> origen >>destino;
		salto.destino = destino - 1;
		salto.origen = origen - 1;
		haySalto[origen-1] = true;
		saltos.push_back(salto);
	}

	GrafoDirigido grafo(dimension);
	int casillas;
	for (int i = 0; i < dimension; ++i) {
		if (!haySalto[i]) {
			
			if (K > (dimension - i)) {
				casillas = dimension - i;
			}
			else {
				casillas = K;
			}
			for (int j = 1; j <= casillas && i+j < dimension; ++j) {

				if (haySalto[i + j]) {
					grafo.ponArista(i, getAtajo(i+j, saltos).destino);
				}
				else {
					grafo.ponArista(i, i + j);
				}

			}
		}
	}

	BreadthFirstDirectedPaths bfs(grafo,0);
	cout << bfs.distance(dimension - 1) << endl;


	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
