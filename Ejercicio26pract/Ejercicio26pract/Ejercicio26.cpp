
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct restaurante {
	int inicio;
	int final;

	friend bool operator <(const restaurante a, const restaurante b) {
		return a.inicio < b.inicio;
	}
};

// comentario sobre la solución y su coste
bool resuelveCaso() {
	int L,N;
	cin >> L;

	
	if (!cin)
    return false;

	cin >> N;
	restaurante res;
	vector<restaurante> restaurantes;
	int ini;
	int r;
	int maxDerecha;
	int derecha;
	int contador = 0;
	for (int i = 0; i < N; ++i) {
		cin>> ini>> r;
		res.inicio = ini - r;
		res.final = ini + r;
		restaurantes.push_back(res);

		
	}
	std::sort(restaurantes.begin(), restaurantes.end());

	if (restaurantes[0].inicio != 0) {
		cout << "-1" << endl;
		return true;
	}
	
	maxDerecha = restaurantes[0].final;
	derecha = restaurantes[0].final;;

	for (int i = 1; i < N; ++i) {

		if (restaurantes[i].inicio > maxDerecha) {
		

				cout << "-1" << endl;
				return true;
			}
			else if(restaurantes[i].final> derecha){

				contador++;
				derecha = restaurantes[i].final;
			}
		}
		else {

		}
	}
	// resolver caso

	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos1.txt");
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
