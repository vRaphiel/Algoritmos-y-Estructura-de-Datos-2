
#include "string_map.h"

template <typename T>
string_map<T>::string_map(){
    _raiz = nullptr;
    _claves = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() {
    *this = aCopiar;
} // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    destruirNodos(this->_raiz);
    if(d._raiz != nullptr){
        agregarSubNodos(this->_raiz, d._raiz);
    }
    this->_claves = d._claves;
    return *this;
}
// Asignar a raiz un nodo si d._raiz no es null
// Cuando haces el operador =. La post condicion es que el dicc quede igual al recibido por parametro
// Previo: Destruir todos los nodos de mi dicc actual
template<typename T>
void string_map<T>::agregarSubNodos(Nodo*& actual, const Nodo* copia) {

    if(copia != nullptr){
        if(actual == nullptr){
            Nodo* nodo = new Nodo();
            actual = nodo;
        }
        if(copia->definicion != nullptr){
            T* t = new T(*copia->definicion);
            actual->definicion = t;
        }
        int indice = 0;
        while(indice < copia->siguientes.size()){
            if(copia->siguientes[indice] != nullptr){
                agregarSubNodos(actual->siguientes[indice], copia->siguientes[indice]);
            }
            indice++;
        }
    }
}

template <typename T>
string_map<T>::~string_map(){
    if(_raiz != nullptr) {
        int indice = 0;
        while(indice < _raiz->siguientes.size()){
            if(_raiz->siguientes[indice] != nullptr){
                destruirNodos(_raiz->siguientes[indice]);
            }
            indice++;
        }
        if(_raiz->definicion != nullptr ){
            delete _raiz->definicion;
        }
        _raiz->siguientes.clear();
        delete _raiz;
        _claves = 0;
    }else{
        delete _raiz;
        _claves = 0;
    }
}

template<typename T>
void string_map<T>::destruirNodos(Nodo*& nodo){
    int indice = 0;
    if(nodo != nullptr){
        while(indice < nodo->siguientes.size()){
            if(nodo->siguientes[indice] != nullptr){
                destruirNodos(nodo->siguientes[indice]);
            }
            indice++;
        }
        if(nodo->definicion!= nullptr){
            delete nodo->definicion;
            nodo->definicion = nullptr;
            this->_claves--;
        }
        delete nodo;
        nodo = nullptr;
    }
}

template<typename T>
void string_map<T>::insert(const pair<string, T>& value) {
    insertAux(_raiz, value, 0);
}

template <typename T>
T& string_map<T>::operator[](const string& clave) {
    assert(false);
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    if(_raiz != nullptr) {
        if (clave.size() > 0) {
            Nodo *actual = _raiz;
            int indice = 0;
            int ASCIIcode = clave[indice];

            while (actual != nullptr && indice < clave.size()) {
                if (actual->siguientes[ASCIIcode] != nullptr) {
                    actual = actual->siguientes[ASCIIcode];
                    indice++;
                    ASCIIcode = clave[indice];
                } else {
                    return 0;
                };
            }
            if (indice == clave.size() && actual->definicion != nullptr) {
                return 1;
            }
        }
    }
    return 0;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    if(clave.size() > 0){
        Nodo* actual = _raiz;
        int indice = 0;
        int ASCIIcode = clave[indice];

        while(actual != nullptr || indice < clave.size()){
            if(actual->siguientes[ASCIIcode] != nullptr){
                actual = actual->siguientes[ASCIIcode];
                indice++;
                ASCIIcode = clave[indice];
            }else{
                return nullptr;
            };
        }
        if(indice == clave.size() && actual->definicion){
            return 1;
        }
    }
    return nullptr;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = _raiz;
    int indice = 0;
    int ASCIIcode = clave[indice];

    while(indice < clave.size()){
        if(actual->siguientes[ASCIIcode] != nullptr){
            actual = actual->siguientes[ASCIIcode];
            indice++;
            ASCIIcode = clave[indice];
        }
    }
    return *actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    eraseAux(this->_raiz, this->_raiz, clave, 0, (int) clave[0]);
}

template <typename T>
int string_map<T>::size() const{
    return _claves;
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
    if(index == definition.first.size()) {
        // Nodos nulos
        if(root == nullptr){
            root = new Nodo(new T(definition.second));
            _claves++;
        } else {
        // Nodos no nulos
            if(root->definicion != nullptr){
                delete root->definicion;
                root->definicion = new T(definition.second);
            }else{
                root->definicion = new T(definition.second);
            }
            _claves++;
        }
    }else{
        int ASCIIcode = definition.first[index];
        // Si el nodo es nulo, creo uno nuevo
        if(root == nullptr){
            root = new Nodo();
        }
        insertAux(root->siguientes[ASCIIcode], definition, index+1);
    }
}

template<typename T>
void string_map<T>::eraseAux(Nodo*& root, Nodo*& buscado, const string& clave, int index, int deleteASCII){
    //destruirNodos(this->_raiz);

    bool hayUno = false;
    int ASCIIcode = clave[index];
    if(index == clave.size()){
        for(int i = 0; i < buscado->siguientes.size(); i++){
            if(buscado->siguientes[i] != nullptr){
                hayUno = true;
            }
        }
        if(hayUno){
            delete buscado->definicion;
            buscado->definicion = nullptr;
            _claves--;
        }else{
            destruirNodos(root);
        }
    }else{
        if(buscado->definicion != nullptr){
            hayUno = true;
        }
        int i = 0;
        while(i < buscado->siguientes.size() && !hayUno){
            if(buscado->siguientes[i] != nullptr && i != ASCIIcode){
                hayUno = true;
            }
            i++;
        }
        if(hayUno){
            eraseAux(buscado->siguientes[ASCIIcode], buscado->siguientes[ASCIIcode], clave, index + 1, ASCIIcode);
        }else{
            eraseAux(root, buscado->siguientes[ASCIIcode], clave, index + 1, deleteASCII);
        }
    }

}