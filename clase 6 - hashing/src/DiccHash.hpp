#include "DiccHash.h"

/* Constructor sin parámetros de la clase */
template<class V>
DiccHash<V>::DiccHash() {
	_tam = TAM_INICIAL;
	vector<list<Asociacion>> tabAux(_tam);
	_tabla = tabAux;
	_cant_claves = 0;
}

/* Destructor */
template<class V>
DiccHash<V>::~DiccHash() {

}

/* Devuelve true si la clave está definida en el diccionario.
 * - clav : clave a buscar
 */
template<class V>
bool DiccHash<V>::definido(const string& clav) const {
	for (Asociacion asoc : _tabla[fn_hash(clav)]){
		if (asoc.clave == clav)
			return true;
	}

	return false;
}

/* Agrega una clave y su significado al Diccionario.
 * Si la clave a agregar ya se encuentra definida,
 * redefine su significado.
 * - clav : clave a agregar
 * - sig  : significado de la clave a agregar
 *
 * Nota de implementación:
 *
 * Si el factor de carga supera el valor de UMBRAL_FC, se debe
 * redimensionar la tabla al doble de tamaño.
 *
 */
template<class V>
void DiccHash<V>::definir(const string& clav, const V& sig) {
	if (factorCarga() > UMBRAL_FC)
		redimensionarTabla();
	if (definido(clav)){
		list<Asociacion> nueva;
		for (Asociacion asoc : _tabla[fn_hash(clav)]){
			if (asoc.clave == clav) {
				asoc.valor = sig;
			}
			nueva.push_back(asoc);
		}
		_tabla[fn_hash(clav)] = nueva;
	}
	else {
		Asociacion nueva(clav,sig);
		_tabla[fn_hash(clav)].push_back(nueva);
		_cant_claves++;
	}
}

/* Busca en el diccionario el significado de la clave clav.
 * - clav : clave a buscar
 * Devuelve el significado de clav.
 */
template<class V>
V& DiccHash<V>::significado(const string& clav) {
	list<Asociacion> asociaciones = _tabla[fn_hash(clav)];
	for (Asociacion asociacion : asociaciones)
		if (asociacion.clave == clav)
			return asociacion.valor;
}

/* Borra la clave del diccionario
 * - clav : clave a borrar
 *
 * Precondición: clav está definida en el diccionario */
template<class V>
void DiccHash<V>::borrar(const string& clav) {
	list<Asociacion> original = _tabla[fn_hash(clav)];
	list<Asociacion> nueva;
	for (Asociacion asociacion : original){
		if (asociacion.clave != clav)
			nueva.push_back(asociacion);
	}
	_tabla[fn_hash(clav)] = nueva;
	_cant_claves--;
}

/* Devuelve la cantidad de claves definidas en el diccionario. */
template<class V>
unsigned int DiccHash<V>::cantClaves() const {
	return _cant_claves;
}

/* Devuelve el conjunto de claves del diccionario. */
template<class V>
set<string> DiccHash<V>::claves() const {
	set<string> res;
	for (list<Asociacion> lista : _tabla){
		for (Asociacion asoc : lista){
			res.insert(asoc.clave);
		}
	}
	return res;
}

/* SÓLO PARA TESTING
 *
 * Devuelve el factor de carga de la tabla de hash.
 * Factor de carga : cantidad de claves definidas / tamaño de la tabla.
 */
template<class V>
float DiccHash<V>::factorCarga() const {
	return _cant_claves / _tam;
}

/* SÓLO PARA TESTING
 * Devuelve la cantidad de colisiones que tiene el diccionario.
 *
 * Observación: si en una celda de la tabla conviven n elementos,
 * hay n * (n - 1) / 2 colisiones en esa celda.
 */
template<class V>
unsigned int DiccHash<V>::colisiones() const {
	unsigned int suma = 0;
	for (int i = 0; i < _tam; i++) {
		suma += _tabla[i].size() * (_tabla[i].size() - 1) / 2;
	}
	return suma;
}

/* Función de hash.
 * Recordar usar "hash = hash % _tam".
 * (El operador "%" calcula el resto en la división o "módulo").
 * Devuelve la posición de la tabla asociada a la clave dada.
 */
template<class V>
unsigned int DiccHash<V>::fn_hash(const string& str) const {
	int h = 0;
	for(int i = 0; i < str.size(); i++) {
		h = 131 * h + int(str[i]);
	}
	return h % _tam;
}
/*
* Pasos a seguir para redimensionar la tabla:
* - Crear una tabla del doble de tamaño de la original.
* - Insertar todas las claves de la tabla original en la tabla nueva.
* - Liberar la memoria reservada para la tabla original.
*/
template<class V>
void DiccHash<V>::redimensionarTabla() {
	_tam *= 2;
	_cant_claves = 0; //pq al redefinir las vuelve a sumar

	vector<list<Asociacion>> nuevaTabla(_tam);
	vector<list<Asociacion>> viejaTabla = _tabla;
	_tabla = nuevaTabla;

	for (list<Asociacion> l : viejaTabla)
		for (Asociacion a : l)
			definir(a.clave,a.valor);
}

