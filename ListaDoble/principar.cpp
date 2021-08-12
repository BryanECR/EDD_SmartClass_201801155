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
    
    /*
    obj.agregar(7,8,9,201801155,"Bryan Eduardo Caal Racanac","1","EDD","6/08/2021","Pendiente");
    obj.agregar(1,2,3,201801155,"Bryan Eduardo Caal Racanac","2","EDD","6/08/2021","Pendiente");
    obj.agregar(4,5,6,201801155,"Bryan Eduardo Caal Racanac","3","EDD","6/08/2021","Pendiente");
    obj.agregar(9,8,7,201801155,"Bryan Eduardo Caal Racanac","4","EDD","6/08/2021","Pendiente");
    obj.agregar(3,2,1,201801155,"Bryan Eduardo Caal Racanac","5","EDD","6/08/2021","Pendiente");
    obj.agregar(6,5,4,201801155,"Bryan Eduardo Caal Racanac","6","EDD","6/08/2021","Pendiente");
    obj.agregar(1,5,9,201801155,"Bryan Eduardo Caal Racanac","7","EDD","6/08/2021","Pendiente");
    obj.agregar(7,5,3,201801155,"Bryan Eduardo Caal Racanac","8","EDD","6/08/2021","Pendiente");
    obj.agregar(1,5,3,201801155,"Bryan Eduardo Caal Racanac","9","EDD","6/08/2021","Pendiente");
    obj.agregar(7,2,9,201801155,"Bryan Eduardo Caal Racanac","10","EDD","6/08/2021","Pendiente");

    obj.graficar(1);
    */

    int res = obj.validarFechas(10,"mes");
    cout<<res<<endl;
    res = obj.validarFechas(31,"dia");
    cout<<res<<endl;
    res = obj.validarFechas(13,"hora");
    cout<<res<<endl;
    
    return 0;
}