// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> & v, const vector<int>& aux) {
    vector<int> lista;
    int max = aux[0];
    lista.push_back(1);
    for (int i = 1; i < aux.size(); i++) {
        if (aux[i] == max) {
            lista.push_back(i + 1);
        }
        else if (aux[i] > max) {
            lista.clear();
            max = aux[i];
            lista.push_back(i + 1);
        }
    }

    return lista;
}

bool resuelveCaso() {
    int nTiradas, valorMax;
    cin >> nTiradas;

    if (nTiradas == -1)
        return false;
    
    cin >> valorMax;

    vector<int> tiradas(nTiradas);
    for (int i = 0; i < tiradas.size(); i++) { cin >> tiradas[i]; }

    vector<int> aux(valorMax);

    for (int i = 0; i < tiradas.size(); i++) {
        aux[tiradas[i] - 1]++;
    }

    vector<int> repeticiones = resolver(tiradas, aux);

    for (int i = repeticiones.size() - 1; i >= 0 ; i--) {
        cout << repeticiones[i];
        if (i > 0) {
            cout << " ";
        }
    }
    cout << "\n";

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