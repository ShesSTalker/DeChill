#ifndef _SISTEMA_H_
#define _SISTEMA_H_
#include "Menu.h"
class Sistema{
private:
Lista<Animal*>* animales; 

public:
Sistema();
void cargar_animales();
~Sistema();

};


#endif //_SISTEMA_H_