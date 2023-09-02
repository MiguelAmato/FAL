// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> & a, const vector<int>& b) {
    vector<int> lista;
    int auxA = 0, auxB = 0;
    bool acabar = false;

    while (auxA < a.size() && auxB < b.size()) {
        if (a[auxA] == b[auxB]) {
            lista.push_back(a[auxA]);
            lista.push_back(b[auxB]);
            auxA++;
            auxB++;
        }
        else if (a[auxA] < b[auxB]) {
            lista.push_back(a[auxA]);
            auxA++;
        }
        else {
            lista.push_back(b[auxB]);
            auxB++;
        }
    }

    while (auxA < a.size()) {
        lista.push_back(a[auxA]);
        auxA++;
    }

    while (auxB < b.size()) {
        lista.push_back(b[auxB]);
        auxB++;
    }

    return lista;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int nA, nB;
    cin >> nA >> nB;
    vector<int> a(nA), b(nB), lista;
    for (int i = 0; i < a.size(); i++) { cin >> a[i]; }
    for (int i = 0; i < b.size(); i++) { cin >> b[i]; }

    lista = resolver(a, b);

    for (int i = 0; i < lista.size(); i++) { 
        if (i == lista.size() - 1)
            cout << lista[i] << "\n";
        else 
            cout << lista[i] << " "; 
    }
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