#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    auto min = *it;
    while (it != c.end()){
        if (*it < min)
            min = *it;
        it++;
    }
    return min;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::value_type total = 0;
    typename Contenedor::value_type cantElem = 0;
    while(it != c.end()){
        total += *it;
        cantElem++;
        it++;
    }
    return total/cantElem;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    auto it = desde;
    typename Iterator::value_type min = *it;
    while (it != hasta){
        if (min > *it){
            min = *it;
        }
        it++;
    }
    return min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type total = 0;
    typename Iterator::value_type cantElem = 0;
    Iterator it = desde;
    while(it != hasta){
        total += *it;
        cantElem++;
        it++;
    }
    return total/cantElem;
}

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    typename Contenedor::iterator it = c.begin();
    while (it != c.end()){
        if (*it == elem){
            it = c.erase(it);
        }
        else{
            it++;
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c){
    typename Contenedor::const_iterator it = c.begin();
    it++;
    while (it != c.end()){
        auto anterior = it;
        anterior--;
        if (!(*it > *anterior))
            return false;
        it++;
    }
    return true;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor>
split(const Contenedor & c,
      const typename Contenedor::value_type& elem){
    Contenedor c1,c2;
    typename Contenedor::iterator it1 = c1.begin();
    typename Contenedor::iterator it2 = c2.begin();

    auto it = c.end();

    while(1){
        if (*it < elem){
            it1 = c1.insert(it1,*it);
        }
        else{
            it2 = c2.insert(it2,*it);
        }

        if(it == c.begin()){
            return make_pair(c1,c2);
        }

        it--;
    }
}

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
