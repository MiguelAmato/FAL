// Nombre del alumno Miguel Amato
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using lg = long long int;

void resolver(vector<lg> & v, lg error, lg & cont) {
    int encuentraError = 0, encuentraAcierto = 0;
    bool seguir = true;

    for (int i = 0; i < v.size(); i++) {
        if (v[encuentraAcierto] != error) {
            v[encuentraError] = v[encuentraAcierto];
            encuentraAcierto++;
            encuentraError++;
            cont++;
        }
        else {
            encuentraAcierto++;
        }
    }

    v.resize(encuentraError);

}

void resuelveCaso() {
    lg medidas, error, cont = 0;
    cin >> medidas >> error;

    vector<lg> v(medidas);

    for (int i = 0; i < v.size(); i++) { 
        cin >> v[i]; 
    }

    resolver(v, error, cont);

    cout << cont << "\n";

    for (int i = 0;  i < v.size() ; i++) {
        cout << v[i];
        if (i < v.size() - 1) {
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