#include <iostream>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include "ListaDoble.cpp"

using namespace std;

int main(){
    ListaDoblementeEnlazada obj;
    
    obj.agregar(201801155,"cañas","chupar","inicio","hoy","ahorita","ansioso");
    obj.agregar(201801155,"cañas","chupar","ninguna","hoy","ahorita","ansioso");
    obj.agregar(201801155,"cañas","chupar","ninguna","hoy","ahorita","ansioso");
    obj.agregar(201801155,"cañas","chupar","ninguna","hoy","ahorita","ansioso");
    obj.agregar(201801155,"cañas","chupar","final","hoy","ahorita","ansioso");

    obj.mostrar();

    int ta = obj.sizeDeLaLista();
    cout<<endl<<ta<<endl;

    return 0;
}