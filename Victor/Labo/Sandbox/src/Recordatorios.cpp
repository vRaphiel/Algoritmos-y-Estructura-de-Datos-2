#include <iostream>
#include <ostream>
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
    Fecha(uint mes, uint dia);
    uint mes();
    uint dia();
    void incrementar_dia();

    // Completar declaraciones funciones
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

private:
    //Completar miembros internos
    uint mes_;
    uint dia_;
};

Fecha::Fecha(uint mes, uint dia) : mes_(mes), dia_(dia){}
uint Fecha::mes() {return mes_;}
uint Fecha::dia() {return dia_;}

ostream& operator<<(ostream& os , Fecha f){
    os << f.dia() << "/" << f.mes();
    return os;
}

void Fecha::incrementar_dia() {
    if(dia_ < dias_en_mes(mes_)) {
        dia_ = dia_ + 1;
    } else {
        dia_ = 1;
        if(mes_ == 12){
            mes_ = 1;
        }else{
            mes_ = mes_+1;
        }
    }
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia_ == o.dia();
    bool igual_mes = this->mes_ == o.mes();
    // Completar iguadad (ej 9)
    return igual_dia && igual_mes;
}
#endif

// Ejercicio 11, 12

// Clase Horario
class Horario{
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator<(Horario h);
private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min){}
uint Horario::hora() {return hora_;}
uint Horario::min() {return min_;}

bool Horario::operator<(Horario h) {
    if(this->hora() == h.hora()){
        return this->min() < h.min();
    }

    return this->hora() < h.hora();
}

ostream& operator<<(ostream& os, Horario h){
    os << h.hora() << ":" << h.min();
    return os;
}

// Ejercicio 13

// Clase Recordatorio
class Recordatorio{
public:
    Recordatorio(Fecha f, Horario h, string mensaje);
    string mensaje();
    Fecha fecha();
    Horario horario();
private:
    string mensaje_;
    Fecha f_;
    Horario h_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string mensaje) : f_(f), h_(h), mensaje_(mensaje){}
Fecha Recordatorio::fecha() {return f_;}
Horario Recordatorio::horario() {return h_;}
string Recordatorio::mensaje() {return mensaje_;}
ostream& operator<<(ostream& os, Recordatorio r){
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}
// Ejercicio 14

// Clase Agenda
class Agenda{
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

    private:
        Fecha dia_actual_;
        list<Recordatorio> recordatorios_;
};

ostream& operator<<(ostream& os, Agenda a){
    os << a.hoy() <<"\n";
    os << "=====" <<"\n";
    for (Recordatorio rec : a.recordatorios_de_hoy()) {
        os << rec <<"\n";
    }
    return os;
}

Agenda::Agenda(Fecha fecha_inicial) : dia_actual_(fecha_inicial){}

Fecha Agenda::hoy(){
    return dia_actual_;
}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    recordatorios_.push_back(rec);
}

void Agenda::incrementar_dia() {
    dia_actual_.incrementar_dia();
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    vector<Recordatorio> lRecAux = {};

    // Selecciono de todos los recordatorios, los que sean del dia actual
    for(Recordatorio recAux : recordatorios_){
        /* Opte por ponerlo asi en vez de comparar la fecha directamente ya que, el operador == esta habilitado desde el ej. 9
         * en adelante y, si estoy en un caso de ejercicio distinto al 9, no lo encuentra y explota el programa */
        if(recAux.fecha().dia() == hoy().dia() &&
            recAux.fecha().mes() == hoy().mes()){
            lRecAux.push_back(recAux);
        }
    }

    // Si tengo almenos un recordatorio del dia actual, entonces ordeno la lista por horario
    if(lRecAux.size()>0){
        for(int i = 0; i < lRecAux.size()-1; i++){
            for(int j = 0; j< lRecAux.size()-1; j++){
                if(lRecAux[j+1].horario() < lRecAux[i].horario()){
                    Recordatorio temp = lRecAux[i];
                    lRecAux[i] = lRecAux[j+1];
                    lRecAux[j+1] = temp;
                }
            }
        }
    }

    // Como debo devolver una lista, "convierto" el vector en lista
    list<Recordatorio> entrega = {};
    for(int i = 0; i < lRecAux.size(); i++){
        entrega.push_back(lRecAux[i]);
    }

    return entrega;
}