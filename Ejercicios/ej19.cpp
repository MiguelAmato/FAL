// Nombre del alumno Miguel Amato   
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



int resolver(const vector<int>& v, const int& intervalo) {
    int ini = v[0], suma = 0, maxSuma = 0, pos = 0, numMax = v[0], posMax = 0, posIni = 0;

    for (int i = 0; i < intervalo; i++) {
        suma += v[i];
        if (v[i] >= numMax) {
            numMax = v[i];
            posMax = i;
        }
    }
    maxSuma = suma;
    pos = 0;
   
    for (int i = intervalo; i < v.size(); i++) {
        suma = suma - ini;
        posIni++;
        ini = v[posIni]; // i - intervalo + 1
        suma += v[i];
        if (v[i] >= numMax) {
            numMax = v[i];
            posMax = i;
        }
        if (posMax >= posIni) {
             if (suma >= maxSuma) {
                 maxSuma = suma;
                 pos = i - intervalo + 1;
             }
        }
    }

    return pos;
}


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
