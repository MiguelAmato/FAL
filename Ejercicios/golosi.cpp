// Nombre del alumno Miguel Antonio Amato Hermo y Daniel Perez García
// Usuario del Juez G16

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int maximoValorNutricional(vector<int> const& vC, vector<int> const& vN, int const& umbral) {
    int longAct = 0, valorAct = 0, valorMax = 0, ini = 0;
    for (int i = 0; i < (int)vC.size(); i++) {
        if (longAct + vC[i] <= umbral ) { 
            longAct += vC[i];
            valorAct += vN[i];
            if (valorMax < valorAct) 
                valorMax = valorAct; 
        }
        else {
            valorAct = valorAct - vN[ini];
            longAct = longAct - vC[ini];
            ini++;
            i--;
        }
    }
    return valorMax;
} 

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> vCalorico(n), vNutricional(n);
    for (int i = 0; i < n; i++) { cin >> vCalorico[i]; }
    for (int i = 0; i < n; i++) { cin >> vNutricional[i]; } 
    int umbral;
    cin >> umbral;  
    cout << maximoValorNutricional(vCalorico, vNutricional, umbral) << "\n";
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