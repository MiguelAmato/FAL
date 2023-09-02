#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool esLetraValida(string dni) {
    int numero = stoi(dni.substr(0, dni.size() - 1));
    return dni[dni.size() - 1] == "TRWAGMYFPDXBNJZSQVHLCKE"[numero % 23];
}

void dniValidos (vector<int>& ilegibles, int k, string& dni, int& sol) {
    for (int i = 0; i < 10; i++) {
        dni[ilegibles[k]] = '0' + i;
        if () {
            
        }
        if (k == ilegibles.size() - 1 && esLetraValida(dni)) {
            sol++;
        }
        else if (k < ilegibles.size() - 1) {
            dniValidos(ilegibles, k + 1, dni, sol);
        }
    }
}

void resuelveCaso() {
    string dni;
    cin >> dni;
    vector<int> ilegibles;
    for (int i = 0; i < dni.size(); i++) 
        if (dni[i] == '?') 
            ilegibles.push_back(i);
    int sol = 0;
    dniValidos(ilegibles, 0, dni, sol);
    cout << sol << endl;
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