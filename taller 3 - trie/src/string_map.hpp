template <typename T>
string_map<T>::string_map(){
    raiz = new Nodo;
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() {
    *this = aCopiar;
} // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    raiz = new Nodo;
    _size = 0;
    for(string c : d.claves){
        insert(make_pair(c,d.at(c)));
    }
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* n = aDefinicion(clave);
    return n == nullptr || n->definicion == nullptr ? 0 : 1;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* n = aDefinicion(clave);
    return *n->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* n = aDefinicion(clave);
    return *n->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return size() == 0;
}

template<typename T>
typename string_map<T>::Nodo * string_map<T>::aDefinicion(const string &key) const {
    Nodo* nodoActual = raiz;
    for (int i = 0; i < key.size() && nodoActual != nullptr; i++){
        nodoActual = nodoActual->siguientes[key[i]];
    }
    return nodoActual;
}

template<typename T>
void string_map<T>::insert(const pair<string, T> &val) {
    Nodo* nodoActual = raiz;
    for (int i = 0; i < val.first.size() - 1; i++){
        if (nodoActual->siguientes[val.first[i]] == nullptr)
            nodoActual->siguientes[val.first[i]] = new Nodo;

        nodoActual = nodoActual->siguientes[val.first[i]];
    }

    if (nodoActual->siguientes[val.first[val.first.size()-1]] != nullptr){
        T* sigAnterior = nodoActual->siguientes[val.first[val.first.size()-1]]->definicion;
        nodoActual->siguientes[val.first[val.first.size()-1]]->definicion = new T(val.second);
        delete sigAnterior;
    }
    else{
        nodoActual->siguientes[val.first[val.first.size()-1]] = new Nodo(val.second);
        _size++;
        claves.push_back(val.first);
    }
}