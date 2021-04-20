#include <iostream>
#include <ostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho){};

uint Rectangulo::alto() {
    return alto_;
}

uint Rectangulo::ancho() {
    return ancho_;
}

float Rectangulo::area(){
    return alto_ * ancho_ ;
}

// Ejercicio 2

// Clase Elipse
class Elipse {
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float area();
        float pi();

    private:
        int r_a_;
        int r_b_;
        float pi_ = 3.14;
};

Elipse::Elipse(uint a, uint b) : r_a_(a), r_b_(b) {}

uint Elipse::r_a(){
    return r_a_;
}

uint Elipse::r_b(){
    return r_b_;
}

float Elipse::area(){
    return pi_ * r_a_ * r_b_;
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return r_.alto();
}

float Cuadrado::area() {
    return r_.area();
}

// Ejercicio 4

class Circulo{
    public:
        Circulo(uint r);
        uint radio();
        float area();
    private:
        Elipse c_;
};

Circulo::Circulo(uint r): c_(r,r) {}
uint Circulo::radio(){
    return c_.r_a();
}
float Circulo::area(){
    return c_.area();
}

// Ejercicio 5
ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.ancho() << ", " << r.alto() << ")";
    return os;
}

ostream& operator<<(ostream& os, Elipse e){
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6
ostream& operator<<(ostream& os, Cuadrado c) {
    os << "Cuad(" << c.lado() << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo e){
    os << "Circulo(" << e.radio();
    return os;
}

