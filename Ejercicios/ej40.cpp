// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int buscar(const vector<int>& v1, const vector<int>& v2, int ini, int fin) {
    if (ini + 1 == fin) {
        return ini;
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v2[mitad] == v1[mitad]) {
            return buscar(v1, v2, ini, mitad + 1);
        }
        else {
            return buscar(v1, v2, mitad + 1, fin);
        }
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n - 1);
    for (int& i : v1) cin >> i;
    for (int& i : v2) cin >> i;
    int falta = buscar(v1, v2, 0, v2.size());
    cout << v1[falta] << "\n";
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