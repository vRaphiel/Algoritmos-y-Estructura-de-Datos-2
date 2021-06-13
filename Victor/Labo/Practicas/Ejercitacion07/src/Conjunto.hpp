
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() {
    destruir(_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    return perteneceAux(_raiz, clave);
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    insertarAux(this->_raiz, clave);
}

template <class T>
void Conjunto<T>::remover(const T& valor) {
    removerAux(_raiz, valor);
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    return encontrarSucc(clave);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* nodo = _raiz;
    while(nodo->izq != nullptr){
        nodo = nodo->izq;
    }
    return nodo->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* nodo = _raiz;
    while(nodo->der != nullptr){
        nodo = nodo->der;
    }
    return nodo->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return cardinalAux(_raiz);
    //return _quantity;
}

template<class T>
const T& Conjunto<T>::getRaiz() const {
    return _raiz->valor;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {

}

/* AUXILIAR FUNCTIONS */
template<class T>
void Conjunto<T>::insertarAux(Nodo* &root, const T& clave) {
    if(root == nullptr){
        root = new Nodo(clave);
    } else {
        if(clave == root->valor){

        }
        if(clave > root->valor){
            insertarAux(root->der, clave);
        }else if(clave < root->valor) {
            insertarAux(root->izq, clave);
        }
    }
}

template<class T>
bool Conjunto<T>::perteneceAux(Nodo* root, const T& clave) const{
    if(root == nullptr){
        return false;
    }else{
        if(root->valor == clave){
            return true;
        }else{
            if(clave > root->valor){
                return perteneceAux(root->der, clave);
            }else{
                return perteneceAux(root->izq, clave);
            }
        }
    }
}

template<class T>
void Conjunto<T>::removerAux(Nodo* &root, const T& valor) {
    if(root != nullptr){
        if(root->valor == valor){

            if(root->izq == nullptr && root->der == nullptr){
                Nodo* nodo = nullptr;
                delete root;
                root = nodo;
            }else if(root->izq == nullptr || root->der == nullptr){
                if(root->izq == nullptr){
                    Nodo* nodo = root->der;
                    delete root;
                    root = nodo;
                } else {
                    Nodo* nodo = root->izq;
                    delete root;
                    root = nodo;
                }
            }else{
                Nodo* pI = root->der;
                while(pI->izq != nullptr){
                    pI = pI->izq;
                }
                T pIValue = pI->valor;
                removerAux(root, pIValue);
                root->valor = pIValue;
            }
        }else{
           if(valor > root->valor){
               removerAux(root->der, valor);
           } else if(valor < root->valor){
               removerAux(root->izq, valor);
           }
        }
    }
}


template<class T>
const T& Conjunto<T>::encontrarSucc(const T& valor) const{
    Nodo* miNodoV = _raiz;
    Nodo* padreDeMiNodo = _raiz;
    while(miNodoV->valor != valor){
        padreDeMiNodo = miNodoV;
        if(valor > miNodoV->valor){
            miNodoV = miNodoV->der;
        }else{
            miNodoV = miNodoV->izq;
        }
    }

    if(miNodoV->der != nullptr){
        Nodo* minimo = miNodoV->der;
        while(minimo->izq != nullptr){
            minimo = minimo->izq;
        }
        return minimo->valor;
    }

    if(miNodoV->der == nullptr){
        if(padreDeMiNodo->der == nullptr){
            return padreDeMiNodo->valor;
        }else{
            Nodo* minimo = padreDeMiNodo->der;
            while(minimo->izq != nullptr){
                minimo = minimo->izq;
            }
            if(padreDeMiNodo->valor < minimo->valor){
                return padreDeMiNodo->valor;
            }else{
                return minimo->valor;
            }
        }
    }
    return _raiz->valor;
}

template<class T>
void Conjunto<T>::destruir(Nodo* &n){
    if(n != nullptr){
        if(n->izq != nullptr){
            destruir(n->izq);
        }
        if(n->der != nullptr){
            destruir(n->der);
        }
        delete n;
    }
}

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