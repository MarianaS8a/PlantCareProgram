#include <iostream>
#include <string>
#include <fstream>
#include "plantavegetal.h"
#include "vegetalbulbo.h"
#include "vegetalhoja.h"
#include "vegetalraiz.h"
#include "vegetaltallo.h"
#include "vermisplantas.h"

using namespace std;

int main() {
  
  int opcion1;
  int opcion2;
  string preguntaExtra;
  string id;
  string tp;
  bool hojas;
  bool seca;
  bool ahogada;
  bool plagas;
  bool estadoHojas;
  bool estadoTallo;
  bool estadoPuntaTallo;
  string nuevo;
  const int datos = 5;
  string preguntas[datos];
  VerMisPlantas plantas;

  while (opcion1 != 3){
    cout << "Bienvenido al programa para consultar recomendaciones de plantas con plagas, secas o ahogadas. Elige lo que quieres hacer:\n 1) Agregar una planta\n 2) Ver tus plantas y recomendaciones\n 3) Salir\n";
    cin >> opcion1;
    if (opcion1 == 1){
      cout << "Elige el tipo de vegetal que da tu planta:\n 1) Bulbo\n 2) Hoja\n 3) Raíz\n 4) Tallo\n";
      cin >> opcion2;

      if (opcion2 == 1){
        preguntaExtra = ", cómo es la punta del tallo: 0) verde 1) amarillo";
      }
      else if (opcion2 == 2){
        preguntaExtra = ", cómo están las hojas: 0) normales 1)caídas";
      }
      else if (opcion2 == 3){
        preguntaExtra = ", cómo están las hojas: 0) normales 1)caídas";
      }
      else if (opcion2 == 4){
        preguntaExtra = ", cómo está el tallo: 0) normal 1) decolorado";
      }

      bool respuestas[datos];

      ifstream archivo;
      archivo.open("proyecto.txt");
      if (archivo.is_open()){
        getline(archivo, tp);
        tp = tp + preguntaExtra;
        
        int coma = 0;
        

        for (int i=0; i<= datos; i++){
          if (i<datos){
            coma = tp.find(",");
            nuevo = tp.substr(0, coma);
            cout << "Escribe " << nuevo << "\n";
            tp.erase(0,coma+1);
          }
          else{
            cout << "Escribe" << tp << "\n";
            
          }
          if (i>0)
            cin >> respuestas [i-1];
          else
            cin >> id;
        }
        
      }


      archivo.close();

      hojas = respuestas[0];
      seca = respuestas[1];
      ahogada = respuestas[2];
      plagas = respuestas[3];

      if (opcion2 == 1) {
        bool estadoPuntaTallo = respuestas[4];
        plantas.anadirPlanta(new VegetalBulbo(id, hojas, seca, ahogada, plagas, estadoPuntaTallo));
      }
      else if (opcion2 == 2) {
      estadoHojas = respuestas[4]; 
      plantas.anadirPlanta(new VegetalHoja(id, hojas, seca, ahogada, plagas, estadoHojas));
      }
      else if (opcion2 == 3) {
      estadoHojas = respuestas[4]; 
      plantas.anadirPlanta(new VegetalRaiz(id, hojas, seca, ahogada, plagas, estadoHojas));
      }
      else if (opcion2 == 4){
      estadoTallo = respuestas[4]; 
      plantas.anadirPlanta(new VegetalTallo(id, hojas, seca, ahogada, plagas, estadoTallo));

      }
    }
    else if (opcion1 == 2){
      plantas.anadirPlanta(new VegetalTallo("PlantaEjemplo", 0, 1, 1, 1, 0));
      cout << plantas.toString();
    }
    cout << "\n\n\n";
  }


return 0;
}