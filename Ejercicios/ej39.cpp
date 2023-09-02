// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int buscar(const vector<int> & v, int ini, int fin) {
    if (ini + 1 == fin) {
        return ini;
    }
    else {
        int mitad = (ini + fin) / 2; 
        if (v[mitad] > v[mitad - 1]) {
            return buscar(v, ini, mitad);
        }
        else {
            return buscar(v, mitad, fin);
        }
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin)
        return false;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    int minimo = buscar(v, 0, v.size());
    cout << v[minimo] << "\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso());

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}