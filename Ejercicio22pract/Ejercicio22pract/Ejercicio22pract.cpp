
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N, dato;
	int a, b;
	int resultado=0;
	cin >> N;
	PriorityQueue <int,greater<int>> broncos;
	PriorityQueue <int,less<int>> rivales;

	if (N == 0) // no hay más casos
		return false;

	for (int i = 0; i < N; ++i){
		cin >> dato;
		rivales.push(dato);
	}
	for (int i = 0; i < N; ++i) {
		cin >> dato;
		broncos.push(dato);
	}

	for (int i = 1; i <=N; ++i) {
		a = broncos.top();
		b = rivales.top();
		if (a > b) {
			resultado += a - b;
		}
		broncos.pop(); rivales.pop();
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
