#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Nodo{
    public:
        Nodo* izq;
        int carnet;
        int dpi;
        string nombre;
        string carrera;
        string password;
        int creditos;
        int edad;
        Nodo* der;
};