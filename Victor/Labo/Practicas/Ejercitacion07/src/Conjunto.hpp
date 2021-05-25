
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    if(_raiz != nullptr){
        if(_raiz->valor == clave){
            return true;
        }else{
            return perteneceAux(_raiz->izq, clave) || perteneceAux(_raiz->der, clave);
        }
    }
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    _listaEnOrden.push_back(clave);
    if(_raiz == nullptr){
        _raiz = new Nodo(clave);
    }else{
        if(clave > _raiz->valor){
            insertarAux(_raiz->der, clave);
        }else{
            insertarAux(_raiz->izq, clave);
        }
    }
    insertarAux(_raiz, clave);
}

template <class T>
void Conjunto<T>::remover(const T& valor) {
    if(_raiz != nullptr){
        if(_raiz->valor == valor){
            _raiz = nullptr;
        }else{
            if(valor > _raiz->valor){
                borradoAux(_raiz, _raiz->der, valor);
            }else{
                borradoAux(_raiz, _raiz->izq, valor);
            }
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    ordenarLista();
    for(int i = 0; i<_listaEnOrden.size(); i++){
        if(_listaEnOrden[i] == clave){
            return _listaEnOrden[i+1];
        }
    }
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
    return cardinalAux(_raiz);
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
void Conjunto<T>::insertarAux(Nodo* subarbol, const T& value){
    if(subarbol == nullptr){
        subarbol == new Nodo(value);
    }else{
        if(value > subarbol->valor){
            if(subarbol->der == nullptr){
                subarbol->der = new Nodo(value);
            }else{
                insertarAux(subarbol->der, value);
            }
        }else if(value < subarbol->valor){
            if(subarbol->izq == nullptr){
                subarbol->izq = new Nodo(value);
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
void Conjunto<T>::swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

template<class T>
void Conjunto<T>::ordenarLista(){
    T i, j;
    for (i = 0; i < _listaEnOrden.size()-1; i++)

        // Last i elements are already in place
        for (j = 0; j < _listaEnOrden.size()-1; j++)
            if (_listaEnOrden[j] > _listaEnOrden[j+1])
                swap(&_listaEnOrden[j], &_listaEnOrden[j+1]);
}