// Nombre del alumno Miguel Amato
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int buscar(const vector<int>& v, int ini, int fin) {
    if (ini >= fin) {
        return ini;
    }
    if (ini + 1 == fin) {
        return ini;
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] < v[ini]) {
            return buscar(v, mitad, fin);
        }
        else {
            return buscar(v, ini, mitad + 1);
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
    if (v.size() > 1 && v[minimo] > v[minimo + 1])
        cout << v[minimo + 1] << "\n";
    else
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