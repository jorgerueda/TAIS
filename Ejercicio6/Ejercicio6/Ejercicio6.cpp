
//Jorge Rueda - practica examen



#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

struct paciente
{
	string nombre;
	long int gravedad;
	int orden;

	friend bool operator<(paciente a, paciente b){
		if (a.gravedad > b.gravedad) return true;
		else if (a.gravedad == b.gravedad) return a.orden < b.orden;
		else return false;

	}
};
	void resuelve(int N) {
	PriorityQueue<paciente> cola;
	for (int i = 0; i < N; ++i) {

		string evento;
		paciente p;
		cin >> evento;
		if (evento.compare("I") == 0) {
			cin >> p.nombre;
			cin >> p.gravedad;
			cola.push(p);
		}
		else if(evento.compare("A") == 0){
			cout<<cola.top().nombre<<endl;
			cola.pop();
		}
	}

	
}


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N;
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	resuelve(N);
	cout << "----" << endl;
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
