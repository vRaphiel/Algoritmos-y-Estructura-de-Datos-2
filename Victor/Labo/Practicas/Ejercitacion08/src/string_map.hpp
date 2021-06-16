
#include "string_map.h"

template <typename T>
string_map<T>::string_map(){
    _raiz = nullptr;
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    assert(false);
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template<typename T>
void string_map<T>::insert(const pair<string, T> & value) {
    insertAux(_raiz, value, 0);
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    assert(false);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    if(clave.size() > 0){
        Nodo* actual = _raiz;
        int indice = 0;
        char leter = clave[indice];

        while(actual != nullptr){
            if(actual->siguientes[(int) leter] != nullptr){
                actual = actual->siguientes[(int) leter];
                indice++;
                leter = clave[indice];
            }else{
                return false;
            };
        }
        if(indice == clave.size() - 1 && actual->definicion){
            return 1;
        }
    }
    return 0;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    assert(false);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    assert(false);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    assert(false);
}

template <typename T>
int string_map<T>::size() const{
    assert(false);
}

template <typename T>
bool string_map<T>::empty() const{
    if(_raiz == nullptr){
        return true;
    }
    return false;
}

template<typename T>
void string_map<T>::insertAux(Nodo*& root, const pair<string, T>& definition, int index) {
    if(index == definition.first.size() - 1) {
        // Nodos nulos
        if(root == nullptr){
            Nodo* nodo = new Nodo();
            root = nodo;
            T data = definition.second;
            root->definicion = definition.second;
        } else {
        // Nodos no nulos
            root->definicion = definition.second;
        }
    }else{
        int ASCIIcode = definition.first[index];
        // Si el nodo es nulo, creo uno nuevo
        if(root == nullptr){
            Nodo* nodo = new Nodo();
            root = nodo;
        }
        insertAux(root->siguientes[ASCIIcode], definition, index+1);
    }
}