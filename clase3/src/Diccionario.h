#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>

typedef int Clave;
typedef int Valor;

class Diccionario {

public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	void borrar(Clave k);
	std::vector<Clave> claves();
private:
	struct Asociacion{
		Clave clave;
		Valor valor;
	};
    std::vector<Asociacion> asociaciones;
};



#endif /*__DICCIONARIO_H__*/
