
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() {
    /*
    _treeList.clear();
    destruir(_raiz);
     */
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    /*
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
     */
    return perteneceAux(_raiz, clave);
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(_raiz == nullptr){
        _raiz = new Nodo(clave);
        _raiz->izq = nullptr;
        _raiz->der = nullptr;
        _quantity++;
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
        _raiz = nullptr;
        _quantity--;
    }else{
        if(valor > _raiz->valor){
            borradoAux(_raiz, _raiz->der, valor);
        }else{
            borradoAux(_raiz, _raiz->izq, valor);
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    /*
    ordenarLista();
    for(int i = 0; i<_treeList.size(); i++){
        if(_treeList[i] == clave){
            return _treeList[i+1];
        }
    }
    return clave;
     */
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
    return _quantity;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

/** *
 * AUXILIAR FUNCTIONS
 * **/

template<class T>
int Conjunto<T>::cardinalAux(Nodo* padre) const{
    if(padre == nullptr){
        return 0;
    }else{
        if(padre->izq == nullptr && padre->der == nullptr){
            return 1;
        }else{
            return 1 + cardinalAux(padre->izq) + cardinalAux(padre->der);
        }
    }
}

template<class T>
void Conjunto<T>::insertarAux(Nodo*& subarbol, const T& value){
    if(subarbol == nullptr){
        Nodo* nodo = new Nodo(value);
        subarbol == nodo;
        _quantity++;
    }else{
        if(value > subarbol->valor){
            if(subarbol->der == nullptr){
                Nodo* nodo = new Nodo(value);
                subarbol->der = nodo;
                _quantity++;
            }else{
                insertarAux(subarbol->der, value);
            }
        }else if(value < subarbol->valor){
            if(subarbol->izq == nullptr){
                Nodo* nodo = new Nodo(value);
                subarbol->izq = nodo;
                _quantity++;
            }else{
                insertarAux(subarbol->izq, value);
            }
        }
    }

}

template<class T>
bool Conjunto<T>::perteneceAux(Nodo* padre, const T& valor) const {
    if(padre == nullptr){
        return false;
    }else{
        if(padre->valor == valor){
            return true;
        }else{
            return perteneceAux(padre->izq, valor) || perteneceAux(padre->der, valor);
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
                    _quantity--;
                    padre->izq = nullptr;
                }else{
                    _quantity--;
                    padre->der = nullptr;
                }
                delete hijo;
                _quantity--;
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
                    _quantity--;
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
                    _quantity--;
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

/*
template<class T>
void Conjunto<T>::insertarOrdenado()

template<class T>
void Conjunto<T>::swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}


template<class T>
void Conjunto<T>::ordenarLista(){
    T i, j;
    for (i = 0; i < _treeList.size()-1; i++)

        // Last i elements are already in place
        for (j = 0; j < _treeList.size()-1; j++)
            if (_treeList[j] > _treeList[j+1])
                swap(&_treeList[j], &_treeList[j+1]);
}
 */