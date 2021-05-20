#include "ensalada2.hpp"
#include "ensalada.hpp"
#include <iostream>

int main() {
    Banana b;
    Pera p;
    Manzana m;
    Tupla<Banana, Pera> ensalada1(b, p);
    Tupla<Banana, Manzana> ensalada2(b,m);
}
