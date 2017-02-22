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
	PriorityQueue<int, less<int>> minQ;

	int contador, num, precio, resultado,rival,local;
	bool exit = false;
	resultado = 0;
	std::cin >> num;
	if (num==0) {
		return false;
	}
	else {
		for (int i = 0; i < num; i++) {
			std::cin >> precio;
			minQ.push(precio);
		}
		for (int i = 0; i < num; i++) {
			std::cin >> precio;
			maxQ.push(precio);
		}
		while (maxQ.size()>0 && !exit) {
			rival = minQ.top();
			local = maxQ.top();
			maxQ.pop();
			minQ.pop();
			if (rival > local) {
				exit = true;
			}
			else {
				resultado = resultado + (local - rival);
			}

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