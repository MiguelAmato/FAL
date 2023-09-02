// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema
int resolver(vector<int>& v) {

    sort(v.begin(), v.end());

    int valor = v[0], cont = 1, contModa = 0;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[i - 1]) {
            cont = 1;
        }
        else {
            cont++;
            if (cont > contModa) {
                valor = v[i];
                contModa = cont;
            }
        }
    }

    return valor;
}

bool resuelveCaso() {
    int nAccidentes;
    
    cin >> nAccidentes;

    if (nAccidentes == -1)
        return false;

    vector<int> v(nAccidentes);

    for (int i = 0; i < v.size(); i++) { cin >> v[i]; }

    int sol = resolver(v);

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

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}