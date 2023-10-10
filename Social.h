#pragma once
#include <iostream>
#include "Software.h"
#include "Usuarios.h"
#include <vector>
using namespace std;

class Social : public Software
{
    private:
    vector<string> listaAmigos;
    public:
    Social(string nombre, string developer, int edad, int precio);
    void agregarAmigos(string);
    void printearAmigos();
};

Social :: Social(string nombre, string developer, int edad, int precio) : Software(nombre, developer, edad, precio)
{
}

void Social :: agregarAmigos(string amigue)
{
    listaAmigos.push_back(amigue);
}

void Social :: printearAmigos()
{
    for(int i = 0; i < listaAmigos.size(); i++)
    {
            cout << listaAmigos[i] << endl;
    }
}