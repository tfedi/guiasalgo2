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


#endif

#if EJ >= 6
TEST(diccionario, ej6_claves){
    std::vector<Clave> keys = {1,2,3,4,5,6,7,8};
    std::vector<Clave> keys2 = {2,1,4,5,6,8,3,7};
    std::vector<Clave> keys3 = {};
    std::vector<Clave> keys4 = {};
    std::vector<Clave> keys5 = {5,3,4};

    ASSERT_EQ(esPermutacion(keys,keys2),true);
    ASSERT_EQ(esPermutacion(keys3,keys4),true);
    ASSERT_EQ(esPermutacion(keys3,keys5),false);
    ASSERT_EQ(esPermutacion(keys,keys5),false);
}

#endif

#if EJ >= 7

TEST(diccionario,ej7_igualdad){
    Diccionario diccionario2;
    diccionario2.definir(1,4);
    diccionario2.definir(2,5);
    diccionario2.definir(6,6);
    Diccionario diccionario;
    diccionario.definir(2,6);
    diccionario.definir(6,4);
    diccionario.definir(1,5);
    Diccionario diccionario3;
    diccionario3.definir(2,0);
    diccionario3.definir(6,1);
    diccionario3.definir(1,7);
    ASSERT_EQ(diccionario == diccionario2,true);
    ASSERT_EQ(diccionario == diccionario3,false);
}

#endif

#if EJ >= 8

#endif

