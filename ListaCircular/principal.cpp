#include <iostream>
#include "ListaCircular.cpp"
using namespace std;

int main(){
    ListaCirculasDoblementeEnlazada obj;

    obj.agregar(201801155,321654987,"Bryan Eduardo Caal Racanac","Ingenieria en sistemas","Bryanecr1234",72,22,"@kajsdkljasd");
    obj.agregar(201801155,741258963,"Bryan Eduardo Caal Racanac","Ingenieria en sistemas","Bryanecr1234",72,22,"@kajsdkljasd");
    obj.agregar(201801155,369852147,"Bryan Eduardo Caal Racanac","Ingenieria en sistemas","Bryanecr1234",72,22,"@kajsdkljasd");
    obj.agregar(201801155,100000001,"Bryan Eduardo Caal Racanac","Ingenieria en sistemas","Bryanecr1234",72,22,"@kajsdkljasd");
    obj.mostrar();
    cout<<endl;

    obj.graficar(1);


    return 0;
}