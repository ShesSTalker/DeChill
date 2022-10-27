#ifndef _SISTEMA_H_
#define _SISTEMA_H_

#include "Menu.h"
class Sistema{
private:
Lista<Animal*>* animales; 
Menu *menu;

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
//PRE: opcion_tomada debe ser 0 < opcion_tomada <= 6
//POS: Procesa opcion_tomada para ejecutar las operaciones de la opcion elejida por el usuario
void procesar_opcion(Lista<Animal*>* animales);
//PRE: -
//POS: Imprime por pantalla todos los animales de la lista.
void listar_animales(Lista<Animal*>* animales); 
//PRE: -
//POS: Muestra por pantalla la informacion del animal
void mostrar_animal(Animal* mi_animal);
//PRE: -
//POS: Le pide al usario el nombre del animal rescatado, si el nombre ya existe se le da la opcion al usuario de cargar otro nombre o volver al menu;
void ingresar_nombre(Lista<Animal*>* animales);
//PRE: - 
//POS: Devuelve verdadero si el nombre existe en la lista y falso si no existe       
bool buscar_nombre(string nombre, Lista<Animal*>* animales);
//PRE: El nombre del animal no debe estar en la lista
//POS: Carga el animal a la lista
void rescatar_animal();
//PRE: -
//POS: guarda todos los cambios realizados al  archivo csv de animales
void guardar();
//PRE: -
//POS: 
~Sistema();
};
#endif //_SISTEMA_H_