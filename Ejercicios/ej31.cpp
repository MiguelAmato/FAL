// Nombre del alumno Miguel Amato
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int recursivoFinal(int n, short d, int cont) {
    // Caso base
    if (n == 0) { 
        return cont;  
    }
    // Caso recursivo
    else {
        if (n % 10 == d) {
            return recursivoFinal(n / 10, d, cont + 1);
        }
        else {
            return recursivoFinal(n / 10, d, cont);
        }
    }
}

int recursivoNoFinal(int n, short d) {
    // Caso base
    if (n < 10) {
        if (n == d) 
            return 1;
        else 
            return 0;
    }
    // Caso recursivo
    else {
        if (n % 10 == d) 
            return recursivoNoFinal(n / 10, d) + 1;
        else 
            return recursivoNoFinal(n / 10, d);
    }
}

void resuelveCaso() {
    int numero;
    short digito; 


    cin >> numero >> digito;

    if (numero == 0 && digito == 0) {
        cout << 1 << " " << 1 << "\n";
    }
    else {
        cout << recursivoNoFinal(numero, digito) << " " << recursivoFinal(numero, digito, 0) << "\n";
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