// Nombre del alumno Miguel Amato
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int resolver(const vector<int>& v, const int k) {
    int contSeg = 0, contActual = 1;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i + 1] % v[i] == 0) {
            contActual++;
            if (contActual == k) {
                contSeg++;
                contActual = k - 1;
            }
        }
        else {
            contActual = 1;
        }
    }
    return contSeg;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == -1)
        return false;
    int k;
    cin >> k;
    vector<int> v(n);
    for (int& i : v) { cin >> i; }
    int sol;
    if (k == 1) {
        sol = n;
    }
    else {
        sol = resolver(v, k);
    }
    cout << sol << "\n";
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