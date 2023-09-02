// Nombre del alumno Miguel Antonio Amato Hermo y Daniel Perez Garcia
// Usuario del Juez G16

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct casilla {
    int x;
    int y;
};

vector<casilla> movimientosPosibles(const int& n, int x, int y) { // Muy feo esto, no me gusta
    vector<casilla> sol;
    if (x + 2 < n && y + 1 < n) 
        sol.push_back({ x + 2, y + 1 });
    if (x + 2 < n && y - 1 >= 0) 
        sol.push_back({ x + 2, y - 1 });
    if (x - 2 >= 0 && y + 1 < n) 
        sol.push_back({ x - 2, y + 1 });
    if (x - 2 >= 0 && y - 1 >= 0) 
        sol.push_back({ x - 2, y - 1 });
    if (x + 1 < n && y + 2 < n) 
        sol.push_back({ x + 1, y + 2 });
    if (x + 1 < n && y - 2 >= 0) 
        sol.push_back({ x + 1, y - 2 });
    if (x - 1 >= 0 && y + 2 < n) 
        sol.push_back({ x - 1, y + 2 });
    if (x - 1 >= 0 && y - 2 >= 0) 
        sol.push_back({ x - 1, y - 2 });
    return sol;
}

/*
El arbol de busqueda de solucion seria:
Cada etapa seria el siguiente movimiento del caballo y los hijos de cada etapa los posibles movimientos 
que puede hacer el caballo en esa casilla.
*/

void caballo(vector<vector<bool>>& tablero, const int& n, int x, int y, int& sol) {
    if (x == n-1 && y == n-1) // Si hemos llegado al final
        sol++; 
    else {
        vector<casilla> movimientos = movimientosPosibles(n, x, y); // Sacamos todos los posibles nodos a los que podemos ir
        for (int i = 0; i < (int)movimientos.size(); ++i) { // Los hijos del arbol son los posibles movimientos
            if (!tablero[movimientos[i].x][movimientos[i].y]) { // Si no esta marcada la casilla
                tablero[movimientos[i].x][movimientos[i].y] = true; // Marcas
                caballo(tablero, n, movimientos[i].x, movimientos[i].y, sol);
                tablero[movimientos[i].x][movimientos[i].y] = false; // Desmarcas
            }
        }
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0)
        return false;
    int x, y;
    cin >> x >> y;
    vector<vector<bool>> tablero(n, vector<bool>(n, false));
    tablero[x][y] = true; // Marcamos la casilla inicial del caballo
    int sol = 0;
    caballo(tablero, n, x, y, sol);
    cout << sol << "\n";
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
