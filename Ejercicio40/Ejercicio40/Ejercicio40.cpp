//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda

/*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
#include "Matriz.h"
using namespace std;


struct nodo {
	vector<bool> sol;
	size_t k;
	double beneficio;
	double beneficio_optimo;
	vector<double> ocupada;

	friend bool operator>(const nodo &a, const nodo &b) {
		return a.beneficio_optimo > b.beneficio_optimo;
	}
};

struct song
{
	double duracion;
	double puntuacion;


	friend bool operator>(const song &a, const song &b) {
		return (a.puntuacion /a.duracion )>( b.puntuacion /b.duracion);
	}
};



int calculoOptimista(const std::vector<song> &canciones, size_t t, size_t k, double beneficio, vector<double>& ocupada) {
	double hueco = t - (ocupada[0] + ocupada[1]);
	int opt = beneficio;
	size_t i = k + 1;
	while (i < canciones.size() && canciones[i].duracion <= hueco) {
		hueco = hueco - canciones[i].duracion;
		opt = opt + canciones[i].puntuacion;
		i++;
	}
	if (i < canciones.size()) 
		opt = opt + (hueco / canciones[i].duracion)*canciones[i].puntuacion;
	
	return opt;
}


double canciones_rp(vector<song> const& canciones, int t) {
	nodo y;
	PriorityQueue<nodo,std::greater<nodo>> cola;
	double benef_mejor = -1;
	y.k = -1;
	y.sol = std::vector<bool> (canciones.size() , false);
	y.ocupada = std::vector<double>(2, 0);
	y.beneficio = 0;
	y.beneficio_optimo = calculoOptimista(canciones, t, y.k, y.beneficio, y.ocupada);
	cola.push(y);
	
	while (!cola.empty() && (cola.top().beneficio_optimo > benef_mejor)) {
		
		y = cola.top(); cola.pop();
		nodo x(y);
		x.k ++;
		//grabar en cara 1
		if (x.ocupada[0] + canciones[x.k].duracion <= t / 2) {
			x.sol[x.k] = true;
			x.ocupada[0] = y.ocupada[0] + canciones[x.k].duracion;
			x.beneficio = y.beneficio + canciones[x.k].puntuacion;
			x.beneficio_optimo = y.beneficio_optimo;
			if (x.k == canciones.size()-1) {
				benef_mejor = x.beneficio;
			}
			else
			{
				cola.push(x);
			}
		}
		if (x.ocupada[0] != x.ocupada[1]) {
			//grabar en cara 2
			if (x.ocupada[1] + canciones[x.k].duracion <= t / 2) {
				x.sol[x.k] = true;
				x.ocupada[0] = y.ocupada[0];
				x.ocupada[1] = y.ocupada[1] + canciones[x.k].duracion;
				x.beneficio = y.beneficio + canciones[x.k].puntuacion;
				x.beneficio_optimo = y.beneficio_optimo;
				if (x.k == canciones.size()-1) {
					benef_mejor = x.beneficio;
				}
				else
				{
					cola.push(x);
				}
			}
		}
		//no grabar
		x.ocupada = y.ocupada;
		x.beneficio = y.beneficio;
		x.beneficio_optimo = calculoOptimista(canciones, t, x.k, x.beneficio, x.ocupada);
		if (x.beneficio_optimo >= benef_mejor) {
			x.sol[x.k] = false;
			if (x.k == canciones.size()-1) {
				benef_mejor = x.beneficio;
			}
			else
			{
				cola.push(x);
			}
		}
	}
	return benef_mejor;
}

void resuelveCaso(int N) {
	vector<song> canciones(N);
	song s;
	
	int duracion_cara;
	vector<double>  beneficio_mejor;
	std::cin >> duracion_cara;
	for (size_t i = 0; i < N; i++)
	{	
		std::cin >> s.duracion;
		std::cin >> s.puntuacion;
		canciones[i] = s;
	}
	std::sort(canciones.begin(), canciones.end(), std::greater<song>());
	std::cout << canciones_rp(canciones, duracion_cara * 2) << std::endl;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int canciones;
	std::cin >> canciones;
	while (canciones != 0) {
		resuelveCaso(canciones);
		std::cin >> canciones;
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}