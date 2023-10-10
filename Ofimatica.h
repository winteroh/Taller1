#pragma once
#include <iostream>
#include "Software.h"

using namespace std;

class Ofimatica : public Software
{
    private:
    int cantidad;
    public:
    Ofimatica(string nombre, string developer, int edad, int precio, int cantidad);
    int getCantidad();
    void setCantidad(int);
    void agregarCantidad();
    void eliminarCantidad();
};

Ofimatica :: Ofimatica(string nombre, string developer, int edad, int precio, int cantidad) : Software(nombre, developer, edad, precio)
{
    this -> cantidad = cantidad;
}

int Ofimatica :: getCantidad()
{
    return this -> cantidad;
}

void Ofimatica :: setCantidad(int cantidad)
{
    this -> cantidad = cantidad;
}

void Ofimatica :: agregarCantidad()
{
    this -> cantidad = cantidad + 1;
}

void Ofimatica :: eliminarCantidad()
{
    this -> cantidad = cantidad - 1;
}