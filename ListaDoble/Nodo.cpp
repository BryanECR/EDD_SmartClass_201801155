#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Nodo{
    public:
        Nodo* izq;
        int carnet;
        string nombre;
        string descripcion;
        string materia;
        string fecha;
        string hora;
        string estado;
        Nodo* der;
};