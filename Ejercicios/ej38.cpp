// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

char buscar(const vector<char> & v, char inicio, int ini, int fin) {
    if (ini >= fin) {
        return ini + inicio;
    }
    else if (ini + 1 == fin) {
        return ini + inicio;
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] > mitad + inicio) {
            return buscar(v, inicio, ini, mitad + 1);
        }
        else {
            return buscar(v, inicio, mitad + 1, fin);
        }
    }
}

void resuelveCaso() {
    char ini, fin;
    cin >> ini >> fin;
    vector<char> v;
    char aux;
    for (int i = 0; i < (fin - ini); i++) {
        cin >> aux;
        v.push_back(aux);
    }
    char buscado = buscar(v, ini, 0, v.size());
    if (buscado == v[v.size() - 1]) {
        cout << char(buscado + 1) << "\n";
    }
    else {
        cout << buscado << "\n";
    }
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