//Jorge Rueda - practica examen

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

class comparatorMin{
public:
	bool operator()(int a, int b) {
		return a < b;
	 }

	
};

class comparatorMax {
public:
	bool operator()(int a, int b) {
		return a > b;
	}

};

void resuelve(int N) {
	int num;
	PriorityQueue<int,comparatorMin>colaMin;
	PriorityQueue<int, comparatorMax>colaMax;

	
	for (int i = 0; i < N; ++i) {
		cin >> num;
		colaMin.push(num);
		if (colaMax.size() + colaMin.size() == 1) {
			cout << colaMin.top()*2 << " ";
		}else if (colaMax.size() + colaMin.size() == 2) {
			cout << colaMin.top() + num << " ";
		}
		else {
			if (colaMin.size() > 2) {
				colaMax.push(colaMin.top());
				colaMin.pop();
			}
			if ((colaMax.size() + colaMin.size()) % 2 == 0) {
				cout << (colaMin.top() + colaMax.top()) << " ";
			}
			else {
				cout << colaMin.top() * 2 << " ";
			}
		}
	}
	cout << endl;


 }
// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N;
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	resuelve(N);

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
