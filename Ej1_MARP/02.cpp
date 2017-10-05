
// Jose María Monreal González

#include <algorithm>
#include <iostream>
#include <fstream>

#include "bintree_eda.h"

// lee un árbol binario de la entrada estándar
template <typename T>
bintree<T> leerArbol(T vacio) {

	T raiz;
	auto altura;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return{ iz, raiz, dr, altura };
	}
}

int altura(bintree<int> const& arbol) {

	if (arbol.empty())
		return 0;
	else
		return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
}

bintree<int> const& recorrido(bintree<int> const& arbol){

	if (arbol.empty())
		return altura(arbol);
	else {
		//altura(arbol);
		return std::max(arbol.left(), arbol.right());
	}

}

// propios o los de las estructuras de datos de clase
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(bintree<int> const& arbol) {

	int alt_min, alt_max;

	if (arbol.empty())
		return true;

	else {

		alt_max = 1 + std::max(altura(arbol.left()), altura(arbol.right()));

		alt_min = 1 + std::min(altura(arbol.left()), altura(arbol.right()));

		if (alt_max - alt_min <= 1 && comparaHijos(arbol))
			return true;
		else return false;
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	auto arbol = leerArbol('-1');
	bool sol = resolver(arbol);

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
