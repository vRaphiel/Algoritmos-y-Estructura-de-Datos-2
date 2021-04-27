//
// Created by victor on 26/4/2021.
//

#ifndef L05_TESTSTRUCT_H
#define L05_TESTSTRUCT_H

#include <string>
#include <iostream>

using namespace std;

// Si uno tiene un struct -> structure -> structura
/*
 * Lo que defina dentro de struct sin decir nada, es publico
 * */
struct Datos {
    int a;
    string b;
};

// Ahora el nodo existe dentro del contexto de Lista
// El nodo sigue siendo un tipo, ahora de lista, pero es un tipo

class Lista{

public:
    void agregar(int v);

    friend int main();

    friend ostream* operator<<(ostream& os, const Lista& l){
        l.mostrar(os);
    }

private:
    void mostrar(ostream& os);
    // Struct no es parte de la definicion de lista. Solo lo hacemos para definir la clase
    // La lista solo tiene una clase, que es primero_
    struct Nodo{
        int valor;
        Nodo* siguiente;

        Nodo(int valor);
    };

    Nodo* primero_;
};

void Lista::mostrar(ostream &os) {

}

Lista::Nodo::Nodo(int v) : valor(v), siguiente(nullptr) {}

void Lista::agregar(int v) {
    primero_ = new Nodo(v);
}

// Buscamos que haya multiples nodos con diverentes scope
class Conj{
public:
    void insertar(int v);

    struct Nodo{
        int valor;
        Nodo* izq;
        Nodo* der;

        Nodo(int valor);
    };

private:
    Nodo* primero;
};


int main(){
    Datos d;
    d.a = 5;
    d.b = "30";
    cout << d.b << endl;

    Lista::Nodo n(5);
    Lista l;
    l.primero_ = nullptr;
}


#endif //L05_TESTSTRUCT_H
