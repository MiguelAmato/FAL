// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez G16

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int sol (int n, int suma) {
    if (n < 10) {
        cout << n << " = ";
        return suma + n;
    }
    else {
        cout << n % 10 << " + "; 
        return sol(n / 10, suma + n % 10);
    }
}

bool resuelveCaso() {
    int n = 0;
    cin >> n;
    if (n == -1)
        return false;
    
    cout << sol(n, 0) << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso());
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}