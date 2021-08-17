#include <iostream>
#include <string>

using namespace std;

class Tarea{
    private:
        int carnet;
        string nombre;
        string descripcion;
        string materia;
        string fecha;
        string estado;
    public:
        Tarea(){
            this->carnet = 0;
            this->nombre = "";
            this->descripcion = "";
            this->materia = "";
            this->fecha = "";
            this->estado = "";
        }
    
    void getTarea(int c,string n,string d, string m, string f,string e){
        this->carnet = c;
        this->nombre = n;
        this->descripcion = d;
        this->materia = m;
        this->fecha = f;
        this->estado = e;
    }

};


/*
int main(){
    Tarea Matrix[5][9][30] = { Tarea() };
    matriz3d[0][0][0].getTarea(201801155,"Bryan","proyecto","EDD","123/15/12","Casi");
    matriz3d[0][1][1].getTarea(202000156,"Eduardo","proyecto","OCL1","2021/09/05","Casi");
    matriz3d[0][2][2].getTarea(202108479,"Caal","tarea","Apli1","2021/10/8","Casi");
    matriz3d[1][0][2].getTarea(201901425,"Tarea de Matematica","proyecto","EDD","123/15/12","Casi");
    matriz3d[1][1][1].getTarea(201901425,"Tarea de Matematica","proyecto","OCL1","2021/09/05","Casi");
    matriz3d[1][2][0].getTarea(201901425,"Tarea de Matematica","tarea","Apli1","2021/10/8","Casi");
    matriz3d[2][1][0].getTarea(202000786,"Codificar en C++","proyecto","EDD","123/15/12","Casi");
    matriz3d[2][1][1].getTarea(202000786,"Codificar","proyecto","OCL1","2021/09/05","Casi");
    matriz3d[2][1][2].getTarea(202000786,"Codificar","tarea","Apli1","2021/10/8","Casi");
    matriz3d[3][0][1].getTarea(201704186,"Tarea 2 de Física 3,","proyecto","EDD","123/15/12","Casi");
    matriz3d[3][1][1].getTarea(201704186,"Física","proyecto","OCL1","2021/09/05","Casi");
    matriz3d[3][0][1].getTarea(201704186,"Física","tarea","Apli1","2021/10/8","Casi");

    //Column Major
    
    Tarea vector[36] = { Tarea() };

    for(int i=0; i<3; i++){
        for(int j=0; i<3; j++){
            for(int k=0; k<4; k++){
                matriz3d[k][i][j] = vector[];
            }
        }
    }
    

    int matriz[4][3][3];
    int contador=1;
    for(int k = 0; k<4; k++){
        cout<<endl<<"Nivel: "<<k<<endl;
        for(int j = 0; j<3; j++){
            for(int i = 0; i<3; i++){
                matriz[k][j][i] = contador;
                cout<<matriz[k][j][i]<<" ";
                contador++;        
            }
            cout<<endl;
        }
    }

    cout<<endl;
    for(int j = 0; j<3; j++){
        for(int i = 0; i<3; i++){
            for(int k = 0; k<4; k++){
                cout<<matriz[k][i][j]<<" ";  
            }
        }
    }

   return 0;
}*/