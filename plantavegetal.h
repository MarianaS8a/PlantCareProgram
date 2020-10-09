#ifndef PLANTAVEGETAL_H
#define PLANTAVEGETAL_H
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class PlantaVegetal{
  protected:
  string ID;
  bool hojas;
  bool seca;
  bool ahogada;
  bool plagas;
  string recomSeca;
  string recomAhogada;
  string recomPlagas;

  public:
  PlantaVegetal();
  PlantaVegetal(string i, bool h, bool s, bool ah, bool p);
  //virtual ~PlantaVegetal()=0;
  string getID();
  bool getSeca();
  bool getAhogada();
  void setSeca(bool s);
  void setAhogada(bool ah);
  void setPlagas(bool p);
  void tipPlagas();
  virtual void tipPlantaSeca()=0;
  virtual void tipPlantaAhogada()=0;
  virtual string toString();
  
};

PlantaVegetal::PlantaVegetal(){
  ID = "";
  hojas = 0;
  seca = 0;
  ahogada = 0;
  plagas = "";

}

PlantaVegetal::PlantaVegetal(string i, bool h, bool s, bool ah, bool p){
  ID = i;
  hojas = h;
  seca = s;
  ahogada = ah;
  plagas = p;

}

string PlantaVegetal::getID(){
  return ID;
}

bool PlantaVegetal::getSeca(){
  return seca;
}

bool PlantaVegetal::getAhogada(){
  return ahogada;
}

void PlantaVegetal::setSeca(bool s){
  seca = s;
}

void PlantaVegetal::setAhogada(bool ah){
  ahogada = ah;
}

void PlantaVegetal::setPlagas(bool p){
  plagas = p;
}


void PlantaVegetal::tipPlagas(){
  if (plagas == 0)
    recomPlagas = "¡Felicitaciones por no tener plagas!";
  else if (plagas == 1){
    recomPlagas = "Para combatir todo tipo de plagas puedes usar: \nAceite de Neem \nTierra de Diatomeas \nAzufre Agrícola \nTrichodermas \nMicrorizas \nRemedios Caseros (jabón potásico, extracto de ajo, chile, cebolla, bicarbonato de sodios entre otros)";
  }
}

string PlantaVegetal::toString() {
	string nuevoHojas;
  string nuevoSeca;
  string nuevoAhogada;
  string nuevoPlagas;
  
  stringstream output;
	
  if (hojas == 1)
    nuevoHojas = "sí";
  else if (hojas == 0)
    nuevoHojas = "no";

  if (seca == 1)
    nuevoSeca = "sí";
  else if (seca == 0)
    nuevoSeca = "no";

  if (ahogada == 1)
    nuevoAhogada = "sí";
  else if (ahogada == 0)
    nuevoAhogada = "no";

  if (plagas == 1)
    nuevoPlagas = "sí";
  else if (plagas == 0)
    nuevoPlagas = "no";

	output << "Id: " << ID << "\n" << "Hojas: " << nuevoHojas << "\n" << "Seca: " << nuevoSeca << "\n" << "Ahogada: " << nuevoAhogada << "\n" << "Plagas: " << nuevoPlagas << "\n" << "Recomendaciones:\n" << recomSeca << "\n" << recomAhogada << "\n" << recomPlagas << "\n";
	return output.str();
}




#endif