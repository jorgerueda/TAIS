
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;



struct Edificio
{
	int izq;
	int derecha;

	friend bool operator <(const Edificio a, const Edificio b){

		if (a.derecha < b.derecha) return true;
		else return false;
	}

};


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N;
	int max=-1;
	int resultado=0;
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	Edificio e;
	PriorityQueue <Edificio> edificios;

	for (int i = 0; i < N; ++i) {
		cin >> e.izq >> e.derecha;
		edificios.push(e);
	} 

	while (!edificios.empty()) {

		e = edificios.top();
		if (e.izq >= max) {
			resultado++;
			max = e.derecha;
		}
		edificios.pop();
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
