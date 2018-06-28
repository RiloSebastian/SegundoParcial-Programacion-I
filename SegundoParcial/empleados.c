#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleados.h"
#include "validaciones.h"


int id= 1;

eEmpleados* new_Empleados()
{
    eEmpleados* EmpleadosAux;

    EmpleadosAux = (eEmpleados*) malloc(sizeof(eEmpleados));

    return EmpleadosAux;
}


int set_sueldo(eEmpleados* this, float sueldo)
{
    int index=-1;

    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        index=0;
    }
    return index;
}


float get_sueldo(eEmpleados* this)
{
    float index=-1;

    if(this != NULL)
    {
        index= this->sueldo;
    }
    return index;
}


int set_id(eEmpleados* this, int id)
{
    int index=-1;

    if(this != NULL && id >= 0)
    {
        this->id = id;
        index=0;
    }
    return index;
}

int set_edad(eEmpleados* this, int edad)
{
    int index=-1;

    if(this != NULL && edad >= 0)
    {
        this->edad = edad;
        index=0;
    }
    return index;
}

int get_id(eEmpleados* this)
{
    int index=-1;

    if(this != NULL)
    {
        index= this->id;
    }
    return index;
}


int get_edad(eEmpleados* this)
{
    int index=-1;

    if(this != NULL)
    {
        index= this->edad;
    }
    return index;
}


int set_nombre(eEmpleados* this, char* nombre )
{
    int index=-1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        index=0;
    }
    return index;
}


char* get_nombre (eEmpleados* this)
{
    char* nombre=NULL;

    if(this != NULL)
    {
        nombre = this->nombre;
    }
    return nombre;
}

int set_profesion(eEmpleados* this, char* profesion )
{
    int index=-1;

    if(this != NULL && profesion != NULL)
    {
        strcpy(this->profesion,profesion);
        index=0;
    }
    return index;
}


char* get_profesion(eEmpleados* this)
{
    char* profesion=NULL;

    if(this != NULL)
    {
        profesion = this->profesion;
    }
    return profesion;
}


int mostrar_Empleadoss(eEmpleados* this)
{
    int index=-1;

    if(this != NULL)
    {
        printf(" NOMBRE: %s ---- sueldo: %f ---- id:%d \n", get_nombre(this), get_sueldo(this), get_edad(this));
        index=0;
    }
    return index;
}


int comparar_Empleadoss(void* EmpleadosA, void* EmpleadosB)
{
    eEmpleados* Empleados1;
    eEmpleados* Empleados2;

    Empleados1= (eEmpleados*) EmpleadosA;
    Empleados2= (eEmpleados*) EmpleadosB;
    /*
    printf("Empleados j: nom: %s -- mail: %f\n",Empleados1->nombre, Empleados1->sueldo);
    printf("Empleados i: nom: %s -- mail: %f\n",Empleados2->nombre, Empleados2->sueldo);
    system("pause");*/
    return 0; //strcmp(Empleados1->sueldo, Empleados2->sueldo);
}


int mostrar_lista_Empleadoss(ArrayList* listado)
{
    int index=-1;
    int i;
    int len;
    eEmpleados* EmpleadosActual;

    if(listado != NULL)
    {
        len = listado->len(listado);
        for(i=0; i<len; i++)
        {
            EmpleadosActual= (eEmpleados*) listado->get(listado, i);
            printf("%d.",i+1);
            mostrar_Empleadoss(EmpleadosActual);
        }
        index=0;
    }
    return index;
}

int crear_pagina(FILE* archivoEmpleados,ArrayList* listaEmpleados , eEmpleados* ActualEmpleados)
{
    int index=-1;
    void* elemento;

    if(archivoEmpleados != NULL && listaEmpleados != NULL && ActualEmpleados != NULL)
    {

     cargar_Empleados(listaEmpleados, ActualEmpleados);
     elemento=listaEmpleados->get(listaEmpleados,id);
     archivoEmpleados=fopen("empleados.csv","w");
     fwrite(elemento,sizeof(void), 1, archivoEmpleados);
     fclose(archivoEmpleados);
     id++;
    }
    return index;
}

int cargar_Empleados(ArrayList* listaEmpleados , eEmpleados* actualEmpleado)
{
    int index=-1;
    char nombre[20];
    char profesion[20];
    int edad;
    float sueldo;

    if(listaEmpleados != NULL && actualEmpleado != NULL)

    actualEmpleado=new_Empleados();

    nombre[20]= validarnombre(nombre);
    set_nombre(actualEmpleado, nombre);

    edad=validarNumero(edad);
    set_edad(actualEmpleado, edad);

    profesion[20]=validarnombre(profesion);
    set_profesion(actualEmpleado,profesion);
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
    set_sueldo(actualEmpleado,sueldo);

    set_id(actualEmpleado,id);


    listaEmpleados->add(listaEmpleados,actualEmpleado);




return index;
}
