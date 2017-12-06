#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carrera{
    char nombre[2014];
    int id;
    int nem;
    int rank;
    int leng;
    int mat;
    int hist;
    int cs;//ciencias naturales
    int pond;
    int psu;
    float primo;
    float finale;
    int c_psu;// Cupos PSU
    int c_bea;
}carrera;

struct facultades{
    char nombre[1024];
    struct carrera *corsa [30];
};
///////////// Funciones Principales ///////////////
void inicializarFacultades(struct facultades universidad[]);
void inicializarCarreras(struct carrera courir[]);
int cargarDatos (struct facultades faculte[],struct carrera courir[]);
void menu (struct facultades faculte[],struct carrera courir[]);
///////////////////////////////////////////////////
//\\\\\\\\\\\ Funciones del menu \\\\\\\\\\\\\\\\//
void consultaPonderado(struct carrera courir[]);
void simuladorPostulacion(struct carrera courir[]);
void mostrarFacultad(struct facultades faculte[]);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//

int main (){
    struct facultades UV[20];
    struct carrera uv[100];
    inicializarFacultades(UV);
    if (cargarDatos(UV,uv))menu(UV,uv);
}

void menu(struct facultades faculte[],struct carrera courir[]){
    int opcion=1;
    while (opcion!=4){
        printf("\n|||||******************************************|||||\n");
        printf("|||||Bienvenido a el simulador de postulaciones|||||\n");
        printf("|||||                                          |||||\n");
        printf("|||||1.- Consultar ponderacion de la carrera   |||||\n");
        printf("|||||                                          |||||\n");
        printf("|||||2.- Simular postulacion de la carrera     |||||\n");
        printf("|||||                                          |||||\n");
        printf("|||||3.- Mostrar ponderaciones de una facultad |||||\n");
        printf("|||||                                          |||||\n");
        printf("|||||4.- Salir                                 |||||\n");
        printf("|||||******************************************|||||\n");
        printf("|||||Ingrese opcion (solo 1 caracter): ");
        scanf("%i",&opcion);
        if (opcion==1)consultaPonderado(courir);
        if (opcion==2)simuladorPostulacion(courir);
        if (opcion==3)mostrarFacultad(faculte);
        if (opcion==4);
        else {
            if ((opcion!=1)&&((opcion!=2)&&(opcion!=3))){
                printf("|||||Error al ingresar opcion                  |||||\n");
                printf("|||||Ingrese opcion (solo 1 caracter): ");
                scanf("%c",&opcion);
            }
        }
    }
}

void inicializarFacultades(struct facultades universidad[]){
    printf("Prueba\n");
}
void inicializarCarreras(struct carrera courir[]){
    int i;
    for (i=0;i<100;i++){
        strcpy(courir[i].nombre,"");
        courir[i].id=0;
        courir[i].nem=0;
        courir[i].rank=0;
        courir[i].leng=0;
        courir[i].mat=0;
        courir[i].hist=0;
        courir[i].cs=0;//ciencias naturales
        courir[i].pond=0;
        courir[i].psu=0;
        courir[i].primo=0.0;
        courir[i].finale=0.0;
        courir[i].c_psu=0;// Cupos PSU
        courir[i].c_bea=0;
    }
}
int cargarDatos (struct facultades faculte[],struct carrera courir[]){
    printf("Prueba\n");
    return 1;
}



void consultaPonderado(struct carrera courir[]){
    printf("Prueba\n");
}
void simuladorPostulacion(struct carrera courir[]){
    printf("Prueba\n");
}
void mostrarFacultad(struct facultades faculte[]){
    printf("Prueba\n");
}
