#include "gtest-1.8.1/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}
#endif

#if EJ >= 5

TEST(diccionario, ej5_borrar){
    Diccionario diccionario2;
    diccionario2.definir(1,4);
    diccionario2.definir(2,5);
    diccionario2.borrar(1);
    ASSERT_EQ(diccionario2.def(1),false);
    ASSERT_EQ(diccionario2.def(2),true);
    ASSERT_EQ(diccionario2.obtener(2),5);
    diccionario2.borrar(7);
    ASSERT_EQ(diccionario2.def(2),true);
}

// Completar para el ejercicio 5

#endif

#if EJ >= 6

// Completar para el ejercicio 6

#endif

#if EJ >= 7

// Completar para el ejercicio 7

#endif

#if EJ >= 8

#endif

