#pragma once
#include <iostream>
#include "Usuarios.h"

using namespace std;

class Administrador : public Usuarios
{
    private:
    string correo;
    public:
    Administrador(string usuario, string contrasena, int edad, string correo);
    bool tengoAcceso() override;
    bool edadReq() override;

};

Administrador :: Administrador(string usuario, string contrasena, int edad, string correo):Usuarios(usuario,contrasena,edad)
{
    this -> correo = correo;
}

bool Administrador :: tengoAcceso() 
{
    return true;
}

bool Administrador :: edadReq()
{
    return true;
}
