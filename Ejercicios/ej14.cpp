// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct salida {
    int racha = 0;
    int veces = 0;
    int partidos = 0;
};

 salida resolver(const vector<int> & v) {
     salida devolver;

     int cont = 0, contMax = 0, ultimaPos = -1;

     for (int i = 0; i < v.size(); i++) {
         if (v[i] > 0) {
             cont++;
             if (cont > contMax) {
                 contMax = cont;
                 devolver.veces = 1;
                 ultimaPos = i;
             }
             else if (cont == contMax) {
                 devolver.veces++;
                 ultimaPos = i;
             }
         }
         else {
             cont = 0;
         }
     }

     devolver.racha = contMax;
     devolver.partidos = (v.size() - 1) - ultimaPos;
     return devolver;
}

bool resuelveCaso() {
    int nPartidos;
    cin >> nPartidos;

    if (!cin)
        return false;

    vector<int> v(nPartidos);

    for (int i = 0; i < v.size(); i++) { cin >> v[i]; };

    cout << resolver(v).racha << " " 
         << resolver(v).veces << " " 
         << resolver(v).partidos << "\n";

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