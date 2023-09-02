// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez G16

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int sol(const vector<int> & v, const int & intervalo) {
    int ini = v[0], indIni = 0, cont = 1, max = 1; 

    for (int i = 1; i < v.size(); ++i) {
        if (ini != v[i] && v[i] - ini >= intervalo) {
            if (cont > max)
                max = cont;
            cont = 0; 
            ++indIni;
            ini = v[indIni];
        }
        else {
            cont++;
        }
    }
    return max;
}

bool resuelveCaso() {
    int nNacimientos, intervalo;
    cin >> nNacimientos >> intervalo;
    if (nNacimientos == 0 && intervalo == 0)
        return false;
    vector<int> v(nNacimientos);
    for (int i = 0; i < v.size(); ++i) cin >> v[i];
    cout << sol(v, intervalo) << "\n";
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