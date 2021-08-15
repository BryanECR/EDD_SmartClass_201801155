#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Nodo{
    public:
        Nodo* izq;
        int mes;
        int dia;
        int hora;
        int carnet;
        string nombre;
        string descripcion;
        string materia;
        string fecha;
        string estado;
        Nodo* der;
};