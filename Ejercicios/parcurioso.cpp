// Nombre del alumno 
// Usuario del Juez 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct tSol {
    bool esSol = true;
    int nPares = 0;
    int nImpares = 0;
    int sumaPares = 0;
    int sumaImpares = 0;
};

tSol soln (const vector<int>& v,int ini, int fin) {
    if (ini + 1 == fin) {
        if (v[ini] % 2 == 0)
            return {true, 1, 0, v[ini], 0};
        else 
            return {true, 0, 1, 0, v[ini]};
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        tSol iz = soln(v, ini, mitad + 1);
        tSol dc = soln(v, mitad + 1, fin);
        return {iz.nPares <= dc.nImpares && iz.sumaPares <= dc.sumaImpares && (iz.esSol || dc.esSol), 
                iz.nPares + dc.nPares, 
                iz.nImpares + dc.nImpares,
                iz.sumaPares + dc.sumaPares, 
                iz.sumaImpares + dc.sumaImpares};
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    tSol sol = soln(v, 0, n);
    cout << (sol.esSol ? "SI" : "NO");
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