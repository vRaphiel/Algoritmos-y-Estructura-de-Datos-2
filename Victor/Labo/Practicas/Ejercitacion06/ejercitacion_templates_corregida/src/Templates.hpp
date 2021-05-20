template<class T>
T cuadrado(T x){
    return x*x;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor c, Elem e){
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == e) {
            return true;
        }
    }
    return false;
};

template<class ContenedorA, class ContenedorB>
bool esPrefijo(ContenedorA cA, ContenedorB cB){
    bool esPref = true;
    if(cA.size() < cB.size()) {
        for(int i = 0; i<cA.size(); i++){
            if(cA[i] != cB[i]){
                esPref = false;
            }
        }
    }else{
        esPref = false;
    }
    return esPref;
}

template<class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem maximo = c[0];
    for(int i = 0; i < c.size(); i++){
        if(maximo < c[i]){
            maximo = c[i];
        }
    }
    return maximo;
}