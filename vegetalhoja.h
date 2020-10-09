#ifndef VEGETALHOJA_H
#define VEGETALHOJA_H
#include <string>
#include <sstream>
#include <iostream>
#include "plantavegetal.h"


using namespace std;

class VegetalHoja:public PlantaVegetal{
  private:
  bool estadoHojas;

  public:
  VegetalHoja();
  VegetalHoja(string i, bool h, bool s, bool ah, bool p, bool eh);
  void tipPlantaSeca();
  void tipPlantaAhogada();
  string toString();
};

VegetalHoja::VegetalHoja()
  : PlantaVegetal() {
  estadoHojas = "";

}

VegetalHoja::VegetalHoja(string i, bool h, bool s, bool ah, bool p, bool eh)
  : PlantaVegetal(i, h, s, ah, p){
  estadoHojas = eh;
}

void VegetalHoja::tipPlantaSeca(){
  if (seca == 1){

    if (estadoHojas == 1){
    
      recomSeca = "Hidrata más tu planta o pronto morirá";
    }

    else if (estadoHojas == 0 ){

      recomSeca = "Incrementa la cantidad de riego";
    }


  }
  else
    recomSeca = "Sigue hidratando tu planta de la misma manera";
  
}

void VegetalHoja::tipPlantaAhogada(){
  if (ahogada == 1){
    if (estadoHojas == 0){

      recomAhogada = "Tu planta no está ahogada, está seca. Hidrata más tu planta o pronto morirá";
    }

    else if (estadoHojas == 1){
      recomAhogada = "Disminuye la cantidad de agua con la que riegas.";
    }
  }
  else
    recomAhogada = "Sigue hidratando tu planta de la misma manera";

}

string VegetalHoja::toString(){
	stringstream output;
  string nuevoEstadoHojas;
  if (estadoHojas == 1)
    nuevoEstadoHojas = "caídas";
  else if (estadoHojas == 0)
    nuevoEstadoHojas = "normal";

	output << PlantaVegetal::toString() << "Estado de las hojas: " << nuevoEstadoHojas << "\n";
	return output.str();
}

#endif