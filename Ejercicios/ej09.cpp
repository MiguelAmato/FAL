// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

using lg = long long int;

vector<int> resolver(const vector<int> & v1, const vector<int>& v2) {
    vector<int> devolver;
    int aux1 = 0, aux2 = 0;
    bool acabar = false;

    while (aux1 < v1.size() && aux2 < v2.size()) {
        if (v1[aux1] == v2[aux2]) {
            devolver.push_back(v1[aux1]);
            aux1++;
            aux2++;
        }
        else if (v1[aux1] < v2[aux2]) {
            aux1++;
        }
        else {
            aux2++;
        }
    }

    return devolver;
}

void resuelveCaso() {
    vector<int> v1, v2;
    int comp1, comp2;

    cin >> comp1;
    while (comp1 != 0) {
        v1.push_back(comp1);
        cin >> comp1;
    }
    sort(v1.begin(), v1.end());

    cin >> comp2;
    while (comp2 != 0) {
        v2.push_back(comp2);
        cin >> comp2;
    }
    sort(v2.begin(), v2.end());

    vector<int> vMostrar = resolver(v1, v2);

    for (int i = 0; i < vMostrar.size(); i++) {
        cout << vMostrar[i];
        if (i < vMostrar.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}