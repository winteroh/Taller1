#pragma once
#include <iostream>
#include <vector>
#include "Software.h"

using namespace std;

class Usuarios
{
    private:
    string usuario;
    string contrasena;
    int edad;
    vector <string> listaSoftwares; // del user

    public:
    Usuarios(string usuario, string contrasena, int edad);
    string getUsuario();
    string getContrasena();
    int getEdad();
    void agregarSoftware(string);
    void PrintearSoftware();
    vector <string >getListaSoft();
    //metodos para comprobar si soy admin o que tipo soy

    virtual bool tengoAcceso();
    virtual bool edadReq();
};

Usuarios :: Usuarios(string usuario, string contrasena, int edad)
{
    this-> usuario = usuario;
    this -> contrasena = contrasena;
    this->edad = edad;
}

bool Usuarios :: tengoAcceso()
{
    return false;
}
bool Usuarios :: edadReq()
{
    return false;
}

string Usuarios :: getUsuario()
{
    return this -> usuario;
}

string Usuarios :: getContrasena()
{
    return this -> contrasena;
}

int Usuarios :: getEdad()
{
    return this -> edad;
}
void Usuarios :: agregarSoftware(string nombresoftware)
{
    listaSoftwares.push_back(nombresoftware);
}
void Usuarios :: PrintearSoftware()
{
    for(int i = 0; i < listaSoftwares.size(); i++)
    {
            cout << listaSoftwares[i] << endl;
    }
}
vector<string> Usuarios :: getListaSoft()
{
    return this -> listaSoftwares;
}