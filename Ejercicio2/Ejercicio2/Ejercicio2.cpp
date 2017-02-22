
//  Jorge Rueda


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "BinTree.h"
using namespace std;


// lee un �rbol binario de la entrada est�ndar
BinTree<int> leerArbol() {
	int raiz;
	std::cin >> raiz;
	if (raiz == -1) { // es un �rbol vac�o
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

// N log N siendo N el n�mero de nodos.
/*
Se inicializan las variables mx y mn a un valor m�ximo y un valor m�nimo respectivamente. Necesitamos estos dos valores para almacenar y comprobar
los valores que "vamos dejando atr�s" en las hojas de los sub�rboles que conforman el �rbol y que, en principio, cumplen las condiciones de AVL.
De manera an�loga necesitamos comprobar el tama�o de las ramas. Para ello se emplea la variable global altura y las variables espec�ficas altI y altD.
*/
bool avl(BinTree<int> arbol, int& altura, int mx, int mn) {
	if (arbol.empty())
		return true;

	else {
		if (arbol.root() < mx && arbol.root() > mn) {
			int altI = altura;
			int altD = altura;

			if (!avl(arbol.left(), altI, arbol.root(), mn))
				return false;

			if (!avl(arbol.right(), altD, mx, arbol.root()))
				return false;

			//verificar la restriccion de alturas
			if (abs(altI - altD) <= 1) {
				altura = 1 + std::max(altD, altI);
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
}

bool resuelveCaso() {

	auto arbol = leerArbol();
	int altura = 0;

	//limites para los nodos
	int maximo = INT16_MAX;
	int minimo = -1;

	cout << (avl(arbol, altura, maximo, minimo) ? "Si" : "NO") << endl;

	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
