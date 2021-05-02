#include <iostream>
#include <cstdlib>
using namespace std;

class Lista{
public:
    Lista();
    ~Lista();
    void agregar(const int& x);
    void sacarPrimero();
    void _destruir();

private:

    struct Nodo{
        Nodo(const int& elem);
        int valor;
        Nodo* siguiente;
    };

    Nodo* _primero;
};

Lista::Lista(){
    _primero = NULL;
}

Lista::~Lista(){
    _destruir();
}

void Lista::_destruir(){
    while(_primero != NULL){
        sacarPrimero();
    }
}

void Lista::sacarPrimero(){
    Nodo* p = _primero;
    _primero = _primero->siguiente;
    delete p;
}

void Lista::agregar(const int& x){
    Nodo* nuevo = new Nodo(x);
    nuevo->siguiente = _primero;
    _primero = nuevo;
}

Lista::Nodo::Nodo(const int& elem):valor(elem), siguiente(NULL) {}