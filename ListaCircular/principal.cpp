#include <iostream>
#include "ListaCircular.cpp"
using namespace std;

int main(){
    ListaCirculasDoblementeEnlazada obj;

    int q = obj.validarCarnetDpi(201801155);
    cout<<q;
    q = obj.validarCarnetDpi(36296350115);
    cout<<q;
    q = obj.validarCarnetDpi(201801);
    cout<<q;
    q = obj.validarCarnetDpi(3629635920115);
    cout<<q;

    return 0;
}