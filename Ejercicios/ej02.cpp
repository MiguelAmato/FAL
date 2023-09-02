// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool resolver(const vector<int> & v, int pos) {
    int max = v[0];

    for (int i = 1; i <= pos; i++) {
        if (v[i] > max)
            max = v[i];
    }

    int j = pos + 1;
    bool encontrado = false;

    while (!encontrado && j < v.size()) {
        if (v[j] <= max) 
            encontrado = true;
        j++;
    }

    return encontrado;
}

void resuelveCaso() {
    int nElementos, pos;
    cin >> nElementos >> pos;
    vector <int> v(nElementos);

    for (int i = 0; i < v.size(); i++) 
        cin >> v[i];

    if (!resolver(v, pos)) 
        cout << "SI\n";
    else 
        cout << "NO\n";
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
