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
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
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
    // Completar
    this->head_ = aCopiar.head_;
    this->tail_ = aCopiar.tail_;
    this->longitud_ = aCopiar.longitud_;
    if(longitud_>0){
        int i = 0;
        while(i < this->longitud_){
            int aiesimo = aCopiar.iesimo(i);
            this->agregarAtras(aiesimo);
            i++;
        }
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {

    Nodo* currentNode = head_->next;

    Nodo* newNode = new Nodo();
    newNode->value = elem;
    newNode->prev = nullptr;
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
    Nodo* nFind = nullptr;

    while(pos < longitud()){
        if(pos == i){
            nFind = nAux;
        }
        nAux = nAux->next;
        pos++;
    }
    return nFind->value;
}

int& Lista::iesimo(Nat i) {
    int pos = 0;
    Nodo* nAux = head_->next;
    Nodo* nFind = nullptr;

    while(pos < longitud()){
        if(pos == i){
            nFind = nAux;
        }
        nAux = nAux->next;
        pos++;
    }
    return nFind->value;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
