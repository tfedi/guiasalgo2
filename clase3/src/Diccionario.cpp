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

std::vector<Clave> Diccionario::claves() const{
    std::vector<Clave> claves;
    for(Asociacion a : asociaciones){
        claves.push_back(a.clave);
    }
    std::sort(claves.begin(),claves.end());
    return claves;
}

std::vector<Valor> Diccionario::valores() const{
    std::vector<Valor> valores;
    for(Asociacion a : asociaciones){
        valores.push_back(a.valor);
    }
    std::sort(valores.begin(),valores.end());
    return valores;
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

int maximaClave(std::vector<Clave> v1){
    int maximo = v1[0];
    for(Clave c : v1){
        if(c > maximo){
            maximo = c;
        }
    }
    return maximo;
}

int minimaClave(std::vector<Clave> v1){
    int minimo = v1[0];
    for(Clave c : v1){
        if(c < minimo){
            minimo = c;
        }
    }
    return minimo;
}

bool todosCero(std::vector<int> v){
    bool res = true;
    for(int i : v){
        if (i != 0) res = false;
    }
    return res;
}

bool auxPermutacion(std::vector<Clave> v1, std::vector<Clave> v2){ // Pre: |v1| = |v2|
    int minimaclave = minimaClave(v1);
    int maximaclave = maximaClave(v1);
    std::vector<int> apariciones(maximaclave-minimaclave+1,0);
    for(Clave c : v1){
        apariciones[c-minimaclave]++;
    }
    for(Clave c2 : v2){
        if(c2 > maximaclave || c2 < minimaclave){
            return false;
        }else{
            apariciones[c2-minimaclave]--;
        }
    }
    return todosCero(apariciones);
}

bool esPermutacion(std::vector<Clave> v1, std::vector<Clave> v2){
    bool res = true;
    if(v1.size() != v2.size()){
        res = false;
    }else{
        res = v1.empty() ? true : auxPermutacion(v1,v2);
    }
    return res;
}

bool Diccionario::operator==(Diccionario o) const {
    return esPermutacion(claves(),o.claves()) && esPermutacion(valores(),o.valores());
}

Diccionario Diccionario::operator&&(Diccionario o) const {
    Diccionario diccionario;
    for(Clave key : claves()){
        if(o.def(key)){
            diccionario.definir(key,obtener(key));
        }
    }
    return diccionario;
}

Diccionario Diccionario::operator||(Diccionario o) const {
    Diccionario diccionario;
    for(Clave key : claves()){
        diccionario.definir(key,obtener(key));
    }
    for(Clave key : o.claves()){
        if(!def(key)){
            diccionario.definir(key,o.obtener(key));
        }
    }
    return diccionario;
}