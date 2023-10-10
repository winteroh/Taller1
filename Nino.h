#pragma once
#include <iostream>
#include "Usuarios.h"

using namespace std;

class Nino : public Usuarios
{
    private:
    public:
    Nino(string usuario, string contraseña, int edad);
    bool tengoAcceso() override;
    bool edadReq() override;

};

Nino :: Nino(string usuario, string contraseña, int edad):Usuarios(usuario,contraseña,edad)
{
}

bool Nino :: tengoAcceso() 
{
    return false;
}

bool Nino :: edadReq()
{
    return false;
}