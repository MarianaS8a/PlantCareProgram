#ifndef VEGETALRAIZ_H
#define VEGETALRAIZ_H
#include <string>
#include <sstream>
#include <iostream>
#include "plantavegetal.h"


using namespace std;

class VegetalRaiz:public PlantaVegetal{
  private:
  bool estadoHojas;

  public:
  VegetalRaiz();
  VegetalRaiz(string i, bool h, bool s, bool ah, bool p, bool e);
  void tipPlantaSeca();
  void tipPlantaAhogada();
  string toString();
};

VegetalRaiz::VegetalRaiz()
  : PlantaVegetal() {
  estadoHojas = "";

}

VegetalRaiz::VegetalRaiz(string i, bool h, bool s, bool ah, bool p, bool e)
  : PlantaVegetal(i, h, s, ah, p){
  estadoHojas = e;
}

void VegetalRaiz::tipPlantaSeca(){

  if (seca == 1 && estadoHojas == 1){

    recomSeca = "Como tu planta está seca y las hojas caídas, probablemente ya no puedas revivirla. Mejor siembra otra planta.";
  }

  else if (seca == 1 && estadoHojas == 0){
  
    recomSeca = "Chomo tu planta está seca pero las hojas no tan caídas, aún puedes salvarla. Incrementa el riego y nutre tu planta con té de plátano.";
  }
  else if (seca== 1)
    recomSeca = "En realidad tu planta no está seca, sigue así.";

  else 
    recomSeca = "Felicidades por que tu planta no esté seca.";

}

void VegetalRaiz::tipPlantaAhogada(){
  if (ahogada == 1 && estadoHojas == 1){

    recomAhogada = "Como tu planta está ahogada, envuélvela en papel absorbente y déjala reposar durante un día entero cambiando el papel si ves que se empapa en exceso. Pasado este día, poda las raíces podridas, es decir, las que estén muy marrones, y vuelve a sembrar la planta sin regarla en unos cuantos días.";
  }

  else if (ahogada == 1 && estadoHojas == 0){
  
    recomAhogada = "Como tu planta está ahogada, no la riegues por unos cuantos días y cuando vuelvas a regar disminuye la cantidad de agua. En ocasiones las plantas se ahogan por estar al aire libre, si le ha caído lluvia a tu planta, ponla en un lugar techado";
  }
  else if (ahogada ==0)
    recomAhogada = "Qué bien que tu planta no tiene exceso de agua";
  
}

string VegetalRaiz::toString(){
	stringstream output;
  string nuevoEstadoHojas;
  if (estadoHojas == 1)
    nuevoEstadoHojas = "caídas";
  else if (estadoHojas == 0)
    nuevoEstadoHojas = "normales";

	output << PlantaVegetal::toString() << "Estado de las hojas: " << nuevoEstadoHojas << "\n";
	return output.str();
}

#endif