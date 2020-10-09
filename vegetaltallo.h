#ifndef VEGETALTALLO_H
#define VEGETALTALLO_H
#include <string>
#include <sstream>
#include <iostream>
#include "plantavegetal.h"


using namespace std;

class VegetalTallo:public PlantaVegetal{
  private:
  bool estadoTallo;

  public:
  VegetalTallo();
  VegetalTallo(string i, bool h, bool s, bool ah, bool p, bool e);
  void tipPlantaSeca();
  void tipPlantaAhogada();
  string toString();
};

VegetalTallo::VegetalTallo()
  : PlantaVegetal() {
  estadoTallo = "";

}

VegetalTallo::VegetalTallo(string i, bool h, bool s, bool ah, bool p, bool e)
  : PlantaVegetal(i, h, s, ah, p){
  estadoTallo = e;
}


void VegetalTallo::tipPlantaSeca(){
  if (seca == 1 && estadoTallo == 0){

    recomAhogada = "Como tu planta está seca y el tallo caído, aumenta la cantidad de agua con la que riegas";
  }

  else if (seca == 1 && estadoTallo == 1){
  
    recomAhogada = "Como tu planta está seca y el tallo muy decolorado, pon las raíces de tu planta en agua durante 1 día y riega con más frecuencia. Además, puedes añadir té de platano para que tu planta tenga más nutrientes";
  }
  else if (seca ==0)
    recomAhogada = "Qué bueno que tu planta no está seca";

}

void VegetalTallo::tipPlantaAhogada(){


    if (ahogada == 1){

    recomAhogada = "Deja de regarla por 2 días y luego disminuye la cantidad de agua con la que se riega.";
  }

  else if (ahogada ==0)
    recomAhogada = "Qué bueno que tu planta no está ahogada";

}

string VegetalTallo::toString(){
	stringstream output;
  string nuevoEstadoTallo;
  if (estadoTallo == 1)
    nuevoEstadoTallo = "decolorado";
  else if (estadoTallo == 0)
    nuevoEstadoTallo = "normal";
	output << PlantaVegetal::toString() << "Estado del tallo: " << nuevoEstadoTallo << "\n";
	return output.str();
}

#endif