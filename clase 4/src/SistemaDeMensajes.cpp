#include "SistemaDeMensajes.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes() {
    for (int i = 0; i < 4; ++i) {
        _conns[i] = nullptr;
    }
}

SistemaDeMensajes::~SistemaDeMensajes(){
    for (int i = 0; i < 4; ++i) {
        delete _conns[i];
    }
    for (int i = 0; i < proxys.size(); ++i) {
        delete proxys[i];
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id){
    _conns[id] = nullptr;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* p = new Proxy(&_conns[id]);
    proxys.push_back(p);
    return p;
}