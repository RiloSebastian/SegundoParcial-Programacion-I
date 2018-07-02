#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include "ArrayList.h"
typedef struct
{
int id;
char nombre[20];
char profesion[20];
float sueldo;
int edad;
}eEmpleados;

eEmpleados* new_Empleados();

int set_edad(eEmpleados* this, int edad);

int get_edad(eEmpleados* this);

int set_sueldo(eEmpleados* this, float );

int set_id(eEmpleados* this, int id);

int get_id(eEmpleados* this);

int set_sueldo(eEmpleados* this, float );

float get_sueldo(eEmpleados* this);

int set_nombre(eEmpleados* , char* );

char* get_nombre(eEmpleados* );

int set_profesion(eEmpleados* , char* );

char* get_profesion (eEmpleados* );

int mostrar_Empleadoss (eEmpleados* );

int comparar_Empleadoss(void* , void* );

int mostrar_lista_Empleadoss(ArrayList* );

int cargar_Archivo(FILE*  ,ArrayList* , eEmpleados* , int , char* , int , char* , float );

int crear_pagina(FILE* ,ArrayList* );

int cargar_Empleados(ArrayList* , eEmpleados* , int , char* , int , char* , float );

int borrar_Empleados(FILE*  ,ArrayList* , eEmpleados* , int , char* , int , char* , float );

int leer_Archivo(FILE* );

#endif
