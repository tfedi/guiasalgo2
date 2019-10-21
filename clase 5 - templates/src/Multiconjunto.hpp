#ifndef __MULTICONJUNTO_HPP__
#define __MULTICONJUNTO_HPP__

#include "Diccionario.hpp"

template <class T>
class Multiconjunto{
public :
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x);
    bool operator<=(Multiconjunto<T> otro) const;

private:
    Diccionario <T,int> _multiconjunto;
};

template <class T>
Multiconjunto<T>::Multiconjunto(){
}

template <class T>
void Multiconjunto<T>::agregar(T x) {
    if(_multiconjunto.def(x)) _multiconjunto.definir(x, _multiconjunto.obtener(x)+1);
    else _multiconjunto.definir(x, 1);
}

template <class T>
int Multiconjunto<T>::ocurrencias(T x) {
    return _multiconjunto.def(x) ? _multiconjunto.obtener(x) : 0;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const {
    for (T c : _multiconjunto.claves()){
        if (!(otro._multiconjunto.def(c) && _multiconjunto.obtener(c) <= otro._multiconjunto.obtener(c)))
            return false;
    }
    return true;
}

#endif

