#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main(){

    // variables para la extraccion de informacion
    string path = "";
    string data = "";
    string item = "";
    
    //variables para distinguir la informacion
    int mes,dia,hora,carnet;
    string nombre,descripcion,materia,fecha,estado;

    // contador para el arreglo, y para las lineas
    int counter = 0;
    int linea = 0;
    int i;

    // Lectura del archivo
    ifstream file;

    cout<<"Ingresar la Ruta: ";
    getline(cin, path);

    file.open(path, ios::in);

    if(!file.fail()){
        while(!file.eof()){
            getline(file, data);
            istringstream div(data);
            while(getline(div, item, ',')){
                if(linea!=0){
                    switch(counter){
                        case 0:
                            mes = stoi(item,nullptr,10);
                        break;
                        case 1:
                            dia = stoi(item,nullptr,10);
                        break;
                        case 2:
                            hora = stoi(item,nullptr,10);
                        break;
                        case 3:
                            carnet = stoi(item,nullptr,10);
                        break;
                        case 4:
                            nombre = item;
                        break;
                        case 5:
                            descripcion = item;
                        break;
                        case 6:
                            materia = item;
                        break;
                        case 7:
                            fecha = item;
                        break;
                        case 8:
                            estado = item;
                        break;
                    }
                } 
                
                counter++;
            }
            if(linea!=0){
                cout<<"Matriz["+to_string(mes)+"]["+to_string(hora)+"]["+to_string(dia)+"] Carnet: "+to_string(carnet)+" Nombre: "+nombre+" Descripcion: "+descripcion+" Materia: "+materia+" Fecha: "+fecha+" Estado: "+estado+"\n";
            }
            
            linea++;
            counter = 0;
            mes = 0;
            dia = 0;
            hora = 0;
            carnet = 0;
            nombre = "";
            descripcion = "";
            materia = "";
            fecha = "";
            estado = "";
        }
    }


    return 0;
}