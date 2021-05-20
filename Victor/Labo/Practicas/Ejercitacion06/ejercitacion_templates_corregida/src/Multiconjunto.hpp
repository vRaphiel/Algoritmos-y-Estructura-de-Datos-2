#include "Diccionario.hpp"

template<class T>
class Multiconjunto{
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    int cardinal() const;
    bool operator<=(Multiconjunto<T> otro) const;
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
int Multiconjunto<T>::ocurrencias(T x) const {
    if(_dicc.def(x)){
        return _dicc.obtener(x);
    }else{
        return 0;
    }
}

template<class T>
int Multiconjunto<T>::cardinal() const{
    return this->_dicc.claves().size();
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const {
    // Vemos si esta uno dentro de otro
    // Llamo a mi conjunto con this, y al otro como otro
    bool estaIncluido = true;
    // Valido si los cardinales estan en rango
    // Si este multiconjunto esta en otro su cardinal debe ser menor al del otro
    int thisCardinal = this->cardinal();
    int thatCardinal = otro.cardinal();

    if(thisCardinal <= thatCardinal){

        for(int i = 0; i<this->cardinal(); i++){

            T xFirst = this->_dicc.claves()[i];
            T xSecond = otro._dicc.claves()[i];

            int xOcurrenciasF = ocurrencias(xFirst);
            int xOcurrenciasS = otro.ocurrencias(xSecond);

            if(xOcurrenciasF > xOcurrenciasS){
                estaIncluido = false;
            }

        }

    }else{
        estaIncluido = false;
    }
    return estaIncluido;
}