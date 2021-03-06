#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include <string>
#include <vector>
//#include "Proxy.h"
#include "Proxy2.h"

using namespace std;

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    void registrarJugador(int id, string ip);
    bool registrado(int id) const;
    void desregistrarJugador(int id);
    void enviarMensaje(int id, string mensaje);
    string ipJugador(int id) const;
    ~SistemaDeMensajes();
    Proxy* obtenerProxy(int id);

  private:
    ConexionJugador* _conns[4];
    vector<Proxy*> _proxyVec;
};
