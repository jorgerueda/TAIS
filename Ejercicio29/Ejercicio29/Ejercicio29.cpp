//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda

/*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;





void calcularPuntuacion(vector<int> const & M, int C, vector<double> & dardos) {
	size_t n = M.size() - 1;
	dardos[0] = 0;
	//rellenamos matriz
	for (int i = 1; i <= n; ++i) {
		for (int j = M[i]; j <= C; j++) {
			dardos[j] = min(dardos[j], dardos[j - M[i]] + 1);
		}
	}


}

 bool calcularDardos(vector<int> const& P, int C,vector<double> & dardos, vector<int> & cuantas) {
	size_t n = P.size() - 1;
	int i = n; int j = C;
	dardos[0] = 0;
	//rellenamos matriz
	for (int i = 1; i <= n; ++i) {
		for (int j = P[i]; j <= C; j++) {
			dardos[j] = min(dardos[j], dardos[j - P[i]] + 1);
		}
	}
	int num = dardos[C];
	string sol= std::to_string(num) + ":";
	while (j > 0) {
		if (i == 0) {
			return false;
		}
		if (P[i] <= j && dardos[j] == dardos[j -P[i]] + 1) {
			//tomamos  dardo del sector de tipo i
			++cuantas[i];
			sol=sol+ " " + std::to_string(P[i]);
			j = j - P[i];

		}
		else // no cogemos dardos del sector de tipo i
			--i;

	}
	std::cout << sol << endl;
	 return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int num, puntuacion, prof, tiempoBuceo, numCofres, valorMax;
	std::cin >> puntuacion;
	std::cin >> num;
	while (std::cin) {
		std::vector<int> P(num+1), cuantas(num + 1,0);
		std::vector<double> dardos(puntuacion + 1, numeric_limits<double>::infinity());
		for (size_t i = 0; i < num; ++i) {
			std::cin >> P[i+1];
		}
		//calcularPuntuacion(P, puntuacion, dardos);
		if (calcularDardos(P, puntuacion, dardos, cuantas)) {
			/*int num = dardos[puntuacion];
			std::cout << std::to_string(num) + ":";
			for (int i = num+1; i>0; i--) {
				if (cuantas[i] != 0) {
					for (int j = 0; j < cuantas[i]; j++) {
						//std::cout << " " + std::to_string(P[i]);
					}
				}
			}std::cout << endl;*/
		}
		else {
			std::cout << "Imposible" << std::endl;
		}
		
		std::cin >> puntuacion;
		std::cin >> num;
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}