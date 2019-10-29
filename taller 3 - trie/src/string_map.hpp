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
    Nodo* actual = raiz;
    destruirNodo(actual);
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
    Nodo* actNodo = raiz;
    Nodo* ultNodo = raiz;
    int ultIndice = -1;

    for (int i = 0; i < clave.size(); ++i) {
        actNodo = actNodo->siguientes[clave[i]];
        if (esNodoUtil(actNodo) && i != clave.size()-1){
            ultNodo = actNodo;
            ultIndice = i;
        }
    }

    //Si o si hay que borrar la definición.
    T* def = actNodo->definicion;
    actNodo->definicion = nullptr;
    delete def;

    //Si no tiene hijos, borramos los nodos que no sirven.
    if (cantHijos(actNodo) == 0){

        Nodo* aux = ultNodo->siguientes[clave[ultIndice+1]];
        ultNodo->siguientes[clave[ultIndice+1]] = nullptr;
        ultNodo = aux;

        while (ultNodo != actNodo){
            Nodo* borrar = ultNodo;
            ultNodo = obtenerHijoUnico(ultNodo);
            delete borrar;
        }
        delete actNodo;
    }

    //Ajustamos el size y actualizamos las claves
    _size--;
    vector<string> nuevasClaves;
    for (string c : claves){
        if (c != clave)
            nuevasClaves.push_back(c);
    }
    claves = nuevasClaves;
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

template<typename T>
bool string_map<T>::esNodoUtil(string_map::Nodo *pNodo) {
    return pNodo->definicion != nullptr || cantHijos(pNodo) > 1;
}

template<typename T>
int string_map<T>::cantHijos(string_map::Nodo *pNodo) {
    int res = 0;
    for (Nodo* sig : pNodo->siguientes){
        res = sig != nullptr ? res+1 : res;
    }
    return res;
}

template<typename T>
//PRE: hay un solo hijo.
typename string_map<T>::Nodo *string_map<T>::obtenerHijoUnico(string_map::Nodo *pNodo) {
    vector<Nodo*> hijos = pNodo->siguientes;
    int i = 0;
    while (i < hijos.size() && hijos[i] == nullptr) {
        i++;
    }
    return hijos[i];
}

template<typename T>
void string_map<T>::destruirNodo(string_map::Nodo *pNodo) {
    //Borro la definición
    T* def = pNodo->definicion;
    pNodo->definicion = nullptr;
    delete def;

    //Limpio el vector de siguientes
    for (int i = 0; i < pNodo->siguientes.size(); i++){
        if (pNodo->siguientes[i] != nullptr){
            Nodo* n = pNodo->siguientes[i];
            pNodo->siguientes[i] = nullptr;
            destruirNodo(n);
        }
    }
    delete pNodo;
}
