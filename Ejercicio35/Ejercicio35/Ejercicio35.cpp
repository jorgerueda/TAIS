//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda

/*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;

void palindromo(vector<char>const & palabra, Matriz<int>& palindromos) {

	size_t n = palabra.size() - 1;
	//rellenar la matriz
	for (int i = 0; i < n; ++i) {
		for (int j = n; j >0 ; --j) {

			if (palabra[i] != palabra[j]) { // no se pueden ser palindromos
				palindromos[i][j] = max(palindromos[i+1][j], palindromos[i][j-1]+1);
			}
			else {
				palindromos[i][j] = palindromos[i+1][j -1];
			}
		}
	}

}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	string palabra;
	vector<char> letras;
	
	std::cin >> palabra;
	while (std::cin) {
		letras = {};		
		for (int i = 0; i < palabra.length(); i++)
		{
			letras.push_back(palabra[i]);
		}
		Matriz<int> palindromos(letras.size(), letras.size(), 0);
		palindromo(letras,palindromos);
		std::cin >> palabra;
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}