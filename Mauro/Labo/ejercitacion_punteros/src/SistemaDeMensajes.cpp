#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes():_conns() {}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if (_conns[id] != nullptr) {
        delete(_conns[id]);
    }

    _conns[id] = new ConexionJugador(ip);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    delete(_conns[id]);
    _conns[id] = nullptr;
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i = 0; i < 4; ++i) {
        delete(_conns[i]);
    }

    for (int i = 0; i < _proxies.size(); ++i) {
        delete(_proxies[i]);
    }

    _proxies.clear();

}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* p = new Proxy(_conns[id]);
    _proxies.push_back(p);

    return p;
}
