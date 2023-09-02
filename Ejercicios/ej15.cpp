// Nombre del alumno Miguel Amato   
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



 int resolver(const vector<int> & v, const int & intervalo) {
     int ini = v[0], suma = 0, maxSuma, pos;

     for (int i = 0; i < intervalo; i++) {
         suma += v[i];
     }

     maxSuma = suma;
   
     pos = 0;
    
     for (int i = intervalo; i < v.size(); i++) {
         suma = suma - ini;
         ini = v[i - intervalo + 1];
         suma += v[i];
        if (suma >= maxSuma) {
            maxSuma = suma;
            pos = i - intervalo + 1;
        }
     }

     return pos;
}

 // La funcion de coste de algoritmo es: 2 + 3n + 1 + 2 + 8m - 8n + 1 + 1 = 8m - 5n + 7; O(m) donde m es el numero de elementos que tiene el vector.


bool resuelveCaso() {
    int nPaginas, intervalo;
    cin >> nPaginas >> intervalo;

    if (nPaginas == 0 && intervalo == 0)
        return false;

    vector<int> v(nPaginas);
    for (int i = 0; i < v.size(); i++) { cin >> v[i]; }
    int sol = resolver(v, intervalo);
    cout << sol << "\n";

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
