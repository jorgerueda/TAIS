
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N, L, agujero;
	int anterior=0;
	int contador =0;
	cin >> N;
	vector<int> manguera;

	 if (!cin)
   return false;

	 cin >> L;
	 for (int i = 0; i < N; ++i) {

		 cin >> agujero;
		 manguera.push_back(agujero);
	 }

	// resolver caso

	 for (int a : manguera) {
		 if (anterior < a) {
			 contador++;
			 anterior = a + L;
		 }
	 }
	 cout << contador << endl;
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
