#ifndef MANCHASPETROLEO_H
#define MANCHASPETROLEO_H

#include "Grafo.h"
#include "CC.h"

class ManchasPetroleo {


private:
	Grafo grafo;
	int filas, columnas,indexManchaAdicional,numeroManchasAdicionales,contador,tamMaxMancha;
	
	std::vector <std::vector<bool>> marked;
	std::vector<int> manchasAdicionales;
	std::vector<bool> markedDFS;
	bool hayManchas; // si despues de crear el grafo no hay manchas, paramos. Tamaño 0

void crearGrafo() {
	
	char mancha;
	
	//std::cin.ignore(256,'\n'); //borramos el Enter
	std::cin.get(mancha);
	for (int i = 0; i < filas; i++) { //filas
		for (int j = 0; j < columnas; j++) { //columnas
			std::cin.get(mancha);
			if (mancha == '#') {
				hayManchas = true;
				marked[i][j] = true;
				if (i > 0) {
					if (marked[i - 1][j]) { //se comprueba si hay mancha en la casilla superior
						grafo.ponArista((i*columnas) + j, ((i - 1)*columnas) + j); // el numero de casilla se calcula con (i * nºcolumnas)+ j
					}
				}
				if (j > 0) {
					if (marked[i][j-1]) { // se comprueba si hay mancha en la casilla de la izq
						grafo.ponArista((i*columnas) + j, (i*columnas) +(j-1));
					}
				}
			}



		}//end for columnas
		std::cin.get(mancha);
		//std::cin.ignore(256, '\n'); //borramos el Enter

	}//end for filas
	if (std::cin) {
		int numero, _i, _j;
		std::cin >> numero;
		for (int i = 0; i < numero; ++i) {
			std::cin >> _i;
			std::cin >> _j;
			_i = _i - 1;
			_j = _j - 1;
			manchasAdicionales.push_back((_i * columnas) + _j);
		}
	}


}

void agregarMancha() {

	int _i, _j;
	///////
	int mancha = manchasAdicionales.at(indexManchaAdicional);
	indexManchaAdicional++;
	 _i = (mancha / columnas);
	 _j = (mancha % columnas);



	/////////

	//std::cin >> _i;
	//std::cin >> _j;
	//int mancha = _i *columnas + _j;
	if (_i > 0) {
		if (marked[_i - 1][_j]) { //comprobamos casilla superior
			grafo.ponArista(_i *columnas + _j, ((_i - 1) * columnas) + _j);
		}

	}
	if (_i < filas - 1)
		if (marked[_i + 1][_j]) {//comprobamos casilla inferior
			grafo.ponArista(_i * columnas + _j, ((_i + 1) * columnas) + _j);
		}
	if (_j > 0)
		if (marked[_i][_j - 1]) { //comprobamos casilla izq
			grafo.ponArista(_i * columnas + _j, _i * columnas + (_j - 1));
		}
	if (_j < columnas - 1) { //comprobamos casilla derecha
		if (marked[_i][_j + 1]) {
			grafo.ponArista(_i * columnas + _j, _i * columnas + (_j + 1));
		}
	}

	contador = 0; //reiniciamos contador y comprobamos el tamaño de la nueva mancha agregada

	//dfs(mancha);
	//if (contador > tamMaxMancha) tamMaxMancha = contador;
	tamMaxMancha = resuelve(grafo);

}

void cargarManchasAdicionales() {

	if (std::cin) {
		int numero, _i, _j;
		std::cin >> numero;
		for (int i = 0; i < numero; ++i) {
			std::cin >> _i;
			std::cin >> _j;
			manchasAdicionales.push_back(_i * columnas + _j);
		}
	}
}



	void dfs(size_t v) {
		markedDFS[v] = true;
		for (auto w : grafo.adj(v)) {
			if (!markedDFS[w]) {
				contador++;
				dfs(w);
			}
		}
	}

	int resuelve(Grafo const& g) {

		CC cc(g);
		int max = 0;
		for (auto i = 0; i < g.V(); ++i) { //se miran  las componentes Conexas y se saca el maximo de estas
			if (max < cc.size(i))
				max = cc.size(i);
		}
		return max;

	}

public:

	ManchasPetroleo(int f, int c) : filas(f), columnas(c), grafo(f*c), marked(f, std::vector<bool>(c, false)), markedDFS(f*c, false), manchasAdicionales(0) {
		
		hayManchas = false;
		crearGrafo();
	//	cargarManchasAdicionales();
		if (!hayManchas) tamMaxMancha = 0;
		else tamMaxMancha = resuelve(grafo);
		indexManchaAdicional = 0;
	 }
	bool agregarSigMancha() {
		if (indexManchaAdicional < manchasAdicionales.size()) {
			agregarMancha();
			return true;
		}
		else return false;

	}
	


	int getamMax() {
		return tamMaxMancha;
	};


};




#endif