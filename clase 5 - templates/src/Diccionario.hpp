#ifndef __DICCIONARIO_HPP__
#define __DICCIONARIO_HPP__

#include <vector>
#include <cassert>

template <class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    std::vector<Clave> claves() const;
private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};

template <class Clave, class Valor>
Diccionario<Clave,Valor>::Diccionario() {
}

template <class Clave, class Valor>
Diccionario<Clave,Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template <class Clave, class Valor>
void Diccionario<Clave,Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template <class Clave, class Valor>
bool Diccionario<Clave,Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template <class Clave, class Valor>
Valor Diccionario<Clave,Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

template <class Clave, class Valor>
std::vector<Clave> Diccionario<Clave,Valor>::claves() const{
    //Genero vector de claves.
    std::vector<Clave> claves;
    for (Asociacion a : _asociaciones){
        claves.push_back(a.clave);
    }
    //Si no llega a los 2 elementos, no hace falta ordenar.
    if(claves.size() < 2){
        return claves;
    }
    //Lo ordeno.
    for (int i = 0; i < claves.size()-1; ++i) {
        for (int j = 0; j < claves.size()-1; ++j) {
            if (!(claves[j] <= claves[j+1])){
                Clave aux = claves[j];
                claves[j] = claves[j+1];
                claves[j+1] = aux;
            }
        }
    }
    return claves;
}

#endif
