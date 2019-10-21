#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
bool elementoEnVector(vector<int> s, int x){
    int i = 0;
    while (i < s.size() && s[i] != x){
        i++;
    }
    return i < s.size();
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    for (int elem : s){
        if(!elementoEnVector(res,elem)) res.push_back(elem);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res;
    set<int> miConjunto;
    for (int elem : s){
        miConjunto.insert(elem);
    }
    for (int elem : miConjunto){
        res.push_back(elem);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    for (int elem : a){
        if(!elementoEnVector(b,elem)) return false;
    }
    for (int elem : b){
        if(!elementoEnVector(a,elem)) return false;
    }
    return true;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> conjA, conjB;
    for (int elem : a){
        conjA.insert(elem);
    }
    for (int elem : b){
        conjB.insert(elem);
    }
    for (int elem: conjA){
        if(conjB.count(elem) == 0) return false;
    }
    for (int elem: conjB){
        if(conjA.count(elem) == 0) return false;
    }
    return true;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> diccionario;
    for (int elem : s){
        diccionario[elem]++;
    }
    return diccionario;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    map<int,int> cant_apar = contar_apariciones(s);
    for (pair<int,int> elem : cant_apar){
        if (elem.second == 1){
            res.push_back(elem.first);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int elem: a){
        if(b.count(elem) == 1) res.insert(elem);
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for (int num : s){
        res[num%10].insert(num);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res(str.size());
    map<char,char> traducciones;
    for (pair<char,char> traduccion : tr){
        traducciones[traduccion.first] = traduccion.second;
    }
    int i = 0;
    for (char letra : str){
        res[i] = traducciones.count(letra) == 1 ? traducciones[letra] : letra;
        i++;
    }
    return res;
}

// Ejercicio 10
bool hayRepetidos(vector<LU> libretas){
    for (int i = 0; i < libretas.size(); ++i) {
        for (int j = i+1; j < libretas.size(); ++j) {
            if (libretas[i].numero() == libretas[j].numero()
            && libretas[i].anio() == libretas[j].anio()){
                return true;
            }
        }
    }
    return false;
}

bool integrantes_repetidos(vector<Mail> s) {
    vector<LU> libretas_que_entregaron;
    map<string,set<LU>> grupos_que_entregaron;
    for (Mail mail : s){
        grupos_que_entregaron[mail.asunto()] = mail.libretas();
    }
    for (pair<string,set<LU>> grupo : grupos_que_entregaron){
        for (LU integrante : grupo.second){
            libretas_que_entregaron.push_back(integrante);
        }
    }
    return hayRepetidos(libretas_que_entregaron);
}

// Ejercicio 11
bool compararMailsPorFecha(Mail m1, Mail m2){
    return m1.fecha() < m2.fecha();
}
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    sort(s.begin(),s.end(),compararMailsPorFecha);
    map<set<LU>, Mail> res;
    for (Mail m : s){
        if (m.adjunto()) res[m.libretas()] = m;
    }
    return res;
}
