// Nombre del alumno Miguel Amato
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int recursivoFinal(int n, int t) { // t de transformado
    // Aqui irá la final
    return 0;
}

int recursivoNoFinal(int n) {
    if (n < 10) {
        if (n % 2 == 0) {
            return n + 1;
        }
        else {
            return n - 1;
        }
    }
    else {
        if (n % 2 == 0) {
            return (recursivoNoFinal(n / 10) * 10) + (n % 10 + 1);
        }
        else {
            return (recursivoNoFinal(n / 10) * 10) + (n % 10 - 1);
        }
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    cout << recursivoNoFinal(n) << "\n";
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