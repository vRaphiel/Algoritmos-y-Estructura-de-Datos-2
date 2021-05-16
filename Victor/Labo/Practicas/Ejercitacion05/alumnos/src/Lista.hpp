#include "Lista.h"

Lista::Nodo::Nodo(int valor) {
    this->value = valor;
    this->next = nullptr;
    this->prev = nullptr;
}

Lista::Lista() {
    longitud_ = 0;
    head_ = new Nodo(0);
    tail_ = new Nodo(0);
    head_->next = tail_;
    head_->prev = nullptr;
    tail_->next = nullptr;
    tail_->prev = head_;
}

Lista::Lista(const Lista& l) : Lista() {
    *this = l;
}

Lista::~Lista() {
    while(head_->next != tail_){
        eliminar(0);
    }
    delete head_;
    delete tail_;
}

Lista& Lista::operator=(const Lista& aCopiar) {

    while(head_->next != tail_){
        eliminar(0);
    }
    head_->next = tail_;
    tail_->prev = head_;

    Nodo* nodo = aCopiar.head_->next;

    while(nodo != aCopiar.tail_){
        this->agregarAtras(nodo->value);
        nodo = nodo->next;
    }

    return *this;
}

void Lista::agregarAdelante(const int& elem) {

    Nodo* currentNode = head_->next;

    Nodo* newNode = new Nodo(elem);
    newNode->prev = head_;
    head_->next = newNode;

    currentNode->prev = newNode;
    newNode->next = currentNode;

    this->longitud_++;

}

void Lista::agregarAtras(const int& elem) {
    Nodo* currentNode = tail_->prev;

    Nodo* newNode = new Nodo(elem);

    tail_->prev = newNode;
    currentNode->next = newNode;
    newNode->next = tail_;
    newNode->prev = currentNode;

    this->longitud_++;
}

void Lista::eliminar(Nat i) {
    int pos = 0;
    Nodo* nAux = head_->next;
    while(pos < longitud()){
        if( pos == i ){
            Nodo* nPrev = nAux->prev;
            Nodo* nNext = nAux->next;
            nPrev->next = nNext;
            nNext->prev = nPrev;
            delete nAux;
            this->longitud_--;
            pos = longitud();
        }else{
            nAux = nAux->next;
        }
        pos++;
    }

}

int Lista::longitud() const {
    return longitud_;
}

const int& Lista::iesimo(Nat i) const {
    int pos = 0;
    Nodo* nAux = head_->next;
    Nodo* nReturn = new Nodo(0);
    while(pos < longitud()){
        if(pos == i){
            nReturn = nAux;
        }
        nAux = nAux->next;
        pos++;
    }
    return nReturn->value;
}

int& Lista::iesimo(Nat i) {
    int pos = 0;
    Nodo* nAux = head_->next;
    while(pos < longitud()){
        if(pos == i){
            return nAux->value;
        }
        nAux = nAux->next;
        pos++;
    }
}


/* No entendi bien cuando expresaba [a_0, a_1, a_2, ...]
 * si a era la posicion del nodo y el 0, 1, ... eran los valores
 * Considere a como la posicion del nodo y seguido al  _ el valor en ese nodo
 * */
void Lista::mostrar(ostream& o) {
    o << "[";
    Nodo* nodo = head_->next;
    int i = 0;
    while(nodo != tail_){
        o << i << "_" << nodo->value << ", ";
        i++;
        nodo = nodo->next;
    }
    o << "]";
}
