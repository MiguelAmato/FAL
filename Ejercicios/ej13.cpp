// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct salida {
    int ini = 0;
    int fin = 0;
};

salida resolver(const vector<int> & v, const int & altura) {
    salida devolver;
    int cont = 0, contMax = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > altura) {
            cont++;
            if (cont > contMax) {
                contMax = cont;
                devolver.fin = i;
                devolver.ini = devolver.fin - cont + 1;
            }
        }
        else {
            cont = 0;
        }
    }
    return devolver;
}

// REQUISITOS DE IMPLEMENTACION:
// El coste de complejidad del algoritmo de la funcion resolver es: O(n)

void resuelveCaso() {
    int nEdificios, hTransporte;
    cin >> nEdificios >> hTransporte;

    vector<int> v(nEdificios);

    for (int i = 0; i < v.size(); i++) { cin >> v[i]; }

    cout << resolver(v, hTransporte).ini << " " << resolver(v, hTransporte).fin << "\n";
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}