
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "CC.h"
using namespace std;


// comentario sobre la solución y su coste
void resuelveCaso() {
	int N, M,a,b;
	
	std::cin >> N >> M;
	Grafo grafo(N);

	for (int i = 0; i < M; ++i) {
		std::cin >> a >> b;
		grafo.ponArista(a-1, b-1);
	}

	int max = 0;
	int aux = 0;
	CC cc(grafo);
	for (int i = 0; i < N;++i) {
		
		
		aux = cc.size(i);
		if (aux > max) {
			
			max = aux;
		}
		
		
	}
	std::cout << max << endl;
	

	
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int N;
	cin >> N;
	for (int i = 0; i < N;++i) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
