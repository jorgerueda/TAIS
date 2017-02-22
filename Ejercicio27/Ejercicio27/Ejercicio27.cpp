
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;


int devolver_cambio1(vector<int> const& M, int C) {
	size_t n = M.size() - 1;
	Matriz <int> monedas(n + 1, C+1, 1000000);
	monedas[0][0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		monedas[i][0] = 0;
		for (int j = 1; j <= C; ++j) {
			if (M[i] > j) // no se puede considerar M[i] para pagar j
				monedas[i][j] = monedas[i-1][j];
			else
				monedas[i][j] = min(monedas[i-1][j], monedas[i][j - M[i]] + 1);
		}
	}
	return monedas[n][C];
}

// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N;
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	// si no hay centinela
	// if (!cin)
	//    return false;

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
