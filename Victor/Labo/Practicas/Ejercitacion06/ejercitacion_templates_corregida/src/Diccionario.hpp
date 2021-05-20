#include <vector>
typedef int Clave;
typedef int Valor;

template<class Clave, class Valor>
class Diccionario{
    public:
        Diccionario();
        void definir(Clave k, Valor v);
        bool def(Clave k) const;
        Valor obtener(Clave k) const;
        std::vector<Clave> claves();
        Valor menor() const;
    private:
        struct Asociacion{
            Asociacion(Clave k, Valor v);
            Clave clave;
            Valor valor;
        };
        std::vector<Asociacion> _asociaciones;
};

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {}

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

template<class Clave, class Valor>
Clave Diccionario<Clave, Valor>::menor() const {

}

template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave, Valor>::claves() {
    std::vector<Clave> v1(_asociaciones.size(), 0);
    for(int i = 0; i< _asociaciones.size(); i++){
        v1[i] = _asociaciones[i].clave;
    }

    for(int i = 0; i<v1.size(); i++){

    }
    return v1;
}