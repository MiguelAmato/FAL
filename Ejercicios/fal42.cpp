// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int solucion(const vector<int>& v, int ini, int fin, const int& num) {
    if (ini >= fin) 
        return ini;
    else if (ini + 1 == fin) 
        return ini;
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] == mitad + num)
            return mitad;
        else if (v[mitad] < mitad + num)
            return solucion(v, mitad, fin, num);
        else 
            return solucion(v, ini, mitad, num);
    }
}

void resuelveCaso() {
    int n, canto;
    cin >> n >> canto;
    vector<int> v;
    int e;
    for (int i = 0; i < n; ++i) {
        cin >> e;
        v.push_back(e);
    }
    int sol = solucion(v, 0, v.size(), canto);
    if (v[sol] == canto + sol) {
        cout << v[sol] << "\n";
    }
    else {
        cout << "NO\n";
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