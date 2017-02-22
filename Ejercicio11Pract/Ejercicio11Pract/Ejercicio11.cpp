
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
#include "CC.h"
using namespace std;


// comentario sobre la solución y su coste
void resuelveCaso() {
	int personas, pares;
	cin >> personas >> pares;
	Grafo grafo(personas);
	int a, b;
	for (int i = 0; i < pares; ++i) {
		cin >> a >> b;
		grafo.ponArista(a - 1, b - 1);

	}
	CC cc(grafo);
	int max = 0;
	for (int i = 0; i < personas; ++i) {
		if (cc.size(i) > max) {
			max = cc.size(i);
		}


	}

	cout << max << endl;


}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
