#include<iostream>

#include "Software.h"
#include "Juegos.h"
#include "Ofimatica.h"
#include "Usuarios.h"
#include "Administrador.h"
#include "Navegador.h"
#include "Produccion.h"
#include "Seguridad.h"
#include "Social.h"
#include "Nino.h"
#include "UserNormal.h"

#include <vector>
using namespace std;

Usuarios BuscaUser(string user, vector<Usuarios> usuarios)
{
    //Busca el usuario que necesito sino me retorna el admin
     for(int i = 0; i < usuarios.size(); i++)
         {
            if(user == usuarios[i].getUsuario())
            {
                return usuarios[i];
            }
         }
    return usuarios[0];
}
Software* BuscaSoft(string buscado, vector<Software*> softwares)
{
    //me busca el software que necesito y me lo retorna
         for(int i = 0; i < softwares.size(); i++)
         {
            if(buscado == softwares[i] -> getNombre())
            {
                return softwares[i];
            }
         }
    return nullptr;
}

bool EliminarArchivo(string ofimatic, vector<Software*> softwares)
{
    //Le resta 1 a su cantidad
    Software* ofimaticbuscado = BuscaSoft(ofimatic, softwares);
    if(ofimaticbuscado == nullptr)
        {
            cout << "Ingresa un software valido" << endl;
            return false;
        }
    else
    {
    if(ofimaticbuscado -> getNombre() == ofimatic && typeid(*ofimaticbuscado) == typeid(Ofimatica))
    {
       if(Ofimatica* ofimatica = dynamic_cast<Ofimatica*>(ofimaticbuscado))
        {
            ofimatica -> eliminarCantidad();
            cout << "La cantidad actual es: " << endl;
            cout << ofimatica -> getCantidad() << endl;
            return true;
        }
    }
    }
    return false;
}
bool CrearArchivo(string ofimatic, vector<Software*> softwares)
{
    //Me suma 1 a su cantidad
    Software* ofimaticbuscado = BuscaSoft(ofimatic, softwares);
     if(ofimaticbuscado == nullptr)
        {
            cout << "Ingresa un software valido" << endl;
            return false;
        }
    else
    {
        if(ofimaticbuscado -> getNombre() == ofimatic && typeid(*ofimaticbuscado) == typeid(Ofimatica))
    {
       if(Ofimatica* ofimatica = dynamic_cast<Ofimatica*>(ofimaticbuscado))
        {
            ofimatica -> agregarCantidad();
            cout << "La cantidad actual es: " << endl;
            cout << ofimatica -> getCantidad() << endl;
            return true;
        }
    }
    }
    return false;
}
void MostrarListaUsers(string user, vector<Usuarios> usuarios)
{
    //Printea la lista de softwares que tiene cada usuario
    Usuarios usermostrar = BuscaUser(user, usuarios);
    if(usermostrar.getListaSoft().empty())
    {
        cout << "Este User no tiene ningun software" << endl;
    }
    else
    {
        cout << "Los softwares son: " << endl;
        usermostrar.PrintearSoftware();
    }
}
void MostrarListaSoftware(string user, string mostrar,vector<Usuarios> usuarios, vector<Software*>softwares)
{
    //Printea la lista de usuarios que utilizan este software
    Software* softmostrar = BuscaSoft(mostrar, softwares);
    if(softmostrar -> getListaUsuarios().empty())
    {
        cout << "Este software no tiene usuarios" << endl;
    }
    else
    {
        cout << "Los usuarios son: "<< endl;
        softmostrar -> printearUsuarios(); 
    }
    
}

