
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N;
	int dato;
	int resultado = 0;
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	vector<int>esquiadores;
	vector<int> esquies;
	for (int i = 0; i < N; ++i) {
		cin >> dato;
		esquiadores.push_back(dato);
	}
	for (int i = 0; i < N; ++i) {
		cin >> dato;
		esquies.push_back(dato);
	}

	std::sort(esquiadores.begin(), esquiadores.end());
	std::sort(esquies.begin(), esquies.end());

	for (int i = 0; i < N; i++) {
		resultado += std::abs(esquiadores[i] - esquies[i]);
	}
	
	cout << resultado << endl;

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
