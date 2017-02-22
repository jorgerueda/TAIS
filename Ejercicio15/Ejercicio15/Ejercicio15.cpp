//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "Grafo.h"
#include "ManchasPetroleo.h"

using namespace std;





void resuelveCaso() {
		int _f, _c, numManchasAdicionales;
		std::cin >> _f;
		while (std::cin) {
		
		
		std::cin >> _c;
		ManchasPetroleo manchas(_f, _c);
		std::cout << manchas.getamMax()<< " ";
		while (manchas.agregarSigMancha()) {
			std::cout << manchas.getamMax()<< " ";
		}
		std::cout << std::endl;
	}
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}