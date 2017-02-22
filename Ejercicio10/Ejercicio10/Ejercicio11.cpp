
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int V, A;

	cin >> V>>A;
	Grafo grafo(V);
	int a, b;
	for (int i = 0; i < A; ++i) {
		cin >> a >> b;
		grafo.ponArista(a, b);
	}
	
	
	cout << "SI" << endl;
	return true;






	// leer resto del caso

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
