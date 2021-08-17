#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void graficar(int numero, string cadena){
    ofstream archivo;
        archivo.open("Estudiantes.txt",ios::out);

        if(archivo.fail()){
            cout<<"No se pudo abrir el archivo";
            exit(1);
        }

        archivo<<cadena;
        archivo.close();
}

int main(){
    string texto;
    int numero;

    for(int k=0; k<2; k++){
        texto+="digraph G{\n\tnode [shape=square]\n\ta0 [label=<\n\t\t<TABLE>\n";
        for(int j=0; j<2; j++){
            texto+="\t\t\t<TR>\n";
            for(int i=0; i<2; i++){
                texto+="\t\t\t<TD>00</TD>\n";
            }
            texto+="\t\t\t</TR>\n";
        }
        texto+="\t\t</TABLE>>];\n}\n";
        cout<<texto;
    }
    

    return 0;
}