#pragma once
#include <iostream>
#include "Software.h"
#include <vector>
using namespace std;

class Navegador : public Software
{
    private:
    vector<string> historial;
    public:
    Navegador(string nombre, string developer, int edad, int precio);
    void agregarHistorial(string);
    void printearHistorial();
        
};

Navegador :: Navegador(string nombre, string developer, int edad, int precio) : Software(nombre,developer,edad,precio)
{
}

void Navegador :: agregarHistorial(string pagina)
{   
   historial.push_back(pagina);
}

void Navegador :: printearHistorial()
{
    for(int i = 0; i < historial.size(); i++)
    {
            cout << historial[i] << endl;
    }
}

