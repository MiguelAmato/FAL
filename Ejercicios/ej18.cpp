// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool operator<(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

pair<int, int> particion(vector<pair<string, int>>& v) {
    int ini = 0;
    int fin = v.size() - 1;
    int i = 0;
    pair<string, int> aux;
    while (i <= fin) {
        if (v[i].first == "a") {
            swap(v[i], v[ini]);
            ++i;
            ++ini;
        }
        else if (v[i].first == "r") {
            swap(v[i], v[fin]);
            --fin;
        }
        else {
            ++i;
        }
    }
    return { ini, fin };
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin)
        return false;
    vector<pair<string, int>> v;
    string color;
    int longitud;
    for (int i = 0; i < n; ++i) {
        cin >> color >> longitud;
        v.push_back({ color, longitud });
    }
    pair<int, int> sol = particion(v);
    sort(v.begin(), v.begin() + sol.first);
    sort(v.begin() + sol.first, v.begin() + 1 + sol.second);
    sort(v.begin() + 1 + sol.second, v.end());
    cout << "Azules:";
    for (int i = 0; i < sol.first; ++i) {
        cout << " " << v[i].second;
    }
    cout << "\n";
    cout << "Verdes:";
    for (int i = sol.first; i <= sol.second; ++i) {
        cout << " " << v[i].second;
    }
    cout << "\n";
    cout << "Rojas:";
    for (int i = sol.second + 1; i < v.size(); ++i) {
        cout << " " << v[i].second;
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