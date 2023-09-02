// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
int resolver(const vector<int> & v, long long int& suma) {
    int min, nMin = 1, cont = v.size();
    min = v[0];
    suma = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < min) {
            min = v[i];
            nMin = 1;
        }
        else if (v[i] == min) {
            nMin++;
        }
        suma += v[i];
    }
    suma = suma - (min * nMin);
    cont = cont - nMin;
    return cont;
}

void resuelveCaso() {
    int numVectores;
    cin >> numVectores;
    vector <int> v(numVectores);
    for (int i = 0; i < numVectores; i++) {
        cin >> v[i];
    }
    long long int suma = 0;
    int cont = resolver(v, suma);
    cout << suma << " " << cont << "\n";
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