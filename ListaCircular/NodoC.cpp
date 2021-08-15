#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class NodoC{
    public:
        NodoC* izq;
        int carnet;
        long long int dpi;
        string nombre;
        string carrera;
        string password;
        int creditos;
        int edad;
        string correo;
        NodoC* der;
};