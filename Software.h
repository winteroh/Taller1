#pragma once
#include <iostream>
#include <vector>
#include "Usuarios.h"

using namespace std;

class Software
{
    private:
    string nombre;
    string developer;
    int edad;
    vector<Usuarios> listausuarios;
    int precio;
    public:
    Software(string nombre, string developer, int edad, int precio);
    string getNombre();
    string getDeveloper();
    int getEdad();
    int getPrecio();
    vector<Usuarios> getListaUsuarios();
    void agregarUsuarios(Usuarios);
    void eliminarUsuario(string);
    void printearUsuarios();
    virtual string toString();
};

Software :: Software(string nombre, string developer, int edad, int precio)
{
    this-> nombre = nombre;
    this -> developer = developer;
    this->edad = edad;
    this-> precio = precio;
    this -> listausuarios;
}
vector<Usuarios> Software :: getListaUsuarios()
{
    return this -> listausuarios;
}
void Software :: printearUsuarios()
{
    for(int i = 0; i < listausuarios.size(); i++)
    {
            cout << listausuarios[i].getUsuario() << endl;
    }
}
void Software :: eliminarUsuario(string usuario)
{
    for (int i = 0; i < listausuarios.size(); i++) 
    {
        if (listausuarios[i].getUsuario() == usuario)
        {
            listausuarios.erase(listausuarios.begin() + i);
            break; 
        }
    }
}

void Software :: agregarUsuarios(Usuarios user)
{
    listausuarios.push_back(user);
}
string Software :: getNombre()
{
   return this -> nombre;
}
int Software :: getEdad()
{
    return this -> edad;
}
string Software :: getDeveloper()
{
    return this -> developer;
}

string Software::toString()
{
    return "Nombre : " + nombre + ", Developer: " + developer + ",Restriccion de edad: " + to_string(edad) + ", Precio: " + to_string(precio);
}