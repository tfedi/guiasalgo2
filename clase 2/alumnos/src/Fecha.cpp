//////////////
// PRELUDIO //
//////////////

// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;

// Ejercicio 1: esBisiesto
bool esDivisiblePor(int n, int m){
  return n%m == 0;
}
bool esBisiesto(Anio anio) {
  return esDivisiblePor(anio,4) and (!esDivisiblePor(anio,100) or esDivisiblePor(anio,400));
}

// Ejercicio 2: diasEnMes
int diasEnMes(Anio anio, Mes mes){
  int res = 0;
  switch (mes){
      case ENERO:
      case MARZO:
      case MAYO:
      case JULIO:
      case AGOSTO:
      case OCTUBRE:
      case DICIEMBRE:
        res = 31;
        break;
      case ABRIL:
      case JUNIO:
      case SEPTIEMBRE:
      case NOVIEMBRE:
        res = 30;
        break;
      case FEBRERO:
        res = esBisiesto(anio) ? 29 : 28;
  }
  return res;
}

// Para ejercicio 6
class Periodo;
class Intervalo;
class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;

  // Ejercicio 7: sumar período a fecha
  void sumar_periodo(Periodo p);
 private:
  Anio _anio;
  Mes _mes; 
  Dia _dia;

  // Ejercicio 7: sumar a fecha
  void sumar_anios(int anios);
  void sumar_meses(int meses);
  void sumar_dias(int dias);
};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia) {
    _anio = anio;
    _mes = mes;
    _dia = dia;
}

Anio Fecha::anio() const {
    return _anio;
}

Mes Fecha::mes() const {
    return _mes;
}

Dia Fecha::dia() const {
    return _dia;
}


// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
    return _anio == o.anio() && _mes == o.mes() && _dia == o.dia();
}

bool Fecha::operator<(Fecha o) const {
    return  _anio < o.anio() ||
            (_anio == o.anio() && _mes < o.mes()) ||
            (_anio == o.anio() && _mes == o.mes() && _dia < o.dia());
}


// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
    return !(f1 == f2);
}

// Ejercicio 6: clase período
class Periodo {
private:
    int _anios;
    int _meses;
    int _dias;
public:
    Periodo(int anios, int meses, int dias);
    int anios() const;
    int meses() const;
    int dias() const;
};

Periodo::Periodo(int anios, int meses, int dias){
    _anios = anios;
    _meses = meses;
    _dias = dias;
}

int Periodo::anios() const {
    return _anios;
}

int Periodo::meses() const {
    return _meses;
}

int Periodo::dias() const {
    return _dias;
}


// Ejercicio 7: implementaciones de funciones
void Fecha::sumar_anios(int anios){
    _anio += anios;
}
void Fecha::sumar_meses(int meses) {
    if (meses == 0){
        //skip.
    }
    else if(meses % 12 == 0){
        sumar_anios(meses/12);
    }
    else{
        while (meses > 0) {
            if (_mes == 12) {
                sumar_anios(1);
                _mes = 1;
            }
            else{
                _mes++;
            }
            meses--;
        }
    }
}
void Fecha::sumar_dias(int dias) {
    if (dias == 0){
        //skip.
    }
    else if (dias % 365 == 0){
        sumar_anios(dias/365);
    }
    else{
        int dias_restantes = _dia + dias;
        int dias_en_mes = diasEnMes(_anio,_mes);

        while(dias_restantes > dias_en_mes){
            sumar_meses(1);
            dias_restantes -= dias_en_mes;
            dias_en_mes = diasEnMes(_anio,_mes);
        }
        _dia = dias_restantes;
    }

}
void Fecha::sumar_periodo(Periodo p) {
    sumar_anios(p.anios());
    sumar_meses(p.meses());
    sumar_dias(p.dias());
}

// Ejercicio 8: clase Intervalo
class Intervalo{
private:
    Fecha _desde;
    Fecha _hasta;
public:
    Intervalo(Fecha desde, Fecha hasta);
    Fecha desde() const;
    Fecha hasta() const;
    int enDias() const;
};

Intervalo::Intervalo(Fecha desde, Fecha hasta) : _desde(desde), _hasta(hasta) {}

Fecha Intervalo::desde() const {
    return _desde;
}

Fecha Intervalo::hasta() const {
    return _hasta;
}

int Intervalo::enDias() const {
    int cant_dias = 0;
    Fecha desde_aux = _desde, hasta_aux = _hasta;
    while (desde_aux != hasta_aux){
        desde_aux.sumar_periodo(Periodo(0,0,1));
        cant_dias++;
    }
    return cant_dias;
}