bool EliminarSoftware(string user, string eliminar, vector<Usuarios>usuarios, vector<Software*> softwares)
{
        Software* softbuscado = BuscaSoft(eliminar, softwares);

        if(softbuscado == nullptr)
        {
            cout << "Ingresa un software valido" << endl;
            return false;
        }
        else
        {
            if(softbuscado -> getListaUsuarios().empty())
        {
            cout << "La lista esta vacia por favor agregar software" << endl;
            return false;;
        }
            else
             {
            cout << "Se esta eliminando el software" << endl;
            softbuscado -> eliminarUsuario(user);
            return true;
             }
        }

        return false;
}
bool AgregarSoftware(string user, string agregar, vector<Usuarios>usuarios, vector<Software*> softwares)
{
        //Agregar primero 
        Software* softbuscado = BuscaSoft(agregar, softwares);
        Usuarios userbuscado = BuscaUser(user, usuarios);

        if(softbuscado == nullptr)
        {
            cout << "Ingresa un software valido" << endl;
            return false;
        }
        else
        {
             for(int i = 0; i < usuarios.size(); i++)
        {
            if(user == usuarios[i].getUsuario())
            {
                if(softbuscado -> getEdad() < usuarios[i].getEdad())
                {
                    softbuscado -> agregarUsuarios(usuarios[i]);
                    cout << "Ha sido agregado con exito :D" << endl;
                    userbuscado.agregarSoftware(softbuscado -> getNombre());
                     return true;
                }
                else
                {
                    cout << "El usuario no puede ser agregado porque no cumple la restriccion de edad" << endl;
                    return false;
                }
            }
        }
        }
        return false;
}
void PrintearSoftware(vector<Software*> softwares)
{
    //Me printea todos los software
    cout << "Softwares: " << endl;
    for(int i = 0; i < softwares.size(); i++)
    {
        cout << softwares[i] -> toString() << endl;
    }
    
}
bool Login(string user, string contrasena, vector<Usuarios> usuarios)
{
    for(int i = 0; i < usuarios.size(); i++)
    {
        if(user == usuarios[i].getUsuario() && contrasena == usuarios[i].getContrasena())
        {
            return true;
        }
    }
    return false;
}

int MenuInicial(string user,string contrasena, vector<Usuarios> usuarios, vector<Software*>softwares)
{
   //Menu inicio
    string opcion1;
      cout << "Hola bienvenido al Menu :D" << endl;
      cout << "Que opcion quieres: " << endl;
      cout << "1)Ver Softwares" << endl;
      cout << "2)Agregar Software" << endl;
      cout << "3)Eliminar Software" << endl;
      cout << "4)Ver Software y sus Usuarios" << endl;
      cout << "5)Eliminar Software biblioteca" << endl;
      cout << "6) Crear Archivo" << endl;
      cout << "7) Borrar Archivo" << endl;
      cout << "8) Cerrar sesion" << endl;
      cout << "9) Ver tus softwares" << endl;
      cout <<"10) Salir" << endl;
      cin >> opcion1;

    while(opcion1 != "10")
    {

      if(opcion1 == "1")
      {
        //Me printea todos los softwares que existen
        PrintearSoftware(softwares);
      }

      else if(opcion1 == "2")
      {
        //Agregar software
        string agregar;
        cout << "Ingrese el software a agregar" << endl;
        cin >> agregar;
        bool agregado = AgregarSoftware(user, agregar, usuarios, softwares);
        if (agregado)
        {
            cout << "Fue agregado perfectamente" << endl;
        }
        else
        {
            cout << "Ha ocurrido un error" << endl;
        }
      }
      else if(opcion1 == "3")
      {
        //Eliminar softwares
        string eliminar;
        cout << "Ingrese el software a eliminar" << endl;
        cin >> eliminar;
        bool eliminado = EliminarSoftware(user, eliminar, usuarios, softwares);
        if(eliminado)
        {
            cout << "Todo salio bien" << endl;
        }
        else
        {
            cout << "Ha ocurrido un error" << endl;
        }
      }

      else if(opcion1 == "4")
      {
        //Ver software y sus usuarios 
        string mostrar;
        cout << "Ingrese el software a mostrar" << endl;
        cin >> mostrar;
        MostrarListaSoftware(user, mostrar, usuarios, softwares);
      }
      else if(opcion1 == "5")
      {
        //Eliminar biblioteca
      }
      else if(opcion1 == "6")
      {
        //Sumar archivos
        string ofimatic;
        cout << "Ingrese el Software Ofimatica para agregar cantidad" << endl;
        cin >> ofimatic;
        bool creado = CrearArchivo(ofimatic, softwares); 
        if (creado)
        {
            cout << "Todo fue un exito" << endl;
        }
        else
        {
            cout << "Pruebe de nuevo" << endl;
        }
      }

      else if(opcion1 == "7")
      {
        //Borrar Archivo
        string ofimatic2;
        cout << "Ingrese el Software Ofimatica para borrar cantidad" << endl;
        cin >> ofimatic2;
        bool creado2 = EliminarArchivo(ofimatic2, softwares); 
        if (creado2)
        {
            cout << "Todo fue un exito" << endl;
        }
        else
        {
            cout << "Pruebe de nuevo" << endl;
        }
      }
      else if(opcion1 == "8")
      {
        //cambio de sesion 
        cout << "Ingrese su user: " << endl;
        cin >> user;
        cout << "Ingrese su contrasena: " << endl;
        cin >> contrasena;
        bool ingreso = Login(user, contrasena, usuarios);
        if(ingreso)
        {
            cout << "ingresaste" << endl;
            MenuInicial(user,contrasena, usuarios, softwares);
        }
        else
        {
            cout<<"Vuelve a iniciar sesion por favor" << endl;
        }
      }
      else if(opcion1 == "9")
      {
        //Ver los software que tiene el usuario
        cout << "Aqui estan tus softwares" << endl;
        MostrarListaUsers(user, usuarios);

      }

      cout << "Que opcion quieres: " << endl;
      cout << "1)Ver Softwares" << endl;
      cout << "2)Agregar Software" << endl;
      cout << "3)Eliminar Software" << endl;
      cout << "4)Ver Software y sus Usuarios" << endl;
      cout << "5)Eliminar Software biblioteca" << endl;
      cout << "6) Crear Archivo" << endl;
      cout << "7) Borrar Archivo" << endl;
      cout << "8) Cerrar sesion" << endl;
      cout << "9) Ver tus software" << endl;
      cout <<"10) Salir" << endl;
      cin >> opcion1;

    }
    

    return 0;
}

