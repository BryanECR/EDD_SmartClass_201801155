#include <iostream>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include "ListaDoble.cpp"

using namespace std;

int main(){
    ListaDoblementeEnlazada obj;
    
    obj.agregar(201801155,"cañas","chupar","inicio","hoy","ahorita","ansioso");
    obj.agregar(201801155,"cañas","chupar","segundo","hoy","ahorita","ansioso");
    obj.agregar(201804420,"cañas","chupar","tercero","hoy","ahorita","ansioso");
    obj.agregar(000000000,"cañas","chupar","cuarto","hoy","ahorita","ansioso");
    obj.agregar(202068947,"cañas","chupar","final","hoy","ahorita","ansioso");

    obj.mostrar();
    cout<<endl;
    obj.ModificarNodo(4);
    cout<<endl;
    obj.mostrar();
    return 0;
}