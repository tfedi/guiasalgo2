template <class T>
T cuadrado(T x) {
    return x * x;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    if (a.size() > b.size()) return false;
    int i = 0;
    while (i < a.size() && a[i] == b[i]){
        i++;
    }
    return i == a.size();
}

template <class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem max = c[0];
    for (int i = 1; i < c.size(); ++i) {
        if (c[i] > max){
            max = c[i];
        }
    }
    return max;
}



