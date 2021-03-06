#include <iostream>
#include "NodoC.cpp"
#include <fstream>
#include <regex>

using namespace std;

class ListaCirculasDoblementeEnlazada{
    private:
        NodoC* inicio;
        NodoC* fin;
    public:
        ListaCirculasDoblementeEnlazada(){
            inicio = NULL;
            fin = NULL;
        }

    void agregar(int carnet,long long int dpi,string nombre,string carrera,string password,int creditos,int edad,string correo){
        NodoC* nuevo = new NodoC();
        nuevo->carnet = carnet;
        nuevo->dpi = dpi;
        nuevo->nombre = nombre;
        nuevo->carrera = carrera;
        nuevo->password = password;
        nuevo->creditos = creditos;
        nuevo->edad = edad;
        nuevo->correo = correo;

        if(inicio == NULL){
            inicio = nuevo;
            inicio->der=inicio;
            inicio->izq=inicio;
            fin=inicio;
            
        }else{
            fin->der=nuevo;
            nuevo->der=inicio;
            nuevo->izq=fin;
            fin=nuevo;
            inicio->izq=fin;

        }
        
    }

    void mostrar(){
        NodoC* actual = new NodoC();
        actual = inicio;
        if(inicio==NULL){
            cout<<"la lista esta vacia"<<endl;
        }else{
            do{
                cout<<actual->carnet<<"\t";
                cout<<actual->dpi<<"\t";
                cout<<actual->nombre<<"\t";
                cout<<actual->carrera<<"\t";
                cout<<actual->password<<"\t";
                cout<<actual->creditos<<"\t";
                cout<<actual->edad<<endl;
                cout<<actual->correo<<endl;
                actual=actual->der;
            }while(actual != inicio);
        }
    }

    string tareaRealizada(string tarea){
        if(tarea == "eliminar"){
            return "Estudiante eliminado con exito";
        }
        return "Datos modificados con exito";
        
    }

    int datosParaModificar(){
        int opcion;
        cout<<" ********** DATOS DEL ESTUDIANTE PARA MODIFICAR **********  \n";
        cout<<"                     1- Carnet\n";
        cout<<"                     2- DPI\n";
        cout<<"                     3- Nombre\n";
        cout<<"                     4- Carrera\n";
        cout<<"                     5- Password\n";
        cout<<"                     6- Creditos\n";
        cout<<"                     7- Edad\n";
        cout<<"                     8- Correo\n";
        cout<<"Ingrese la Opcion que desea modificar: ";
        cin>>opcion;
        return opcion;
    }

    void modificarEstudiante(long long int dpi){
        int opcion;
        int carnetNuevo;
        long long int dpiNuevo;
        string nombreNuevo;
        string carreraNuevo;
        string passwordNuevo;
        int creditosNuevo;
        int edadNuevo;
        string correoNuevo;

        if(inicio == NULL){
            cout<<"La lista se encuantra vacia"<<endl;

        }else{
            NodoC* actual = inicio;
            opcion = datosParaModificar();

            do{
                if(dpi == actual->dpi){
                    switch(opcion){
                    case 1:
                        cout<<"Ingrese el nuevo carnet: ";
                        cin>>carnetNuevo;
                        if(validarCarnetDpi(carnetNuevo)==1){
                            actual->carnet = carnetNuevo;
                            cout<<tareaRealizada("a");
                        }else{
                            cout<<"\n               ??DATOS NO MODIFICADOS!\n";
                            cout<<"** el numero de carnet no cumple con la longitud establecida ** \n";
                        }
                        

                     break;
                    case 2:
                        cout<<"Ingrese el nuevo DPI: ";
                        cin>>dpiNuevo;
                        if(validarCarnetDpi(carnetNuevo)==1){
                            actual->dpi = dpiNuevo;
                            cout<<tareaRealizada("a");
                        }else{
                            cout<<"\n               ??DATOS NO MODIFICADOS!\n";
                            cout<<"** el numero de DPI no cumple con la longitud establecida ** \n";
                        }
                        

                     break;
                    case 3:
                        cout<<"Ingrese el nuevo nombre: ";
                        cin>>nombreNuevo;
                        actual->nombre = nombreNuevo;
                        cout<<tareaRealizada("a");

                     break;
                    case 4:
                        cout<<"Ingrese la nueva carrera: ";
                        cin>>carreraNuevo;
                        actual->carrera = carreraNuevo;
                        cout<<tareaRealizada("a");

                     break;
                    case 5:
                        cout<<"Ingrese el nuevo password: ";
                        cin>>passwordNuevo;
                        actual->password = passwordNuevo;
                        cout<<tareaRealizada("a");

                     break;
                    case 6:
                        cout<<"Ingrese el nuevo numero de creditos: ";
                        cin>>creditosNuevo;
                        actual->creditos = creditosNuevo;
                        cout<<tareaRealizada("a");

                     break;
                    case 7:
                        cout<<"Ingrese la nueva edad: ";
                        cin>>edadNuevo;
                        actual->edad = edadNuevo;
                        cout<<tareaRealizada("a");

                     break;
                    case 8:
                        cout<<"Ingrese el nuevo Correo: ";
                        cin>>correoNuevo;
                        if(validarCorreo(correoNuevo)==1){
                            actual->correo = correoNuevo;
                            cout<<tareaRealizada("a");
                        }else{
                            cout<<"\n               ??DATOS NO MODIFICADOS!\n";
                            cout<<" ** El correo nuevo no cumple con la estructura establecida ** \n";
                        }
                        
                     break;
                    }
                    break;
                }
                actual = actual->der;
            }while(actual != inicio);
        }
    }

