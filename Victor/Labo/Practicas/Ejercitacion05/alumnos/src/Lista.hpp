#include "Lista.h"

Lista::Lista() {
    longitud_ = 0;
    head_ = new Nodo();
    tail_ = new Nodo();
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

    Nodo* newNode = new Nodo();
    newNode->value = elem;
    newNode->prev = head_;
    head_->next = newNode;

    currentNode->prev = newNode;
    newNode->next = currentNode;

    this->longitud_++;

}

void Lista::agregarAtras(const int& elem) {
    Nodo* currentNode = tail_->prev;

    Nodo* newNode = new Nodo();
    newNode->value = elem;

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

    while(pos < longitud()){
        if(pos == i){
            return nAux->value;
        }
        nAux = nAux->next;
        pos++;
    }
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

void Lista::mostrar(ostream& o) {
    // Completar
}
