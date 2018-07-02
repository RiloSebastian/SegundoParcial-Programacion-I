#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "empleados.h"
#include "validaciones.h"

int main()
{
    FILE* empleados;
    eEmpleados* empleado;
    ArrayList* arrrayEmpleados;
    arrrayEmpleados=al_newArrayList();

    int opcion;
    int index=-1;
    char nombre[20];
    char profesion[20];
    int edad;
    float sueldo;
    int id;
    int len;

    do
    {
        printf(" 1.AGREGAR EMPLEADO\n");
        printf(" 2.ELIMINAR EMPLEADO\n");
        printf(" 3.LISTAR\n");
        printf(" 4.SALIR\n");

        printf("\n opcion: ");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            /*if((len = arrrayEmpleados->len(arrrayEmpleados))==0)
            {
                 cargar_Archivo(empleados,arrrayEmpleados,empleado,id,nombre,edad,profesion,sueldo);
            }*/
            printf(" ingrese nombre:\n ");
            nombre[20]= validarnombre(nombre);
            printf(" ingrese edad:\n ");
            edad=validarNumero(edad);
            printf(" ingrese profesion:\n ");
            profesion[20]=validarnombre(profesion);

            if(strcmp(profesion,"analista")==0)
            {
                sueldo= 20000;
            }
            else if(strcmp(profesion,"programador")==0)
            {
                sueldo= 25000;
            }
            else if(strcmp(profesion,"tester")==0)
            {
                sueldo=18000;
            }
            index= cargar_Empleados(arrrayEmpleados,empleado,id,nombre,edad,profesion,sueldo);
            index= crear_pagina(empleados, arrrayEmpleados);
            index= mostrar_lista_Empleadoss(arrrayEmpleados);
            break;
        case 2:
            index=borrar_Empleados(empleados,arrrayEmpleados,empleado,id,nombre,edad,profesion,sueldo);
            index=mostrar_lista_Empleadoss(arrrayEmpleados);
            break;
        case 3:
            leer_Archivo(empleados);
            break;
        case 4:
            break;
        default:
            printf("\n No se ha accedido a ninguna opcion del Sistema. Por favor, intente de nuevo.\n\n");
            break;
        }

    }
    while(opcion!=5);

    return 0;
}
