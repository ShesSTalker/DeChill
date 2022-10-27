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
//PRE: -
//POS: Inicializa el sistema 
void iniciar_sistema();
//PRE: -
//POS: carga animales en la lista de animales
void cargar_animales();
//PRE: -
//POS: guarda todos los cambios realizados al  archivo csv de animales
void guardar();
//PRE: -
//POS: 
~Sistema();
};
#endif //_SISTEMA_H_