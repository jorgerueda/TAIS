//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda

/*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Edificio {
	int izq;
	int derecha;
	Edificio(int i, int d) : izq(i), derecha(d) {}
	bool operator < (const Edificio& str) const
	{
		return (derecha < str.derecha);
	}
};

vector<Edificio> leerEdificios(int numE) {
	int i, d;
	vector<Edificio> edificios;
	for (int j = 0; j < numE; j++) {
		cin >> i;
		cin >> d;
		edificios.push_back(Edificio(i, d));
	}
	std::sort(edificios.begin(), edificios.end());
	return edificios;

}

bool resuelveCaso() {
	int numE;
	int ultimoTunel;
	int contador=1;
	cin >> numE;
	if (numE == 0) {
		return false;
	}
	else {
		vector<Edificio> edificios = leerEdificios(numE);
		ultimoTunel = edificios[0].derecha;
		for (int i = 1; i < numE; i++) {
			if (edificios[i].izq >= ultimoTunel) {
				ultimoTunel = edificios[i].derecha;
				contador++;
			}

		}

		cout << contador<< endl;
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