#ifndef VERMISPLANTAS_H
#define VERMISPLANTAS_H
#include <string>
#include "plantavegetal.h"

using namespace std;
const int MAX = 100;
class VerMisPlantas{
  
  private:
  int cantidad;
  PlantaVegetal *plantas[MAX];

  public:
  VerMisPlantas();
  ~VerMisPlantas();
  void anadirPlanta(PlantaVegetal *p);
  PlantaVegetal* info(string id);
  //PlantaVegetal* recomendaciones(string id);
  string toString();
};

VerMisPlantas::VerMisPlantas(){
  cantidad = 0;
}

VerMisPlantas::~VerMisPlantas(){
	for (int i = 0; i<cantidad; i++ )
    delete plantas[i];
}

void VerMisPlantas::anadirPlanta(PlantaVegetal *p){
  if (cantidad < MAX){
    plantas[cantidad] = p;
  }
  cantidad++;
  
}

PlantaVegetal *VerMisPlantas:: info(string ID){
  for(int i=0; i<=cantidad; i++){
    if (plantas[cantidad]->getID() == ID){
      return plantas[i];
    }
  }
  return 0;
}

string VerMisPlantas::toString() {
	stringstream output;
	output << "Plantas:\n";
	for (int i = 0; i < cantidad; i++) {
    plantas[i]->tipPlagas();
    plantas[i]->tipPlantaAhogada();
    plantas[i]->tipPlantaSeca();
		output << plantas[i]->toString() << "\n";
	}
	return output.str();
}

#endif