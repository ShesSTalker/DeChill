#ifndef _MENU_H_
#define _MENU_H_

class Menu{
    //private
    int opcion_tomada; //creo que la vamos a necestar para procesar las opciones del usuario

    //Metodos
    public:
        //Pre: -
        //Pos: Incianliza opcion_tomada en 0
        Menu();

        void cargar_datos();
        //Pre: -
        //Pos: Imprime por pantalla un saludo al usuario
        
        void bienvenida();
        //Pre: -
        //Pos: Imprime por pantalla el menu con las opciones
        
        void mostrar_menu();
        //Pre: -
        //Pos: Solicita al usuario que ingrese el numero de la opcion que desea ejecutar.
        
        void pedir_opcion();
        //Pre: -
        //Pos: Imprime por pantalla los animales de la reserva
        
        void mostrar_animales();
        //Pre: -
        // Pos: Se agrega un nuevo animal rescatado a la reserva
        void rescatar_animal();
        //Pre: -
        // Pos:  Se buscara el nombre del animal ingresado por el usuario, devolvera true si se encontro el nombre y false en caso contrario 
        bool buscar_animal();
        //Pre: -
        //Pos: Se mostrara por pantalla un menu con las opciones de cuidado disponibles
        void ciudar_animal();
        //Pre: El usuario debe ingresar la primera opcion
        //Pos: Se mostrara los datos de cada animal individualmente y se le preguntara si desaa baniarlo, alimentarlo o saltearlo
        void elegir_individualmente();
        //Pre: El usuario debe ingresar la segunda opcion
        //Pos: El hambre de todos los animales volvera a 0, diciendo su nombre y que comio
        void alimentar_a_todos();
        //Pre: El usuario debe ingresar la tercera opcion
        //Pos: La higiene de los animales subira a 100 y si el animal no quiere banio lo dira por pantalla
        void baniar_a_todos();
        //Pre: El usuario debe ingresar la cuarta opcion
        //Pos: Regresa al menu inicial
        void regresar_al_inicio(); 
        //Pre: -
        //Pos: 
        void adoptar_animal();
        //Pre: -
        //Pos: Se guargan todos los cambios de la reserva en el archivo
        void guardar_y_salir();
    
};

#endif

