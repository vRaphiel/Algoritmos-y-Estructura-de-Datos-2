#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> sin_repetidos;

    for (int i = 0; i < s.size(); ++i) {
        bool pertenece = false;
        for (int j = 0; j < sin_repetidos.size(); ++j) {
            if (sin_repetidos[j]== s[i]) {
                pertenece = true;
            }
        }

        if (!pertenece) {
            sin_repetidos.push_back(s[i]);
        }
    }

    return sin_repetidos;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> sin_repetidos;
    set<int> parcial;

    for (int i = 0; i < s.size(); ++i) {
        if (parcial.count(s[i])==0) {
            parcial.insert(s[i]);
            sin_repetidos.push_back(s[i]);
        }
    }

    return sin_repetidos;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> parcial;
    bool iguales = true;

    for (int i = 0; i < a.size(); ++i) {
        parcial.insert(a[i]);
    }

    for (int i = 0; i < b.size(); ++i) {
        if (parcial.count(b[i]) == 0) {
            iguales = false;
        }else {
            parcial.erase(b[i]);
        }
    }

    if (!parcial.empty()) {
        iguales = false;
    }

    return iguales;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> parcial;
    bool iguales = true;

    for (int i = 0; i < a.size(); ++i) {
        parcial.insert(a[i]);
    }

    for (int i = 0; i < b.size(); ++i) {
        if (parcial.count(b[i]) == 0) {
            iguales = false;
        }else {
            parcial.erase(b[i]);
        }
    }

    if (!parcial.empty()) {
        iguales = false;
    }

    return iguales;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> resultado;

    for (int i = 0; i < s.size(); ++i) {
        resultado[s[i]] += 1;
    }

    return resultado;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> repetidos;

    for (int i = 0; i < s.size(); ++i) {
        bool repetido = false;
        for (int j = 0; i < s.size(); ++j) {
            if (s[i] == s[j]) {
                repetido=true;
            }
        }

        if (repetido) {
            repetidos.push_back(s[i]);
        }
    }

    return repetidos;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> interseccion;

    for (int x : a) {
        if (b.count(x) == 1) {
            interseccion.insert(x);
        }
    }

    return interseccion;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> agrupados;

    for (int i = 0; i < s.size(); ++i) {
        int grupo = s[i] % 10;
        agrupados[grupo].insert(s[i]);

    }

    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;

    for (int i = 0; i < str.size(); ++i) {
        char caracter = str[i];
        for (int j = 0; j < tr.size(); ++j) {
            if (tr[j].first == str[i]) {
                caracter = tr[j].second;
            }
        }

        res.push_back(caracter);
    }

    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
