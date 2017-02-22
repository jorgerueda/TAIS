
//Jorge Rueda - practica examen


#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

struct usuario
{
	int id,periodo,periodoAcumulado;

	friend bool operator <(usuario a, usuario b) {
		if (a.periodoAcumulado < b.periodoAcumulado)return true;
		if (a.periodoAcumulado == b.periodoAcumulado)return a.id < b.id;
		if (a.periodoAcumulado > b.periodoAcumulado)return false;
	}

};


void resolver(int N) {
	usuario u;
	PriorityQueue<usuario> cola;
	int num;

	for (int i = 0; i < N; ++i) {
		cin >> u.id >> u.periodo;
		u.periodoAcumulado = u.periodo;
		cola.push(u);
	}

	cin >> num;
	for (int i = 0; i < num; ++i) {
		usuario us = cola.top();
		cout << us.id << endl;
		us.periodoAcumulado = us.periodoAcumulado + us.periodo;
		cola.pop();
		cola.push(us);
	}
	cout << "----" << endl;
}
// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N;
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	resolver(N);

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
