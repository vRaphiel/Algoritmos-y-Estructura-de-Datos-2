#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
            // ene, feb, mar, abr, may, jun
            31, 28, 31, 30, 31, 30,
            // jul, ago, sep, oct, nov, dic
            31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}


// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();

    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {};

int Fecha::mes() {
    return this->mes_;
}

int Fecha::dia() {
    return this->dia_;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

void Fecha::incrementar_dia() {
    int siguiente_dia = this->dia() + 1;
    int siguiente_mes = this->mes();

    if (siguiente_dia > dias_en_mes(this->mes())) {
        siguiente_dia = 1;
        siguiente_mes = (siguiente_mes + 1) % 12;
    }

    this->dia_ = siguiente_dia;
    this->mes_ = siguiente_mes;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();

    return igual_dia & igual_mes;
}
#endif

// Ejercicio 11, 12

// Clase Horario
class Horario {
    public:
        Horario(uint mes, uint dia);
        uint hora();
        uint min();

        bool operator==(Horario o);
        bool operator<(Horario h);

private:
        int hora_;
        int min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {};

uint Horario::hora() {
    return this->hora_;
}

uint Horario::min() {
    return this->min_;
}

bool Horario::operator==(Horario h) {
    bool igual_hora = this->hora() == h.hora();
    bool igual_min = this->min() == h.min();

    return igual_hora & igual_min;
}

bool Horario::operator<(Horario h) {
    if(this->hora() == h.hora()) {
        return this->min() < h.min();
    }

    return this->hora() < h.hora();
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

// Ejercicio 13

class Recordatorio {
    public:
        Recordatorio(Fecha f, Horario h, string m);
        Fecha fecha();
        Horario horario();
        string mensaje();

    private:
        Fecha fecha_;
        Horario horario_;
        string mensaje_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string m): fecha_(f), horario_(h), mensaje_(m) {}

Fecha Recordatorio::fecha() {
    return this->fecha_;
}

Horario Recordatorio::horario() {
    return this->horario_;
}

string Recordatorio::mensaje() {
    return this->mensaje_;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}

// Ejercicio 14

class Agenda {
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();

    private:
        Fecha hoy_;
        vector<Recordatorio> recordatorios_;
        list<Recordatorio> recordatorios_de_hoy_;
};

Agenda::Agenda(Fecha fecha_inicial): hoy_(fecha_inicial) {}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    this->recordatorios_.push_back(rec);
}

void Agenda::incrementar_dia() {
    this->hoy_.incrementar_dia();
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    vector<Recordatorio> recordatorios_de_hoy_parcial_;

    // me quedo solo con los recordatorios de hoy
    for (int i = 0; i < this->recordatorios_.size(); ++i) {
        if (this->recordatorios_[i].fecha() == this->hoy()) {
            recordatorios_de_hoy_parcial_.push_back(this->recordatorios_[i]);
        }
    }

    // ordeno los recordatorios de hoy
    for (int i = 0;i < recordatorios_de_hoy_parcial_.size(); i++){
            for (int j = 0; j< recordatorios_de_hoy_parcial_.size()-1; j++){
                if (recordatorios_de_hoy_parcial_[j+1].horario() < recordatorios_de_hoy_parcial_[j].horario() ) {
                    Recordatorio recordatorioParcial = recordatorios_de_hoy_parcial_[j];
                    recordatorios_de_hoy_parcial_[j] = recordatorios_de_hoy_parcial_[j+1];
                    recordatorios_de_hoy_parcial_[j+1] = recordatorioParcial;
                }
            }
    }

    // guardo los recordatorios de hoy ordenados en recordatorios_de_hoy
    for (int i = 0; i < recordatorios_de_hoy_parcial_.size(); ++i) {
        this->recordatorios_de_hoy_.push_back(recordatorios_de_hoy_parcial_[i]);
    }

    return this->recordatorios_de_hoy_;
}

Fecha Agenda::hoy() {
    return this->hoy_;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl;
    os << "=====" << endl;

    for (auto recordatorio : a.recordatorios_de_hoy())
        os << recordatorio << endl;

    return os;
}