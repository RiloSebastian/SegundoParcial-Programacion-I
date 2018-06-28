#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleados.h"

int main()
{
    int opcion;
    int index=-1;

    FILE* empleados;

    ArrayList* arrrayEmpleados;
    arrrayEmpleados=al_newArrayList();

    eEmpleados* empleado;

    int contar=0;

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
            //index= crear_pagina(empleados,arrrayEmpleados,empleado);
            index=cargar_Empleados(arrrayEmpleados,empleado);
            index= mostrar_lista_Empleadoss(arrrayEmpleados);
            break;
        case 2:
            break;
        case 3:
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
