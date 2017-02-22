//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda

/*
*/
#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

using namespace std;




bool resuelveCaso() {
	PriorityQueue<int, greater<int>> maxQ;
	int contador, num, precio, resultado;
	resultado = 0;
	std::cin >> num;
	if (!std::cin) {
		return false;
	}
	else {
		for (int i = 0; i < num; i++) {
			std::cin >> precio;
			maxQ.push(precio);
		}
		while (maxQ.size()>2) {
			maxQ.pop();
			maxQ.pop();
			resultado = resultado + maxQ.top();
			maxQ.pop();

		}
		std::cout << resultado << std::endl;
		return true;
	}

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