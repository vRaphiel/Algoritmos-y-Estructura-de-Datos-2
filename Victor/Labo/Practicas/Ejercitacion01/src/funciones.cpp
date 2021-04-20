#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
bool contenido(vector<int> s, int n){
    bool esta = false;
    for(int i : s){
        if(i == n){
            esta = true;
        }
    }
    return esta;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> m;
    for (int i : s) {
        if(!contenido(m, i)){
            m.push_back(i);
        }
    }
    return m;
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
    bool mismos = true;
    set<int> cuales;
    for(int i = 0; i<a.size(); i++){
        cuales.insert(a[i]);
    }
    for(int i = 0; i<b.size(); i++){
        if(cuales.count(b[i]) == 0){
            mismos = false;
        }else{
            cuales.erase(b[i]);
        }
    }

    if(!cuales.empty()){
        mismos = false;
    }

    return mismos;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    bool mismos = true;
    set<int> cuales;
    for(int i = 0; i<a.size(); i++){
            cuales.insert(a[i]);
    }
    for(int i = 0; i<b.size(); i++){
        if(cuales.count(b[i]) == 0){
            mismos = false;
        }else{
            cuales.erase(b[i]);
        }
    }

    if(!cuales.empty()){
        mismos = false;
    }

    return mismos;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> m;
    for(int i = 0; i<s.size(); i++){
        if(m.empty()){
            m.insert(make_pair(s[i], 1));
        }else{
            if(m.count(s[i]) == 0){
                m.insert(make_pair(s[i], 1));
            }else{
                m.find(s[i])->second++;
            }
        }
    }
    return m;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> repetidos;

    for (int i = 0; i < s.size(); i++) {
        bool repetido = false;
        for (int j = 0; j < s.size(); j++) {
            if(i!=j && s[i] == s[j]){
                repetido = true;
            }
        }
        if(!repetido){
            repetidos.push_back(s[i]);
        }

    }

    return repetidos;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> set_a;
    for(int x : a){
        if(b.count(x) == 1){
            set_a.insert(x);
        }
    }
    return set_a;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
