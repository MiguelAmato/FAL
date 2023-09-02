// Nombre del alumno Miguel Amato
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// En la primera entrega del juez se me olvido mencionar que la funcion era no final, aqui ya lo indico.
// En esta entrega probare el funcionamiento de la recursiva final

int sumaDigitosFinal(int n, int suma) { 
    int devolver;
    // Caso base
    if (n == 0) {
        devolver = suma;
    }
    // Caso recursivo
    else {
        devolver = sumaDigitosFinal(n / 10, suma + (n % 10));
    }
    return devolver;
}
 
 int sumaDigitosNoFinal(int n) {
     int suma;
     // Caso base
     if (n < 10) 
         suma = n;
     // Caso recursivo
     else {
         suma = sumaDigitosNoFinal(n / 10) + (n % 10);
     }
     return suma;
}

void resuelveCaso() {
    int numElementos, numero, elemento, sumaDigito;
    bool espacios = false; // Es un booleano para saber cuando puedo empezar a imprimir espacios por consola 

    cin >> numElementos >> numero;

    numero = sumaDigitosFinal(numero, 0);

    for (int i = 0; i < numElementos; i++) {
        cin >> elemento;
        sumaDigito = sumaDigitosFinal(elemento, 0);
        if (sumaDigito == numero) {
            if (espacios) {
                cout << " ";
            }
            cout << elemento;
            espacios = true;
        }
    }
    cout << "\n";
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