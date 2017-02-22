
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct conferencia{

	int inicio;
	int final;
	friend bool operator <(const conferencia a, const conferencia b) {
		return a.inicio < b.inicio;
	}
};

// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N;
	cin >> N;
	

	if (N == 0) // no hay más casos
		return false;

	conferencia c;
	int contador = 1;
	vector<conferencia> conferencias;
	PriorityQueue<int, less<int>> libres;
	for (int i = 0; i < N; ++i) {
		cin >> c.inicio >> c.final;
		conferencias.push_back(c);
		
	}

	std::sort(conferencias.begin(), conferencias.end());

	libres.push(conferencias[0].final);

	for (int i = 1; i < N; ++i) {
	
		if (conferencias[i].inicio < libres.top()) {
			contador++;
			libres.push(conferencias[i].final);
		}
		else {
			libres.pop();
			libres.push(conferencias[i].final);
		}
	}
		
	

	cout << contador << endl;
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
