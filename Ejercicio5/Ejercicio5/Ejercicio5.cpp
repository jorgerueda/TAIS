
//Jorge Rueda - practica examen



#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;


PriorityQueue<int> leerDatos(int N) {
	PriorityQueue<int> cola;
	for (int i = 0; i < N; ++i) {
		
		int numero;
		cin >> numero;
		cola.push(numero);

	}

	return cola;

	}

int resolver(PriorityQueue<int> & cola) {
	if (cola.size() == 1) {
		return 0;
	}
	int numero1,numero2,aux;
	int total = 0;
	while (cola.size() > 1) {
		 numero1 = cola.top();
		cola.pop();
		 numero2 = cola.top();
		cola.pop();
		 aux = numero1 + numero2;
		cola.push(aux);
		 total = total+ aux;

	}
	return total;
	}

// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N;
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	PriorityQueue<int>cola =leerDatos(N);
	cout << resolver(cola) << endl;
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
