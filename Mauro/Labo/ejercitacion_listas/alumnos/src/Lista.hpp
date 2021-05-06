#include "Lista.h"

Lista::Lista() {
    _longitud = 0;
    _primero = new Nodo();
    _ultimo = new Nodo();
    _primero->siguiente = _ultimo;
    _primero->anterior = nullptr;
    _ultimo->siguiente = nullptr;
    _ultimo->anterior = _primero;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
}

Lista& Lista::operator=(const Lista& aCopiar) {
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* currentNode = _primero->siguiente;

    Nodo* newNode = new Nodo();
    newNode->contenido = elem;
    newNode->anterior = _primero;
    _primero->siguiente = newNode;

    currentNode->anterior = newNode;
    newNode->siguiente = currentNode;

    this->_longitud++;

}

void Lista::agregarAtras(const int& elem) {

}

void Lista::eliminar(Nat i) {
    // Completar
}

int Lista::longitud() const {
    return _longitud;
}

const int& Lista::iesimo(Nat i) const {

}

int& Lista::iesimo(Nat i) {

}

void Lista::mostrar(ostream& o) {
    // Completar
}

