#include <iostream>
#include <fstream>
#include "NodoS.cpp"

using namespace std;

class ListaSimple{
    private:
        NodoSimple* inicio;
        NodoSimple* fin; 
    public:
        ListaSimple(){
            inicio = NULL;
            fin = NULL;
        }

    void agregar(int carnet, string tipo, string descripcion){
        NodoSimple* nuevo = new NodoSimple();
        nuevo->carnet = carnet;
        nuevo->tipo = tipo;
        nuevo->descripcion = descripcion;

        if(inicio == NULL){
            inicio = nuevo;
            inicio->sig = NULL;
            fin = inicio;
        }else{
            fin->sig = nuevo;
            nuevo->sig = NULL;
            fin = nuevo;
        }
    }

    void mostrar(){
        NodoSimple* actual = new NodoSimple();
        actual = inicio;
        int contador = 1;
        if(inicio != NULL){
            while(actual != NULL){
                cout<<"ID: "+to_string(contador)+"\nTipo: "+actual->tipo+"\nCarnet: "+to_string(actual->carnet)+"\nDescripcion: "+actual->descripcion+"\n";
                contador+=1;
                actual = actual->sig;
            }
        }else{
            cout<<"la lista esta vacia\n";
        }
    }

    void graficar(){
        NodoSimple* actual = new NodoSimple();
        actual = inicio;
        string texto = "";
        int contador = 0;
        if(inicio != NULL){
            while(actual != NULL){
                texto += "\tnodo"+to_string(contador)+"[shape=box label=\"ID: "+to_string(contador+1)+"\nTipo: "+actual->tipo+"\nCarnet: "+to_string(actual->carnet)+"\nDescripcion: "+actual->descripcion+"\"];\n";
                actual = actual->sig;
                contador+=1;
            }
        }else{
            cout<<"la lista esta vacia\n";
        }

        for(int i = 0; i<contador; i++){
            if(i == 0){
                texto+="\tnodo"+to_string(i);
            }else{
                texto+="-> nodo"+to_string(i);
            }
        }

        // Archivo de texto para escribir el .dot
        ofstream archivo;
        archivo.open("GraficaErrores.dot",ios::out);

        if(archivo.fail()){
            cout<<"No se pudo abrir el archivo";
            exit(1);
        }

        archivo<<"digraph G {\n"+texto+"\n}";
        archivo.close();
        system("dot -Tpng GraficaErrores.dot -o GraficaErrores.png");
    }

    bool vacia(){
        if(inicio==NULL){
            return true;
        }
        return false;
    }

    void eliminar(){
        if(inicio==NULL){
            cout<<"La lista esta vacia"<<endl;
        }else{
            inicio = inicio->sig;
            cout<<"Se elimino el primer error"<<endl;
        }
    }
};

