#ifndef _SISTEMA_H_
#define _SISTEMA_H_
#include "Menu.h"
class Sistema{
private:
Lista<Animal*>* animales; 
Menu menu;

public:
//PRE: -
//POS: Inicializa la lista de animales
Sistema();
void iniciar_sistema();
void cargar_animales();
~Sistema();

};


#endif //_SISTEMA_H_