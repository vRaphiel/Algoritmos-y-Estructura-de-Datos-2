#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Item para Vector o Secuencia
pair<vector<int>, vector<int>> pares_e_impares(vector<int> s){
    vector<int> pares;
    vector<int> impares;
    for(int i = 0; i<s.size(); i++){
        if(s[i] % 2 == 0){
            pares.push_back(s[i]);
        }else{
            impares.push_back(s[i]);
        }
    }
    return pair<vector<int>, vector<int>>(pares, impares);
}

// Item para conjuntos
vector<int> interseccion(vector<int> a, vector<int> b){
    set<int> set_a;
    for(int i = 0; i < a.size(); i++){
        set_a.insert(a[i]);
    }
    vector<int> res;
    for(int i = 0; i<b.size(); i++){
        if(set_a.count(b[i]) == 1){
            res.push_back(b[i]);
        }
    }
    return res;
}

// Item para diccionario
