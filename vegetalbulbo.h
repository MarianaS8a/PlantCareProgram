#ifndef VEGETALBULBO_H
#define VEGETALBULBO_H
#include <string>
#include <sstream>
#include <iostream>
#include "plantavegetal.h"


using namespace std;

class VegetalBulbo:public PlantaVegetal{
  private:
  bool estadoPuntaTallo;

  public:
  VegetalBulbo();
  VegetalBulbo(string i, bool h, bool s, bool ah, bool p, bool e);
  void tipPlantaSeca();
  void tipPlantaAhogada();
  string toString();
};

VegetalBulbo::VegetalBulbo()
  : PlantaVegetal() {
  estadoPuntaTallo = "";

}

VegetalBulbo::VegetalBulbo(string i, bool h, bool s, bool ah, bool p, bool e)
  : PlantaVegetal(i, h, s, ah, p){
  estadoPuntaTallo = e;
}

void VegetalBulbo::tipPlantaSeca(){
  if (seca == 1 && estadoPuntaTallo == 1){
    recomSeca = "Como tu planta está seca y amarilla te recomendamos cortar la punta de los tallos amarillos, y colocar la planta en un recipiente lleno de agua tibia durante 10 minutos. Además incrementa la cantidad de agua con la que la riegas.";
  }
  else if (seca == 1 && estadoPuntaTallo == 0){
  recomSeca = "Como tu la punta de los tallos no está amarilla, te recomendamos solo aumentar la cantidad de agua en cada riego o incrementar las veces que se riega";
  }
  else if (seca == 0)
    recomSeca = "Qué bien que tu planta no tiene exceso de agua";

}

void VegetalBulbo::tipPlantaAhogada(){

  if (ahogada == 1 && estadoPuntaTallo == 1){
    recomAhogada = "Tu planta no está ahogada, está seca. Aumenta el riego.";
  }
  else if (ahogada == 1 && estadoPuntaTallo == 0){
  recomAhogada = "Como tu planta está ahogada, disminuye el riego de tu planta. Puedes sacarla de la tierra y ponerla en tierra seca durante 1 día para que se recupere.";
  }
  else if (ahogada == 0)
    recomAhogada = "Qué bien que tu planta no tiene exceso de agua";
}

string VegetalBulbo::toString(){
	stringstream output;
  string nuevoEstadoPuntaTallo;
  if (estadoPuntaTallo == 1)
    nuevoEstadoPuntaTallo = "amarillo";
  else if (estadoPuntaTallo == 0)
    nuevoEstadoPuntaTallo = "verde";

	output << PlantaVegetal::toString() << "Estado de la punta del tallo: " << nuevoEstadoPuntaTallo << "\n";
	return output.str();
}

#endif