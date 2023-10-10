#pragma once
#include <iostream>
#include "Software.h"

using namespace std;

class Juegos : public Software
{
    private:
    string genero;
    public:
    Juegos(string nombre, string developer, int edad, int precio, string genero);
    string getGenero();
    void setGenero(string);
};

Juegos :: Juegos(string nombre, string developer, int edad, int precio, string genero):Software(nombre,developer,edad,precio)
{
    this -> genero = genero;
}

string Juegos :: getGenero()
{
    return this -> genero;
}
void Juegos :: setGenero(string genero)
{
    this -> genero = genero;
}