
// Jose Mar�a Monreal Gonz�lez

#include <algorithm>
#include <iostream>
#include <fstream>

#include "bintree_eda.h"

// lee un �rbol binario de la entrada est�ndar
template <typename T>
bintree<T> leerArbol(T vacio) {

	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un �rbol vac�o
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return{ iz, raiz, dr };
	}
}

int altura(bintree<char> const& arbol) {

	if (arbol.empty())
		return 0;
	else
		return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
}


//Comprueba si el �rbol binario est� equilibrado
bool equilibrado(bintree<char> const& arbol) {

	int alt_min, alt_max;

	if (arbol.empty())
		return true;

	else {

		alt_max = 1 + std::max(altura(arbol.left()), altura(arbol.right()));
		alt_min = 1 + std::min(altura(arbol.left()), altura(arbol.right()));

		if (alt_max - alt_min > 1)
			return false;
		else
			return equilibrado(arbol.left()) && equilibrado(arbol.right());
	}
}


//Comprueba si el �rbol binario cumple la condici�n de un �rbol AVL
//de tener todos los hijos izquierdos del nodo menores que �ste y mayores que
//los hijos derechos.
bool cumpleCondis(bintree<char> const& arbol){

}

//Comprueba si el �rbol cumple las dos condiciones para ser AVL
bool cumpleAVL(bintree<char> const& arbol){

	return (equilibrado(arbol) && cumpleCondis(arbol));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
void resuelveCaso() {

	auto arbol = leerArbol('.');
	bool sol = cumpleAVL(arbol);

	if (sol)
		std::cout << "SI" << "\n";
	else
		std::cout << "NO" << "\n";
}
int main() {

#ifndef DOMJUDGE
	std::ifstream in("..//CasosEjemplo/02.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif	
	return 0;
}
