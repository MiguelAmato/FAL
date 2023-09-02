// Nombre del alumno 
// Usuario del Juez 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int resolver(vector<int> const& a, vector<int> const& b, int ini, int fin) {
    if (ini >= fin) {
        return ini;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (a[mitad] == b[mitad]) {
            return resolver(a, b, mitad + 1, fin);
        }
        else {
            return resolver(a, b, ini, mitad);
        }
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> a(n);
    vector<int> b(n + 1);
    for (int& i : a) { cin >> i; }
    for (int& i : b) { cin >> i; }

    cout << b[resolver(a, b, 0, a.size())] << "\n";
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