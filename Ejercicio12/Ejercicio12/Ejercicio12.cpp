//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda

/*
*/
#include <iostream>
#include <fstream>
#include <string>
#include "GrafoDirigido.h"
#include "BFSCalculadora.h"

using namespace std;


void cargarGrafo(GrafoDirigido & grafo) {
	int a, b, c;
	for (int i = 0; i < grafo.V(); ++i) {

		a = (i + 1) % 10000;
		b = (i * 2) % 10000;
		c = (i / 3) % 10000;
		grafo.ponArista(i, a);
		grafo.ponArista(i, b);
		grafo.ponArista(i, c);
	}



}

bool resuelveCaso(GrafoDirigido const& grafo) {
	int origen, destino;
	cin >> origen;
	if (!cin) {
		return false;
	}

	cin >> destino;

	BFSCalculadora bdp(grafo, origen, destino);

	cout << bdp.minDisTo() << endl;

}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	GrafoDirigido grafo(10000);
	cargarGrafo(grafo);
	while (resuelveCaso(grafo));

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}