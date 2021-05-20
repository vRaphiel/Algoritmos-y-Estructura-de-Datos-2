template<class T1, class T2>
class Ensalada {
    public:
        Ensalada(T1 t1, T2 t2);
        T1 t1() const;
        T2 t2() const;

    private:
        T1 _t1;
        T2 _t2;
};

/** T1, T2 toman un calor concreto en tiempo de compilacion **/

template<class T1, class T2>
Ensalada<T1, T2>::Ensalada(T1 t1, T2 t2) : _t1(t1), _t2(t2){}

template<class T1, class T2>
T1 Ensalada<T1, T2> :: t1() const {
    return _t1;
}

template<class T1, class T2>
T2 Ensalada<T1, T2> :: t2() const{
    return _t2;
}