// Nombre Miguel Antonio Amato Hermo
// Usuario del juez A01

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std; 

struct tDatos {
    string id;
    int altura;
    int piso;
};

vector<string> resolver(std::vector<tDatos> const& edificios) {
    vector<string> nombres;
    int maxAltura = edificios[edificios.size() - 1].altura;
    if (edificios[edificios.size() - 1].piso >= 0) {
        nombres.push_back(edificios[edificios.size() - 1].id);
    }
    for (int i = edificios.size() - 2; i >= 0; --i) {
        if (edificios[i].piso >= 0) {
            if (edificios[i].piso > maxAltura) {
                nombres.push_back(edificios[i].id);
            }
        }
        if (edificios[i].altura > maxAltura) {
            maxAltura = edificios[i].altura;
        }
    }
    return nombres;
}

bool resuelveCaso() {
    int numEdificios;
    cin >> numEdificios;
    if (numEdificios == 0) return false;

    vector<tDatos> edificios(numEdificios);
    for (int i = 0; i < numEdificios; ++i) {
        std::cin >> edificios[i].id >> edificios[i].altura >> edificios[i].piso;
    }
    vector<string> v = resolver(edificios);
    if (v.size() > 0) {
        std::cout << v.size() << '\n';
        std::cout << v[0];
        for (int i = 1; i < v.size(); ++i)
            std::cout << ' ' << v[i];
        std::cout << '\n';
    }
    else std::cout << "Ninguno\n";
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
