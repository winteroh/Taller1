#pragma once
#include <iostream>
#include "Software.h"

using namespace std;

class Produccion : public Software
{
    private:
    string solucion;
    public:
    Produccion(string nombre, string developer, int edad, int precio, string solucion);
    string getSolucion();
    void setSolucion(string);
};

Produccion :: Produccion(string nombre, string developer, int edad, int precio, string solucion) : Software(nombre, developer, edad, precio)
{
    this -> solucion = solucion;
}

string Produccion :: getSolucion()
{
    return this -> solucion;
}

void Produccion :: setSolucion(string solucion)
{
    this -> solucion = solucion;
}