    void eliminarEstudiante(long long int dpi){
        if(inicio == NULL){
            cout<<"La lista esta vacia"<<endl;

        }else if(inicio->dpi == dpi){
            NodoC* borrarInicio = inicio;
            inicio = inicio->der;
            inicio->izq == fin;
            cout<<tareaRealizada("eliminar");
            delete borrarInicio;

        }else if(fin->dpi == dpi){
            NodoC* borrarFin = fin;
            fin = fin->izq;
            fin->der = inicio;
            cout<<tareaRealizada("eliminar");
            delete borrarFin;

        }else{
            NodoC* actual = inicio;
            NodoC* anterior;
            NodoC* siguiente;
            NodoC* borrar;

            do{
                if(actual->dpi == dpi){
                    anterior=actual->izq;
                    siguiente=actual->der;
                    borrar = actual;
                    anterior->der = siguiente;
                    siguiente->izq = anterior;
                    cout<<tareaRealizada("eliminar");
                    delete borrar;
                    break;
                }
                actual = actual->der;
            }while(actual != inicio);
        }
    }

    void graph(int numero,string cadena, int gra){
        string nombredelagrafica = "Estudiantes"+to_string(numero)+to_string(gra);
        ofstream archivo;
        archivo.open(nombredelagrafica+".dot",ios::out);

        if(archivo.fail()){
            cout<<"No se pude abrir el archivo";
            exit(1);
        }

        archivo<<cadena;
        archivo.close();
        std::string str = "dot -Tpng "+nombredelagrafica+".dot -o "+nombredelagrafica+".png";
        const char *cstm = str.c_str();
        system(cstm);
        cout<<"\n??Grafica realizada con exito!\n";

    }

    void crearTabla(int gra){
        NodoC* actual = new NodoC();
        actual = inicio;
        int contador = 1;
        int numero = 0;
        string texto = "digraph G{\n\ta0[shape=square label=<\n\t\t<TABLE border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n";

        if(inicio==NULL){
            cout<<"la lista esta vacia"<<endl;
        }else{

            do{
                if((contador%50)!=0){
                    texto+="\t\t\t<TR>\n";
                    texto+="\t\t\t<TD border=\"1\">"+to_string(actual->carnet)+"</TD>\n";
                    texto+="\t\t\t<TD border=\"1\">"+to_string(actual->dpi)+"</TD>\n";
                    texto+="\t\t\t<TD border=\"1\">"+actual->nombre+"</TD>\n";
                    texto+="\t\t\t<TD border=\"1\">"+actual->carrera+"</TD>\n";
                    texto+="\t\t\t<TD border=\"1\">"+actual->password+"</TD>\n";
                    texto+="\t\t\t<TD border=\"1\">"+to_string(actual->creditos)+"</TD>\n";
                    texto+="\t\t\t<TD border=\"1\">"+to_string(actual->edad)+"</TD>\n";
                    texto+="\t\t\t<TD border=\"1\">"+actual->correo+"</TD>\n";
                    texto+="\t\t\t</TR>\n";
                    
                }else{
                    texto+="\t\t</TABLE>>];\n}\n";
                    graph(numero,texto,gra);
                    texto ="digraph G{\n\ta0[shape=square label=<\n\t\t<TABLE border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n";
                    numero++;
                }
                actual=actual->der;
                contador++;
            }while(actual != inicio);
        }
    }

    int validarCarnetDpi(long long int numero){
        string cadena = to_string(numero);
        int tama??o = cadena.size();
        if(tama??o == 13 || tama??o == 9){
            return 1;
        }
        return 0;
    }

    int validarCorreo(const std::string& email){
        const std::regex pattern
            ("[\\w]+@[\\w]+\\.[cmesorg]{2,3}");

        if(std::regex_match(email, pattern)){
            return 1;
        }
        return 0;
        
    }

    bool buscarEstudiantes(long long int depei){
        NodoC* actual = new NodoC();
        actual = inicio;
        if(inicio==NULL){
            return false;
        }

        do{
            if(actual->dpi == depei){
                return true;
            }
            actual=actual->der;
        }while(actual != inicio);
        return false;
    }

    bool buscarPorCarnet(int carnet){
        NodoC* actual = new NodoC();
        actual = inicio;
        if(inicio==NULL){
            return false;
        }

        do{
            if(actual->carnet == carnet){
                return true;
            }
            actual=actual->der;
        }while(actual != inicio);
        return false;
    }

    string Salida(){
        NodoC* actual = inicio;
        string salida="";
        do{
            salida += "\n\t??element type=\"user\"?\n";
            salida += "\t\t??item Carnet: \""+to_string(actual->carnet)+"\" $?\n";
            salida += "\t\t??item DPI: \""+to_string(actual->dpi)+"\" $?\n";
            salida += "\t\t??item Nombre: \""+actual->nombre+"\" $?\n";
            salida += "\t\t??item Carrera: \""+actual->carrera+"\" $?\n";
            salida += "\t\t??item Password: \""+actual->password+"\" $?\n";
            salida += "\t\t??item Creditos: "+to_string(actual->creditos)+" $?\n";
            salida += "\t\t??item Edad: "+to_string(actual->edad)+" $?\n";
            salida += "\t??$element?";
            actual = actual->der;
        }while(actual!= inicio);
        return salida;
    }

};
