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
	std::vector<Clave> claves() const;
	std::vector<Valor> valores() const;
	bool operator==(Diccionario o) const;

private:
	struct Asociacion{
		Clave clave;
		Valor valor;
	};
    std::vector<Asociacion> asociaciones;
};

int maximaClave(std::vector<Clave> v1);
int minimaClave(std::vector<Clave> v1);
bool todosCero(std::vector<int> v);
bool auxPermutacion(std::vector<Clave> v1, std::vector<Clave> v2);
bool esPermutacion(std::vector<Clave> v1, std::vector<Clave> v2);


#endif /*__DICCIONARIO_H__*/
