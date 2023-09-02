// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void resolver(vector<int> & v) {
    int encuentraImpar = 0, encuentraAcierto = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[encuentraAcierto] % 2 == 0) {
            v[encuentraImpar] = v[encuentraAcierto];
            encuentraAcierto++;
            encuentraImpar++;
        }
        else {
            encuentraAcierto++;
        }
    }

    v.resize(encuentraImpar);
}

void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++) { cin >> v[i]; }

    resolver(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}