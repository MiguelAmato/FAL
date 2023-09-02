// Nombre del alumno Miguel Amato   
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int busquedaI(const vector<int>& v, int h, int ini, int fin) {
    if (ini >= fin) {
        return ini;
    }
    else if (ini + 1 == fin) { 
        return ini;
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] < h) {
            return busquedaI(v, h, mitad + 1, fin);
        }
        else {
            return busquedaI(v, h, ini, mitad + 1);
        }
    }
}

int busquedaD(const vector<int>& v, int h, int ini, int fin) {
    if (ini >= fin) {
        return ini;
    }
    else if (ini + 1 == fin) { 
        return ini;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] > h) {
            return busquedaD(v, h, ini, mitad);
        }
        else {
            return busquedaD(v, h, mitad, fin);
        }
    }
}

bool resuelveCaso() {
    int n, h;
    cin >> n >> h;
    if (!cin)
        return false;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    int posPrimero = busquedaI(v, h, 0, v.size());
    if (posPrimero == v.size() || v[posPrimero] != h) {
        cout << "NO EXISTE\n";
    }
    else {
        int posUltimo = busquedaD(v, h, 0, v.size());
        if (posUltimo == posPrimero) {
            cout << posPrimero << "\n";
        }
        else {
            cout << posPrimero << " " << posUltimo << "\n";
        }
    }
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