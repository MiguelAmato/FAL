// Nombre del alumno Miguel Antonio Amato Hermo 
// Usuario del Juez A01


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void mostrarSol(vector<char>& sol) {
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i];
    }
    cout << "\n";
}

void resolver(int m, int n, int k, vector<char>& sol, vector<bool>& marcas) {
    for (char i = 'a'; i < 'a' + m; i++) {
        sol[k] = i;
        if (!marcas[i - 'a']) {
            marcas[i - 'a'] = true;
            if (k == n - 1) {
                mostrarSol(sol);
            }
            else {
                resolver(m, n, k + 1, sol, marcas);
            }
            marcas[i - 'a'] = false;
        }
    }
}

bool resuelveCaso() {
    int m, n;
    cin >> m >> n;
    if (!cin)
        return false;
    vector<char> sol(n);
    vector<bool> marcas(26);
    resolver(m, n, 0, sol, marcas);
    cout << "\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso());

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}