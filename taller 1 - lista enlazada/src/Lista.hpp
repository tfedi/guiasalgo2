#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    _prim = nullptr;
    _ult = nullptr;
    _cantElem = 0;
}

template <typename T>
void Lista<T>::copiarNodos(const Lista &o){
    Nodo* actual = o._prim;
    while(actual != nullptr) {
        agregarAtras(actual->valor);
        actual = actual->siguiente;
    }
}

template <typename T>
void Lista<T>::destruirNodos() {
    Nodo* actual = _prim;
    while(actual != nullptr) {
        Nodo* siguiente = actual->siguiente ;
        delete actual;
        actual = siguiente;
        _cantElem--;
    }
    _prim = nullptr;
    _ult = nullptr;
}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    _prim = nullptr;
    _ult = nullptr;
    copiarNodos(l);
}

template <typename T>
Lista<T>::~Lista() {
    destruirNodos();
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo* nuevo = new Nodo(nullptr, _prim, elem);
    if (_prim != nullptr) _prim->anterior = nuevo;
    _prim = nuevo;
    if (longitud() == 0) _ult = nuevo;
    _cantElem++;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo* nuevo = new Nodo(_ult, nullptr, elem);
    if (_ult != nullptr) _ult->siguiente = nuevo;
    _ult = nuevo;
    if (longitud() == 0) _prim = nuevo;
    _cantElem++;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    Nodo* actual = _prim;
    //Pre: i en rango.
    for (int j = 0; j < i; ++j) {
        actual = actual->siguiente;
    }

    //borro el primero
    if(actual->anterior == nullptr){
        _prim = actual->siguiente;
        //si no es el único, reapunto
        if (actual->siguiente != nullptr)
            actual->siguiente->anterior = nullptr;
    }
    //borro el ultimo
    if (actual->siguiente == nullptr){
        _ult = actual->anterior;
        //si no es el único, reapunto
        if (actual->anterior != nullptr)
            actual->anterior->siguiente = nullptr;
    }
    //borro uno del medio
    if (actual->anterior != nullptr && actual->siguiente != nullptr){
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }

    _cantElem--;
    delete actual;
}

template <typename T>
int Lista<T>::longitud() const {
    return _cantElem;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    Nodo* actual = _prim;
    for (int j = 0; j < i; ++j) {
        actual = actual->siguiente;
    }
    return actual->valor;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    Nodo* actual = _prim;
    for (int j = 0; j < i; ++j) {
        actual = actual->siguiente;
    }
    return actual->valor;
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
}