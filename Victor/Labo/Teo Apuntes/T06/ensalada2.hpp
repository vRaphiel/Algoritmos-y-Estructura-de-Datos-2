#ifndef TUPLA_HPP
#define TUPLA_HPP

template <class T1, class T2>
class Tupla {
    public:
        Tupla(T1 t1, T2 t2);
        T1 t1() const;
        T2 t2() const;

        bool operator==(Tupla t) const;

    private:
        T1 _t1;
        T2 _t2;
};

template<class T1, class T2>
bool Tupla<T1, T2>::operator==(Tupla t) const{
    return _t1==t.t1 && _t2==t.t2();
}

/** T1, T2 toman un calor concreto en tiempo de compilacion **/

template <class T1, class T2>
Tupla<T1, T2>::Tupla(T1 t1, T2 t2) : _t1(t1), _t2(t2) {}

template <class T1, class T2>
T1 Tupla<T1, T2>::t1() const
{
    return _t1;
}

template <class T1, class T2>
T2 Tupla<T1, T2>::t2() const
{
    return _t2;
}

#endif