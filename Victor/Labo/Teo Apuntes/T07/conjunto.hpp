template <class T>
class Conjunto{
    public:
        Conjunto();
        void insertar(const T&);
        bool pertenece(const T&) const;
        void remover(const T&);
        const T& minimo() const;
        const T& maximo() const;
        unsigned int cardinal() const;
        void mostrar(std::ostream&) const;
        const T& siguiente(const T&) const;

    private:
        struct Nodo {
            T valor;
            Nodo* izq;
            Nodo* der;
            int cant;
            Nodo(const T& v):
                valor(v), izq(NULL), der(NULL), cant(0){}
        };
        Nodo* nodo;
};

// La raiz es la unica variable de instancia y apunta al nodo raiz del ABB o es NULL si el ABB no tiene nodos

void inOrder(vector<T>& v, int cantAnt){
    int indice = cantIzq() + cantAnt;
    v[indice] = info;
    if(izq != null) izq.inOrder(v, cantAnt);
    if(der != null) der.inOrder(v, indice+1);
}