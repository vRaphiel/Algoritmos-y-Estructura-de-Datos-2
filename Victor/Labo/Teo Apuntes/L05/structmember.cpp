#include "structmember.h"
#include <string>

using namespace std;

class Lista{
public:
    void agregar(int v);

    friend ostream* operator<<(ostream& os, const Lista& l){
        l.mostrar(os);
    }
    friend int main(); // Main ahora es amigo
private:
    void mostrar(ostream& os);
    //Definicion de tipo. El struct no es parte de la definicion de lista. Es una declaracion de clase de otro contexto de lista
    // y es privada para la lista. La lista no tiene una variable valor ni siguiente
    // La lista solo tiene una variable primero
    // friendliness -> friendess -> dar permisos a alguien que no sea de la misma clase para acceder a la clase privada
    struct Nodo{
        int valor;
        Nodo* siguiente;

        Nodo(int valor);
    };

    Nodo* primero_;
};

Lista::Nodo::Nodo(int valor) : valor(valor), siguiente(nullptr) {}

void Lista::agregar(int v) {
    primero_ = new Nodo(v);
}

void Lista::mostrar(ostream& os){
    // while
}

struct Nodo{
    int valor;
    Nodo* izq;
    Nodo* der;

    Nodo(int vaor);
};

class Conj{
public:
    void insertar(int v);
private:
    Nodo* primero_;
};

int main(){
    Lista::Nodo x(4);
}
