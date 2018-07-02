#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "empleados.h"
#include "validaciones.h"
#define TAM 20
#define OCUPADO 1
#define LIBRE 0

char validarnombre(char input[]){
char aux[30];
int i;
int j=0;
int retorno;

do{
 fflush(stdin);
 gets(aux);
 i=strlen(aux);

  while(j<i){
   if((aux[j]> 64 && aux[j]<91) || (aux[j]>96 && aux[j]<123) || aux[j]==160 || aux[j]==161 || aux[j]==162 || aux[j]==163 || aux[j]==164 || aux[j]==165 || aux[j]== 32 || aux[j]==130 || aux[j]==181 || aux[j]==144 || aux[j]==214 || aux[j]==224 || aux[j]==233){
    retorno= 0;
    j++;
   }

   else{
    retorno= 1;
    printf(" Error, vuelva a ingresar:\n ");
    break;
   }
  }
 }while(retorno!=0);

strcpy(input,aux);
return input[30];
}



char validarNumerochar(char numero1[]){
int i;
int j=0;
int retorno;
char numAux[10];

do{
 fflush(stdin);
 gets(numAux);

 i=strlen(numAux);
 while(j<i){
  if((numAux[j]> 47 && numAux[j]<58) || (numAux[j]>43 && numAux[j]<47)){
   retorno= 0;
   j++;
  }
  else{
   retorno= 1;
   break;
  }
 }
 if(retorno!=0){
  printf("Error, vuelva a ingresar:\n ");
 }
}while(retorno!=0);

strcpy(numero1,numAux);
return numero1[10];
}



int validarNumero(int numero){
int num;
int i;
int j=0;
int retorno;
char numAux[30];

do{
 fflush(stdin);
 gets(numAux);

 i=strlen(numAux);

 while(j<i){

  if((numAux[j]> 47 && numAux[j]<58) || (numAux[j]>43 && numAux[j]<47)){
   retorno= 0;
   j++;
  }
  else{
   retorno= 1;
   break;
  }
 }
 if(retorno!=0){
  printf("Error: debe ingresar datos enteros\n vuelva a ingresar: ");
  }
}while(retorno!=0);

num=atoi(numAux);
numero=num;
return numero;
}

