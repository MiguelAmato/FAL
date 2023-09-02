// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez G16

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int bb (const vector<int>& v, const vector<int>& p, int ini, int fin, int cont, const int& n) {
    if (ini + 1 == fin) 
        return v[ini];
    else if (cont == p.size()) 
        return -1;
    else {
        if (n < p[cont]) return bb(v,p,ini,p[cont], cont + 1, n);
        else return bb(v,p,p[cont],fin, cont + 1, n);
    }
}

bool resuelveCaso() {
    int ini, fin, n;
    cin >> ini >> fin >> n;
    if (ini == 0 && fin == 0 & n == 0)
        return false;
    vector<int>v;
    for (int i = ini; i <= fin; ++i) v.push_back(i);
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; ++i) cin >> p[i];
    int sol = bb(v,p,0,v.size(),0,n);
    cout << (sol -1 == n ? "LO SABE" : "NO LO SABE") << "\n";
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
