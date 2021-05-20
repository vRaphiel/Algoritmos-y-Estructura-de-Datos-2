#include "Diccionario.hpp"

template<class T>
class Multiconjunto{
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x);
private:
    Diccionario<T, int> _dicc;
};

template<class T>
Multiconjunto<T>::Multiconjunto() {};

template<class T>
void Multiconjunto<T>::agregar(T x) {
    if(_dicc.def(x)){
        int value = _dicc.obtener(x);
        _dicc.definir(x, (value + 1));
    }else{
        _dicc.definir(x, 1);
    }
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) {
    if(_dicc.def(x)){
        return _dicc.obtener(x);
    }else{
        return 0;
    }
}