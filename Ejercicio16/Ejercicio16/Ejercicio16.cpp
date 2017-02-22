
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "GrafoValorado.h"
#include "Prism.h"

using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int I,P;
	cin >> I;
	int inicio, fin, coste;

	if (!cin)
   return false;

	cin >> P;

	GrafoValorado <int> grafo (I);
	for (int i = 0; i < P; ++i) {

		cin >> inicio >> fin >> coste;
		Arista<int> a(inicio - 1, fin - 1, coste);
		grafo.ponArista(a);
	}

	Prism pr(grafo);
	int costeTotal = pr.coste();
	if (costeTotal != 0) {
		cout << costeTotal << endl;
	}
	else {
		cout << "No hay puentes suficientes" << endl;
	}



	// resolver caso

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
