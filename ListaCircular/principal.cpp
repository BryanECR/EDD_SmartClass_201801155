#include <iostream>
#include "ListaCircular.cpp"
using namespace std;

int main(){
    ListaCirculasDoblementeEnlazada obj;

    std::string email = "usuario@gmail.com";
    std::string email2 = "usua_rio@gmail.gt";
    std::string email3 = "usua*rio@gmail.nice";
    std::string email4 = "usuario@hotmail.es";

    int q = obj.validarCorreo(email);
    cout<<q;
    q = obj.validarCorreo(email2);
    cout<<q;
    q = obj.validarCorreo(email3);
    cout<<q;
    q = obj.validarCorreo(email4);
    cout<<q;



    return 0;
}