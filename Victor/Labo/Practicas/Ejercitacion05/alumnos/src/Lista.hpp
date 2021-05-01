#include "Lista.h"

Lista::Lista() {
    longitud_(0);
    header_ = new Nodo;
    trailer_ = new Nodo;
    header_->next = trailer;
    trailer_->prev = header;
    header_->prev = nullptr;
    trailer_->next = nullptr;
}



Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista
    longitud_(0);
    Lista = l;
}

Lista::~Lista() {

}

Lista& Lista::operator=(const Lista& aCopiar) {

    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
}

void Lista::agregarAtras(const int& elem) {
    // Completar
}

void Lista::eliminar(Nat i) {
    // Completar
}

int Lista::longitud() const {
    // Completar
    return -1;
}

const int& Lista::iesimo(Nat i) const {
    int j = 0;
    Nodo nodoBuscado = header_->next;
    while(j < i){
        nodoBuscado = nodoBuscado.next;
        j++;
    }
    return nodoBuscado;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    assert(false);
}

void Lista::mostrar(ostream& o) {
    // Completar
}
