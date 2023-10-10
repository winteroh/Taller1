#pragma once
#include <iostream>
#include "Usuarios.h"

using namespace std;

class UserNormal : public Usuarios
{
    private:
    string correo;
    public:
    UserNormal(string usuario, string contraseña, int edad, string correo);
    bool tengoAcceso() override;
    bool edadReq() override;

};

UserNormal :: UserNormal(string usuario, string contraseña, int edad, string correo):Usuarios(usuario,contraseña,edad)
{
    this -> correo = correo;
}

bool UserNormal :: tengoAcceso() 
{
    return false;
}

bool UserNormal :: edadReq()
{
    return true;
}