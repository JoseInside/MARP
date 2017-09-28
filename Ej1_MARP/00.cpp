
// Jose María Monreal González

#include <algorithm>
#include <iostream>
#include <fstream>

#include "bintree_eda.h"

// lee un árbol binario de la entrada estándar
template <typename T>
bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return{ iz, raiz, dr };
	}
}

// propios o los de las estructuras de datos de clase
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(bintree<char> const& arbol) {
	
	if (arbol.empty())
		return 0;
	else
		return 1 + std::max(resolver(arbol.left()), resolver(arbol.right()));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	auto arbol = leerArbol('.');
	int sol = resolver(arbol);
	std::cout << sol << "\n";
}
int main() {

#ifndef DOMJUDGE
	std::ifstream in("..//CasosEjemplo/00.txt");
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
