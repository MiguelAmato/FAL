// Nombre del alumno Miguel Amato (El suspenso)
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool resuelveCaso() {
    int fecha1, fecha2; 
    long long int aux, suma = 0;

     cin >> fecha1 >> fecha2;

     if (fecha1 == 0 && fecha2 == 0)
        return false;

     vector<long long int> nacimientos;

     for (int i = 0; i <= (fecha2 - fecha1); i++) {
         cin >> aux;
         suma += aux;
         nacimientos.push_back(suma);
     }

     int preguntas;
     cin >> preguntas;

     int inicio, fin;

     for (int i = 0; i < preguntas; i++) {
         cin >> inicio >> fin;
         if (inicio == fecha1) {
             cout << nacimientos[fin - fecha1] << "\n";
         }
         else {
             cout << nacimientos[fin - fecha1] - nacimientos[inicio - fecha1 - 1] << "\n";
         }
     }
     cout << "---\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
