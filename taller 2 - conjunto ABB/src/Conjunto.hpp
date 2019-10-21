
template <class T>
Conjunto<T>::Conjunto() {
    this->cant_elem = 0;
    this->_raiz = nullptr;
    this->menor_elem = nullptr;
    this->mayor_elem = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() { 
    destruirNodos(_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    return obtenerNodo(clave) != nullptr;
}

template <class T>
void Conjunto<T>::insertar(const T& clave){
    if (pertenece(clave))
        return;
    else if (cardinal() == 0){
        _raiz = new Nodo(clave);
        mayor_elem = _raiz;
        menor_elem = _raiz;
        cant_elem = 1;
    }
    else{
        Nodo* actual = _raiz;
        bool inserte = false;
        while (!inserte){
            if (actual->valor > clave){
                if (actual->izq == nullptr){
                    actual->izq = new Nodo(clave);
                    if (clave < menor_elem->valor)
                        menor_elem = actual->izq;
                    inserte = true;
                }
                else
                    actual = actual->izq;
            }
            else{
                if (actual->der == nullptr){
                    actual->der = new Nodo(clave);
                    if (clave > mayor_elem->valor)
                        mayor_elem = actual->der;
                    inserte = true;
                }
                else
                    actual = actual->der;
            }
        }
        cant_elem++;
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if (!pertenece(clave))
        return;
    else{
        corregirMayoryMenor(clave);
        Nodo* aEliminar = obtenerNodo(clave);
        Nodo* padre = obtenerPadre(aEliminar);
        Nodo* hijo = obtenerHijoUnico(aEliminar);

        if (aEliminar->izq != nullptr && aEliminar->der != nullptr) {
            Nodo* predecesor = obtenerPredecesor(aEliminar);
            padre = obtenerPadre(predecesor);
            hijo = obtenerHijoUnico(predecesor);
            aEliminar->valor = predecesor->valor;
            aEliminar = predecesor;
        }
        if (padre != nullptr){
            if (padre->izq == aEliminar)
                padre->izq = hijo;
            else
                padre->der = hijo;
        }
        //ESTOY QUERIENDO ELIMINAR EL PADRE Y TIENE UN SOLO HIJO
        else if (hijo != nullptr){
            if (aEliminar->izq == hijo)
                aEliminar->izq = nullptr;
            else
                aEliminar->der = nullptr;

            _raiz = hijo;
        }
        //ESTOY QUERIENDO ELIMINAR EL ÚNICO NODO
        else
            _raiz = nullptr;

        cant_elem--;
        delete aEliminar;
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
    while (actual->valor != clave){
        if (actual->valor > clave)
            actual = actual->izq;
        else
            actual = actual->der;
    }
    Nodo* sucesor = obtenerSucesor(actual);
    return sucesor->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    return menor_elem->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    return mayor_elem->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return cant_elem;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

template<class T>
typename Conjunto<T>::Nodo * Conjunto<T>::obtenerNodo(const T &v) const {
    Nodo* actual = _raiz;
    while (actual != nullptr && actual->valor != v) {
        if (actual->valor > v)
            actual = actual->izq;
        else
            actual = actual->der;
    }
    return actual;
}

template <class T>
typename Conjunto<T>::Nodo *Conjunto<T>::obtenerPadre(Conjunto::Nodo *e) {
    Nodo* padre = _raiz;
    while (padre != nullptr && padre->izq != e && padre->der != e){
        if (padre->valor > e->valor)
            padre = padre->izq;
        else
            padre = padre->der;
    }
    return padre;
}

template<class T>
typename Conjunto<T>::Nodo *Conjunto<T>::obtenerHijoUnico(Conjunto::Nodo *e) {
    if(e->izq != nullptr)
        return e->izq;
    else
        return e->der;
}

template <class T>
typename Conjunto<T>::Nodo *Conjunto<T>::obtenerPredecesor(Conjunto::Nodo *e) {
    if (e->izq == nullptr){
        Nodo* padre = obtenerPadre(e);
        return (padre != nullptr && padre->valor < e->valor) ? padre : nullptr;
    }
    else {
        Nodo* predecesor = e->izq;
        while (predecesor->der != nullptr){
            predecesor = predecesor->der;
        }
        return predecesor;
    }
}

template<class T>
typename Conjunto<T>::Nodo *Conjunto<T>::obtenerSucesor(Conjunto::Nodo *e) {
    if (e->der == nullptr){
        Nodo* padre = obtenerPadre(e);
        return (padre != nullptr && padre->valor > e->valor) ? padre : nullptr;
    }
    else {
        Nodo* sucesor = e->der;
        while (sucesor->izq != nullptr){
            sucesor = sucesor->izq;
        }
        return sucesor;
    }
}

template<class T>
void Conjunto<T>::destruirNodos(Conjunto::Nodo *pNodo) {
    if (pNodo != nullptr){
        destruirNodos(pNodo->izq);
        destruirNodos(pNodo->der);
        delete pNodo;
    }
}

template<class T>
void Conjunto<T>::corregirMayoryMenor(const T &eliminado) {
    if (menor_elem->valor == eliminado)
        menor_elem = obtenerSucesor(obtenerNodo(eliminado));
    if (mayor_elem->valor == eliminado)
        mayor_elem = obtenerPredecesor(obtenerNodo(eliminado));
}
