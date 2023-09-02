// Nombre del alumno Miguel Amato
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct persona {
    string nombre;
    int altura;
};


bool operator <(persona op1, persona op2) {
    return op1.nombre < op2.nombre;
}

int resolver(vector<persona> & lista, const int & alturaEstablecida) {
    int i = 0;
    int j = lista.size() - 1;
    while (i <= j) { 
        if (lista[i].altura <= alturaEstablecida) i++; 
        else if (lista[j].altura > alturaEstablecida) j--;
        else {
            swap(lista[i], lista[j]);
            i++; j--; 
        }
    }
    return i;
}

bool resuelveCaso() {
    int nPersona;
    cin >> nPersona;

    if (!cin)
        return false;

    int alturaEstablecida;
    cin >> alturaEstablecida;

    vector<persona> lista(nPersona);

    for (int i = 0; i < lista.size(); i++) {
        cin >> lista[i].nombre >> lista[i].altura;
    }

    int pos = resolver(lista, alturaEstablecida);

    sort(lista.begin(), lista.begin() + pos);
    sort(lista.begin() + pos, lista.end());

    int i = 0;
    
    cout << "Bajos:";
    for (int i = 0; i < pos; i++) {
        cout << " " << lista[i].nombre;
    }
    cout << "\n";

    cout << "Altos:";
    for (int i = pos; i < lista.size(); i++) {
        cout << " " << lista[i].nombre;
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