#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <string>

using namespace std;


class Truco{
    public:
        uint puntaje_j1();
        uint puntaje_j2();

        Truco();
        void sumar_punto(uint);
        bool buenas(uint);

    private:
        uint puntaje_j1_;
        uint puntaje_j2_;
};

using LU = std::string;
using Materia = std::string;
using Nota = int;

class Libreta {
    public:
        Libreta(LU);
        LU lu();
        set<Materia> practicos_aprobados();
        set<Materia> finales_aprobados();
        Nota nota_final(Materia m);

        void aprobar_practico(Materia m);
        void aprobar_final(Materia m, Nota nota);

    private:
        LU lu_;
        set<Materia> practicos_;
        map<Materia, Nota> finales_;
};

LU Libreta::lu() {
    return lu_;
}

set<Materia> Libreta::practicos_aprobados() {
    return practicos_;
}

set<Materia> Libreta::finales_aprobados() {
    set<Materia> ret;
    for (pair<Materia, Nota> pn : finales_) {
        ret.insert(pn.first);
    }
    return ret;
}

Nota Libreta::nota_final(Materia m) {
    return finales_.at(m);
}

Libreta::Libreta(LU lu) : lu_(lu), practicos_(), finales_() {}
void Libreta::aprobar_practico(Materia m) {
    practicos_.insert(m);
}

void Libreta::aprobar_final(Materia m, Nota n) {
    practicos_.insert(m);
    finales_.insert(make_pair(m, n));
}
