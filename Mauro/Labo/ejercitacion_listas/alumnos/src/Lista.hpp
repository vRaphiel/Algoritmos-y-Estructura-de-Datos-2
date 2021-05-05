#include "Lista.h"

Lista::Lista() {
    _longitud = 0;
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
    Nodo* n = new Nodo();
    n->contenido = elem;

    if (_primero != nullptr) {
        n->siguiente = _primero;
        n->anterior = nullptr;
        _primero->anterior = n;
    }

    _primero = n;
    _longitud += 1;
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
    // Completar
    assert(false);
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    assert(false);
}

void Lista::mostrar(ostream& o) {
    // Completar
}

