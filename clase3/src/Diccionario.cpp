#include "Diccionario.h"

Diccionario::Diccionario() {}

void Diccionario::definir(Clave k, Valor v) {
    int i = 0;
    for (; i < asociaciones.size(); ++i) {
        if(asociaciones[i].clave == k){
            asociaciones[i].valor = v;
        }
    }
    if(i == asociaciones.size()){
        Asociacion asociacion;
        asociacion.clave = k;
        asociacion.valor = v;
        asociaciones.push_back(asociacion);
    }

}

bool myfunction (int i,int j) { return (i<j); }

bool esPermutacion(std::vector<Clave> v1, std::vector<Clave> v2){
    bool res = true;
    if(v1.size() != v2.size()){
        res = false;
    }else{
        // Chequear permutacioness
    }
}

std::vector<Clave> Diccionario::claves() {
    std::vector<Clave> claves;
    for(Asociacion a : asociaciones){
        claves.push_back(a.clave);
    }
    std::sort(claves.begin(),claves.end());
    return claves;
}

bool Diccionario::def(Clave k) const {
    bool res = false;
    for(Asociacion asociacion : asociaciones){
        if(asociacion.clave == k){
            res = true;
        }
    }
    return res;
}

Valor Diccionario::obtener(Clave k) const { // Pre: existe la clave k y tiene un valor definido
    for(Asociacion asociacion : asociaciones){
        if(asociacion.clave == k){
            return asociacion.valor;
        }
    }
}

void Diccionario::borrar(Clave k) {
    for (int i = 0; i < asociaciones.size(); ++i) {
        if(asociaciones[i].clave == k){
            asociaciones.erase(asociaciones.begin()+i);
        }
    }
}