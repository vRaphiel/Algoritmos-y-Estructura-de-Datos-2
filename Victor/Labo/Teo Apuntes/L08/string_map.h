#ifndef STRING_MAP_H_
#define STRING_MAP_H_

template<class T>
class string_map {
public:
private:
    struct Nodo{
    vector<Nodo*> siguientes;
    T* definicion;
    Nodo() : siguientes(256, nullptr), definicion(nullptr) {}
    Nodo(T def) : siguientes(256, nullptr), definicion(def) {}
};
};

#endif // STRING_MAP_H_