#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes() : _conns(){}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(_conns[id] != nullptr){
        delete _conns[id];
        _conns[id] = new ConexionJugador(ip);
    }else{
        _conns[id] = new ConexionJugador(ip);
    }
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
    delete _conns[id];
    _conns[id] = nullptr;
}

SistemaDeMensajes::~SistemaDeMensajes(){
    delete _conns[0];
    delete _conns[1];
    delete _conns[2];
    delete _conns[3];

    for(Proxy* p : _proxyVec){
        delete p;
    }
    _proxyVec.clear();
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* proxy = new Proxy(_conns[id]);
    _proxyVec.push_back(proxy);
    return proxy;
}