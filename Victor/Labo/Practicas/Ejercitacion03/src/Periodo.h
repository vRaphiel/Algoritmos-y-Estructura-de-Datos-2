//
// Created by victor on 29/3/2021.
//

#ifndef SOLUCION_PERIODO_H
#define SOLUCION_PERIODO_H

#endif //SOLUCION_PERIODO_H

class Periodo {
public:
    Periodo(int anios, int meses, int dias);

    int anios() const;
    int meses() const;
    int dias() const;

private:
    int anios_;
    int meses_;
    int dias_;
};