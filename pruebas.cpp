#include <iostream>
#include <string>

using namespace std;

// Cantidad correcta de numeros en Carnet y DPI
int errores(long long int numero){
  auto tamaño = std::to_string(numero);

  if(tamaño.length() == 13 || tamaño.size() == 9){
    return 1;
  }else{
    return 0;
  }

}




void split(string str){
  char salto = '\n';
  string temp = "";
  char coma = ',';
  int categoria = 0;

  int linea;
  // Dividir en lineas
  for(int i=0; i<(int)str.size(); i++){
    if(str[i] == '\n'){
      linea+=1;
    }
  }

  string lineas[linea];
  int contador = 0;
  // Dividir por categoria
  for(int i=0; i<(int)str.size(); i++){
    if(str[i] != '\n'){
      temp += str[i];
      lineas[contador++] = temp; 
    }
  }
}


void separarInformacion(string cadena){
  char salto = '\n';
  char coma = ',';
  string temp = "";
  int categoria;
  int linea;

  //Dividir por categorias
  for(int i=0; i<(int)cadena.size(); i++){
    if(cadena[i] != salto || cadena[i] != coma){
      temp += cadena[i];
    }else{
      if(temp != "Carnet" || temp != "DPI" || temp != "Nombre" || temp != "Carrera" || temp != "Password" || temp != "Creditos" || temp != "Edad" || temp != "Correo"){
        if(categoria == 1){
          cout<<temp<<endl;
          temp="";
          categoria++;

        }else if(categoria == 2){
          cout<<temp<<endl;
          temp="";
          categoria++;

        }else if(categoria == 3){
          cout<<temp<<endl;
          temp="";
          categoria++;

        }else if(categoria == 4){
          cout<<temp<<endl;
          temp="";
          categoria++;

        }else if(categoria == 5){
          cout<<temp<<endl;
          temp="";
          categoria++;

        }else if(categoria == 6){
          cout<<temp<<endl;
          temp="";
          categoria++;

        }else if(categoria == 7){
          cout<<temp<<endl;
          temp="";
          categoria++;

        }else if(categoria == 8){
          cout<<temp<<endl;
          temp="";
          categoria++;
          
        }
      }
    }
  }
}


int main(){
  string info2 = "Carnet,DPI,Nombre,Carrera,Password,Creditos,Edad,Correo\n201700886,3502451230508,Emilia Miramontes,Ingeniería en Ciencias y Sistemas,roxodiciqi,205,21,nicols36@hotmail.com\n201501786,7249529279753,Juan Curiel,Ingeniería Industrial,zanolexima,245,24,jernimo.caballero@yahoo.com\n201822186,9298434863898,Eloisa Rincón,Ingeniería Civil,toqelijanu,95,19,carolinaelizondo85@yahoo.com\n201901425,4131766125532,Bernardo Hinojosa,Ingeniería Mecánica,wosopumano,100,20,alfonso03@hotmail.com\n201503186,8549191766348,Manuel Manzanares,Ingeniería Eléctrica,rejumudore,226,24,benitoarmas92@gmail.com\n201123146,9616636196552,Julia Corona,Ingeniería Electrónica,xojobavuji,237,26,ngela.solorio86@yahoo.com\n201704186,4778315315575,Berta Carrasco,Ingeniería Ambiental,gayahizatu,210,22,carmen.montenegro@yahoo.com\n202000786,7382344774121,Lola Delapaz,Ingeniería Química,hujocikimi,45,19,adriana56@gmail.com\n201611446,2511893949443,Sonia Arteaga,Ingeniería Mecánica Industrial,rezutafila,195,23,esperanza.meza41@hotmail.com\n201819852,3423442386382,Benjamín Asencio,Ingeniería Mecánica Eléctrica,runoqozepo,117,20,horacio.tejada15@yahoo.com";



  string info = "nombre,color,comida,estrellas\nmc,rojo&amarillo,hamburgesas,4\ndominos,azul,pizza,3\nmaton,naranja,pollo,3\nchino,blanco,comidachina,2\ngreen,verde,saludable,2\nwok,blanco,china,2\nking,cafe,hamburgesas,3";
   
  int validacion = errores(201801155);
  cout<<validacion<<endl;
  validacion = errores(350245120508);
  cout<<validacion<<endl;
  validacion = errores(201801);
  cout<<validacion<<endl;
  validacion = errores(7249529279753);
  cout<<validacion<<endl;
     
  return 0;
}