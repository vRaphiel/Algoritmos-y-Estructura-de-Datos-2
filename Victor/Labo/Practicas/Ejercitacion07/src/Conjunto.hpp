
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() {
    _treeList.clear();
    destruir(_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    bool esta = false;
    if(_treeList.size() > 0){
        for(int i = 0; i <_treeList.size(); i++){
            Nodo* nodo = _treeList[i];
            if(nodo->valor == clave){
                esta = true;
            }
        }
    }
    return esta;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(_raiz == nullptr){
        Nodo* nodo = new Nodo(clave);
        _raiz = nodo;
        _treeList.push_back(nodo);
    }else{
        if(clave > _raiz->valor){
            insertarAux(_raiz->der, clave);
        }else{
            insertarAux(_raiz->izq, clave);
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& valor) {
    if(_raiz->valor == valor){

    }

};

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    return clave;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    return sucesorInmediato(_raiz);
}

template <class T>
const T& Conjunto<T>::maximo() const {
    return precedesorInmediato(_raiz);
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _treeList.size();
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

/** *
 * AUXILIAR FUNCTIONS
 * **/
template<class T>
void Conjunto<T>::insertarAux(Nodo*& subarbol, const T& value){
    if(subarbol == nullptr){
        Nodo* node = new Nodo(value);
        subarbol = node;
        _treeList.push_back(node);
    }else{
        if(value > subarbol->valor){
            insertarAux(subarbol->der, value);
        }else if(value < subarbol->valor){
            insertarAux(subarbol->izq, value);
        }
    }
}

template<class T>
void Conjunto<T>::borradoAux(Nodo* padre, Nodo* hijo, const T& valor) {
    if(hijo != nullptr){
        if(hijo->valor == valor){
            if(hijo->izq == nullptr && hijo->der == nullptr){
                // Caso donde no hay hijos
                if(padre->izq == hijo){
                    padre->izq = nullptr;
                }else{
                    padre->der = nullptr;
                }
                delete hijo;
            }else if(hijo->izq == nullptr || hijo->der == nullptr){
                // Caso donde hay al menos un hijo
                if(hijo->izq == nullptr){
                    // Opero con padre derecha pues se que izquierda es null
                    Nodo* junior = hijo->der;
                    if(hijo == padre->der){
                        // Caso hijo es derecha
                        padre->der = junior;
                    }else{
                        // Caso hijo es izquierda
                        padre->izq = junior;
                    }
                    delete hijo;
                }else{
                    Nodo* junior = hijo->izq;
                    // Opero con padre izquierda pues se que derecha es null
                    if(hijo == padre->der){
                        // Caso hijo es derecha
                        padre->der = junior;
                    }else{
                        // Caso hijo es izquierda
                        padre->izq = junior;
                    }
                    delete hijo;
                }
            }else{
                // Borro mi V
                const T pI = precedesorInmediato(hijo->izq);
                borradoAux(hijo, hijo->izq, pI);
                hijo->valor = pI;
            }
        }else{
            if(valor > hijo->valor){
                borradoAux(hijo, hijo->der, valor);
            }else{
                borradoAux(hijo, hijo->izq, valor);
            }
        }
    }
}

template<class T>
const T& Conjunto<T>::precedesorInmediato(Nodo* padre) const {
    if(padre->der != NULL){
        return precedesorInmediato(padre->der);
    }else{
        return padre->valor;
    }
}

template<class T>
const T& Conjunto<T>::sucesorInmediato(Nodo* padre) const {
    if(padre->izq != NULL){
        return sucesorInmediato(padre->izq);
    }else{
        return padre->valor;
    }
}

template<class T>
void Conjunto<T>::destruir(Nodo* n) {
    if(n != nullptr){
        destruir(n->izq);
        destruir(n->der);
        delete n;
    }
}