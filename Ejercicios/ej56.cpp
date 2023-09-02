// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct tPiezasTotales {
    int piezasAtotales;
    int piezasRtotales;
    int piezasVtotales;
};

struct tPiezasUsadas {
    int piezasA;
    int piezasR;
    int piezasV;
};

void mostrarSolucion(vector<int>& sol) {
    string color;
    for (int i = 0; i < sol.size(); i++) {
        switch (sol[i]) {
        case 0: color = "azul"; break;
        case 1: color = "rojo"; break;
        case 2: color = "verde"; break;
        }
        cout << color << " ";
    }
    cout << "\n";
}

bool esValida(const vector<int>& sol, int k, tPiezasUsadas& tpu, tPiezasTotales& tpt) {
    return !(sol[k] == 2 && sol[k] == sol[k - 1]) &&
        ((tpt.piezasVtotales - tpu.piezasV) < (tpt.piezasAtotales - tpu.piezasA)); // && (tpu.piezasA > 0) && (tpu.piezasV > 0) && (tpu.piezasR > 0);
}

bool esSolucion(const vector<int>& sol, int k, int n, tPiezasTotales& tpt, tPiezasUsadas& tpu) {
    return ((tpt.piezasAtotales - tpu.piezasA) + (tpt.piezasVtotales - tpu.piezasV) < (tpt.piezasRtotales - tpu.piezasR)) ;
}

void resuelve(int n, int k, vector<int> &sol, tPiezasTotales& tpt, tPiezasUsadas& tpu) {
    for (int i = 0; i < 3; i++) {

        sol[k] = i;

        switch (i) {
        case 0: tpu.piezasA--; break;
        case 1: tpu.piezasR--; break;
        case 2: tpu.piezasV--; break;
        }

        if (esValida(sol, k, tpu, tpt)) {
            if (k == n - 1) {
                if (esSolucion(sol, k, n, tpt, tpu)) {
                    mostrarSolucion(sol);
                }
            }
            else {
                resuelve(n, k + 1, sol, tpt, tpu);
            }
        }

        switch (i) {
        case 0: tpu.piezasA++; break;
        case 1: tpu.piezasR++; break;
        case 2: tpu.piezasV++; break;
        }
    }
}

bool resuelveCaso() {
    int h, a, r, v;
    cin >> h >> a >> r >> v;
    if (h == 0 && a == 0 && r == 0 && v == 0)
        return false;
    tPiezasTotales tpt { a, r, v };
    tPiezasUsadas tpu { a, r, v };
    vector<int> sol(h);
    sol[0] = 1;
    tpu.piezasR--;
    if (h == 1) {
        mostrarSolucion(sol);
    }
    else {
        resuelve(h, 1, sol, tpt, tpu);
    }

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