int main()
{
    //Listas generales para poder despues vincular segun quiera el usuario
    vector<Software*> softwares;
    vector<Usuarios> usuarios;
    //Poblar 15 usuarios 1 admin 4 niños 10 normales
    Administrador s1("Winter","123", 19, "weee");
    usuarios.push_back(s1);
    Nino s2("pepite", "1233", 7);
    usuarios.push_back(s2);
    Nino s3("conan", "lele23", 15);
    usuarios.push_back(s3);
    Nino s4("manty", "juanpere", 10);
    usuarios.push_back(s4);
    Nino s5("xinzao", "lolero12", 12);
    usuarios.push_back(s5);
    UserNormal s6("Shenyugen", "dasha",20, "minusmas");
    usuarios.push_back(s6);
    UserNormal s7("Mandivus", "pokemon", 23, "nosoyoy");
    usuarios.push_back(s7);
    UserNormal s8("Candela", "Serper", 40, "señoritapupou");
    usuarios.push_back(s8);
    UserNormal s9("Martina", "Github12", 32, "tuprincesita");
    usuarios.push_back(s9);
    UserNormal s10("Leon", "memori", 23, "resident");
    usuarios.push_back(s10);
    UserNormal s11("Paule", "profeyameaburri", 19, "salvenme");
    usuarios.push_back(s11);
    UserNormal s12("Cristian", "todomanual", 20, "yabasta");
    usuarios.push_back(s12);
    UserNormal s13("Francisca", "mumu12", 18, "quierovacaciones");
    usuarios.push_back(s13);
    UserNormal s14("Remi", "sucumple", 20, "nosoylaheuRemi");
    usuarios.push_back(s14);
    UserNormal s15("Vicky", "chile12", 45, "Vickyyy");
    usuarios.push_back(s15);

    //Poblar 20 juegos
    Juegos j1("heroes de la galaxia", "winternot", 18, 12000, "MMO");
    softwares.push_back(&j1);
    Juegos j2("starwars", "coke", 40,30000, "FPS");
    softwares.push_back(&j2);
    Juegos j3("lego", "pupu", 7, 5000, "PUZZLE");
    softwares.push_back(&j3);
    Juegos j4("lol", "manuel", 13, 0, "MOBA");
    softwares.push_back(&j4);
    Juegos j5("Overwatch","jeremaye", 12,0,"Shooter");
    softwares.push_back(&j5);
    Juegos j6("Mario wii", "dvnkeo", 15,60000,"Plataforma");
    softwares.push_back(&j6);
    Juegos j7("Mortal Kombet", "jerusalen", 20, 25000, "pelea");
    softwares.push_back(&j7);
    Juegos j8("Mario rpg", "Nintendo", 10, 70000, "RPG");
    softwares.push_back(&j8);
    Juegos j9("GTA 6", "Cj", 19, 80000, "Vandalismo");
    softwares.push_back(&j9);
    Juegos j10("Overcooked","Winter", 20, 10000, "Cooperativo");
    softwares.push_back(&j10);
    Juegos j11("FireEmblen", "winterzt", 4, 12300, "MMO");
    softwares.push_back(&j11);
    Juegos j12("starwars2", "coke", 20,34500, "FPS");
    softwares.push_back(&j12);
    Juegos j13("lego batman", "pupu", 12, 15000, "PUZZLE");
    softwares.push_back(&j13);
    Juegos j14("lol DLC", "Riot", 13, 0, "MOBA");
    softwares.push_back(&j14);
    Juegos j15("Overwatch 2 ","jeremaye", 12,0,"Shooter");
    softwares.push_back(&j15);
    Juegos j16("Mario wii U", "dvnkeo", 15,65000,"Plataforma");
    softwares.push_back(&j16);
    Juegos j17("Mortal Kombet 10", "jerusalen", 20, 30000, "pelea");
    softwares.push_back(&j17);
    Juegos j18("Mario rpg 2", "Nintendo", 12, 75000, "RPG");
    softwares.push_back(&j18);
    Juegos j19("GTA san andrea", "Cj", 19, 800000, "Vandalismo");
    softwares.push_back(&j19);
    Juegos j20("Overcooked 2","Winter", 5, 15000, "Cooperativo");
    softwares.push_back(&j20);

    //Poblar 5 software de ofimatica
    Ofimatica o1("Winterkitchen", "Notsteady", 15, 23000, 5);
    softwares.push_back(&o1);
    Ofimatica o2("Power point", "Epicknmss", 20, 30000, 10);
    softwares.push_back(&o2);
    Ofimatica o3("Sandbox", "minecube", 17, 22000, 132);
    softwares.push_back(&o3);
    Ofimatica o4("Hello Kitty", "Miniso", 32, 1000, 100);
    softwares.push_back(&o4);
    Ofimatica o5("Cinemaroll", "Apple", 18, 43000, 128);
    softwares.push_back(&o5);

    //Poblar 4 software de produccion - only +18
    Produccion p1("New jeans", "bighit", 18, 100000, "Musica");
    softwares.push_back(&p1);
    Produccion p2("Riversgg", "twitch", 20, 3000, "streaming");
    softwares.push_back(&p2);
    Produccion p3("Google fotos", "Camera", 18, 0, "fotos");
    softwares.push_back(&p3);
    Produccion p4("Luisito comunica", "Youtube", 25, 0, "Video");
    softwares.push_back(&p4);
    Produccion p5("Bizzarrap", "Sonic music", 22, 100000, "Musica");
    softwares.push_back(&p5);
    //Poblar 2 software navegadores 
    Navegador n1("History channel", "AE network", 18, 20000);
    softwares.push_back(&n1);
    Navegador n2("Merline", "netflix", 18, 2000);
    softwares.push_back(&n2);

    //Poblar 6 software de seguridad - solo administrador
    Seguridad se1("police", "fbi", 18, 1200, "Ransomware");
    softwares.push_back(&se1);
    Seguridad se2("ninjaspy", "Spyfamily", 20, 38000, "Spyware");
    softwares.push_back(&se2);
    Seguridad se3("robots", "hacker", 22, 50000, "botnets");
    softwares.push_back(&se3);
    Seguridad se4("Hackerss", "hacks", 25, 100000, "rootkits");
    softwares.push_back(&se4);
    Seguridad se5("botanica", "botanikes", 18, 1000, "gusanos");
    softwares.push_back(&se5);
    Seguridad se6("caballeria", "troya", 21, 12000, "troyanos");
    softwares.push_back(&se6);

    //Poblar 2 software social -- 2 amigos por usuario y 1 niños solo amigos niños
    Social so1("Instagram", "Kevin", 7, 20000);
    softwares.push_back(&so1);
    Social so2("Steam", "Rodrigo", 19, 0);
    softwares.push_back(&so2);

    //Iniciar spftware social con "2 amigos por usuario"
    if(so1.getEdad() < s1.getEdad())
    {
        so1.agregarAmigos(s1.getUsuario());
    }
    else
    {
        cout << "No se pudo agregar";
    }

    if(so1.getEdad() < s7.getEdad())
    {
        so1.agregarAmigos(s7.getUsuario());
    }
     else
    {
        cout << "No se pudo agregar";
    }

    if(so2.getEdad() < s8.getEdad())
    {
        so2.agregarAmigos(s8.getUsuario());
    }
    else
    {
        cout << "No se pudo agregar";
    }

    if(so1.getEdad() < s9.getEdad())
    {
        so1.agregarAmigos(s9.getUsuario());
    }
     else
    {
        cout << "No se pudo agregar";
    }
    //despues crear menu login
    bool ingreso = false;
    string user;
    string contrasena;

    while(!ingreso)
    {
        //Se le piden los datos a la persona
        cout << "Ingrese su user: " << endl;
        cin >> user;
        cout << "Ingrese su contrasena: " << endl;
        cin >> contrasena;
        ingreso = Login(user, contrasena, usuarios);
        if(ingreso)
        {
            cout << "ingresaste" << endl;
            MenuInicial(user,contrasena, usuarios, softwares);
        }
        else
        {
            cout<<"Vuelve a iniciar sesion por favor" << endl;
        }
    }
    //finalmente log out con 2 opciones volver a logear o terminar programa
    
    return 0;
}
