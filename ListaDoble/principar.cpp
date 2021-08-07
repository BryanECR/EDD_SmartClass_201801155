#include <iostream>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "ListaDoble.cpp"

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    ListaDoblementeEnlazada obj;
    

    obj.agregar(201801155,"Bryan Eduardo Caal Racanac","P1","EDD","6/08/2021","22:39","Pendiente");
    obj.agregar(201801155,"Bryan Eduardo Caal Racanac","P1","OC1","21/09/2021","00:00","Incumplido");
    obj.agregar(201801155,"Bryan Eduardo Caal Racanac","Tarea","Apli 1","18/08/2021","10:40","Medio Realizado");
    obj.agregar(201801155,"Bryan Eduardo Caal Racanac","mimir","Nada","6/08/2021","22:39","Realizado");
    obj.agregar(201801155,"Bryan Eduardo Caal Racanac","hoja 2","IO1","8/10/2021","12:00","Realizado");
    obj.mostrar();   
    obj.borrarElemento(5);
    cout<<endl;
    obj.ModificarNodo(3);
    obj.mostrar();

    



    return 0;
}