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


/*
tb = tiempo buceo
v = valor cofre
 cantidad(i,j) = maxima cantidad de oro en un tiempo j considerando los cofres entre 1 e i

----- funcion recursiva-------
 cantidad (i-1,j)  si  tb > j
 max { cantidad(i-1,j), cantidad(i-1,j-tb) + v}

 -----casos base----
 cantidad (0,j) = 0
 mochila (i,0) = 0

*/

void cantidad_pd(vector<int> const& P, vector<int> const& V, int M,int & valor, vector<bool> & cuales, int & numCofres) {
	size_t n = P.size()-1;
	Matriz<int> cantidad(n+1 , M+1 , 0);
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (P[i] > j)
				cantidad[i][j] = cantidad[i-1][j];
			else
				cantidad[i][j] = max(cantidad[i-1][j],
					cantidad[i-1][j - P[i]] + V[i]);
		}
	}
	valor = cantidad[n][M];
	numCofres = 0;
	// cálculo de los objetos
	int resto = M;
	for (size_t i = n; i >= 1; --i) {
		if (cantidad[i][resto] == cantidad[i-1][resto]) {
			// no cogemos objeto i
			cuales[i] = false;
		}
		else { // sí cogemos objeto i
			cuales[i] = true;
			numCofres++;
			resto = resto - P[i];
		}
	}
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int num, Tiempo,prof,tiempoBuceo,numCofres,valorMax;
	std::cin >> Tiempo;
	std::cin >> num;
	while (std::cin) {
		std::vector<int> tb(num+1), valores(num+1),profundidades(num+1);
		std::vector<bool>cuales(num+1);
		for (size_t i = 0; i < num; ++i) {
			std::cin >> prof;
			tiempoBuceo = prof +( 2 * prof);
			tb[i+1] = tiempoBuceo;
			profundidades[i+1] = prof;
			std::cin >> valores[i+1];

		}
		cantidad_pd(tb, valores,Tiempo,valorMax,cuales,numCofres);
		std::cout << valorMax<<std::endl;
		std::cout << numCofres << std::endl;
		for (int i = 0; i <= num; i++) {
			if (cuales[i]) {
				std::cout << std::to_string(profundidades[i])+" ";
				std::cout << std::to_string(valores[i]) << std::endl;
			}
		}
		std::cout << "----" << std::endl;
		std::cin >> Tiempo;
		std::cin >> num;
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}