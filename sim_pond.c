#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct carrera{
    char nombre[1014];
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

typedef struct facultades{
    char nombre[1024];
    struct carrera *corsa [30];
}facultades;
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
/////////////    Funciones Extra     //////////////

///////////////////////////////////////////////////

int main (){
    struct facultades UV[20];
    struct carrera uv[100];
    inicializarFacultades(UV);
    inicializarCarreras(uv);
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
    int i = 0,j = 0;
    for(i=0;i<20;i++){
        strcpy(universidad[i].nombre ,"");
        for (j=0;j<30;j++){
            universidad[i].corsa[j]=0;
        }
    }
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
    int i=0,pos_f=0,pos_c=0,aux;
    char destino[1024],flag;
    FILE *carrera_facultades;
    strcpy(destino,"ej04.txt");
    printf("||||| Ingrese la ruta y el archivo de texto: \n");
    //scanf("%s",destino);
    carrera_facultades=fopen(destino,"r");
    if (carrera_facultades==0){
        printf("|||||Archivo no encontrado");
        return 0;
    }
    else {
        while (feof(carrera_facultades) == 0) {
            fscanf(carrera_facultades,"%s",destino);
            if(strcmp(destino,"*")==0){
                fscanf(carrera_facultades,"%s   ",destino);
                while ((strcmp(destino,"<")!=0)||(strcmp(destino,"*")!=0)){
                    if((strcmp(destino,"<")==0)||(strcmp(destino,"*")==0)) break;
                    if(feof(carrera_facultades))break;
                    strcat(faculte[pos_f].nombre,destino);
                    strcat(faculte[pos_f].nombre," ");
                    fscanf(carrera_facultades,"%s   ",destino);
                }
                pos_f++;
                i=0;
            }
            if(strcmp(destino,"<")==0){
                fscanf(carrera_facultades,"%s",destino);
                while ((strcmp(destino,"<")!=0)||(strcmp(destino,"*")!=0)){
                    if((strcmp(destino,"<")==0)||(strcmp(destino,"*")==0)) break;
                    if(feof(carrera_facultades))break;
                    strcat(courir[pos_c].nombre,destino);
                    strcat(courir[pos_c].nombre," ");
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].id=aux;
                    printf("--------->> %d",courir[pos_c].id);
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].nem=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].rank=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].leng=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].mat=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].hist=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].cs=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].pond=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].psu=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].primo=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].finale=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].c_psu=aux;
                    fscanf(carrera_facultades,"%s",destino);
                    aux=atoi(destino);
                    courir[pos_c].c_bea=aux;
                    faculte[pos_f].corsa[i]=&courir[pos_c];
                    pos_c++;
                    i++;
                    fscanf(carrera_facultades,"%s",destino);
                }
            }
        }
    fclose(carrera_facultades);
    }
    return 1;
}



void consultaPonderado(struct carrera courir[]){
    int i=0,codigo_n,opcion,j,cont_acierto,aciertos=0;
    char codigo_c[1024];
    strcpy(codigo_c,"");
    printf("|||||Desea buscar por codigo (1) o carrera (2):");
    scanf("%i",&opcion);
    if(opcion==1){
        printf("|||||Ingrese un codigo numerico:\n");
        scanf("%d",&codigo_n);
        while((i<100)&&(strcmp(courir[i].nombre,"")!=0)){
            if (codigo_n==courir[i].id){
                printf("|||||%s \n",courir[i].nombre);
                printf("|||||Nem:%d||Ranking:%d||Lenguaje:%d||Matematica:%d||(Historia:%d|or|Ciencias:%d)||\n",courir[i].nem,courir[i].rank,courir[i].leng,courir[i].mat,courir[i].hist,courir[i].cs);
                printf("|||||Ponderacion minima:%d||Ponderacion minima PSU:%d||\n",courir[i].pond,courir[i].psu);
                printf("|||||Primer matriculado:%f||Ultimo matriculado:%f||\n",courir[i].primo,courir[i].finale);
                printf("|||||Cupos PSU:%d||Cupos BEA:%d|||\n",courir[i].c_psu,courir[i].c_bea);
                return;
            }
            i++;
        }
        printf("|||||No se encontraron coincidencias\n");
    }
    else{
        printf("|||||Ingrese nombre de la carrera: ");
        scanf("%s",codigo_c);
        while ((i<100)&&(strcmp(courir[i].nombre,"")!=0)){
            printf("----> %d ; %d \n",strlen(codigo_c),strlen(courir[i].nombre));
            if(strlen(codigo_c)<=strlen(courir[i].nombre)){
                j=0;
                cont_acierto=0;
                while (j<strlen(codigo_c)){
                    //if ((tolower(codigo_c[j])==tolower(courir[i].nombre[j]))||(codigo_c[j]==" ")&&(courir[i].nombre[j]=="_")){
                    if (tolower(codigo_c[j])==tolower(courir[i].nombre[j])){
                        cont_acierto++;
                    }
                    j++;
                }
                if (cont_acierto==j){
                    aciertos++;
                    printf("|||||%s \n",courir[i].nombre);
                    printf("|||||Nem:%d||Ranking:%d||Lenguaje:%d||Matematica:%d||(Historia:%d|or|Ciencias:%d)||\n",courir[i].nem,courir[i].rank,courir[i].leng,courir[i].mat,courir[i].hist,courir[i].cs);
                    printf("|||||Ponderacion minima:%d||Ponderacion minima PSU:%d||\n",courir[i].pond,courir[i].psu);
                    printf("|||||Primer matriculado:%f||Ultimo matriculado:%f||\n",courir[i].primo,courir[i].finale);
                    printf("|||||Cupos PSU:%d||Cupos BEA:%d|||\n",courir[i].c_psu,courir[i].c_bea);
                }
            }
            i++;
        }
        if (aciertos==0){
            printf("|||||Busqueda sin resultados...");
        }
    }
}
void simuladorPostulacion(struct carrera courir[]){
    /*int nem,rank,leng,mat,hist,cs,code,i=0;
    float postulante=0.0,aux;
    printf("|||||Ingrese Nem: \n");
    scanf("%d",&nem);
    printf("|||||Ingrese Ranking: \n");
    scanf("%d",&rank);
    printf("|||||Ingrese Lenguaje y cominicacion: \n");
    scanf("%d",&leng);
    printf("|||||Ingrese Matematicas: \n");
    scanf("%d",&mat);
    printf("|||||Ingrese Historia: \n");
    scanf("%d",&hist);
    printf("|||||Ingrese Ciencias: \n");
    scanf("%d",&cs);
    printf("|||||Ingrese un codigo numerico: \n");
    scanf("%d",&code);
    while((i<100)&&(strcmp(courir[i].nombre,"")!=0)){
        if (code==courir[i].id){
            printf("|||||%s \n",courir[i].nombre);
            printf("|||||Nem:%d||Ranking:%d||Lenguaje:%d||Matematica:%d||(Historia:%d|or|Ciencias:%d)||\n",courir[i].nem,courir[i].rank,courir[i].leng,courir[i].mat,courir[i].hist,courir[i].cs);
            printf("|||||Ponderacion minima:%d||Ponderacion minima PSU:%d||\n",courir[i].pond,courir[i].psu);
            printf("|||||Primer matriculado:%f||Ultimo matriculado:%f||\n",courir[i].primo,courir[i].finale);
            printf("|||||Cupos PSU:%d||Cupos BEA:%d|||\n",courir[i].c_psu,courir[i].c_bea);
            aux=(courir[i].nem*nem)/100;
            postulante=postulante+aux;
            aux=(courir[i].rank*rank)/100;
            postulante=postulante+aux;
            aux=(courir[i].leng*leng)/100;
            postulante=postulante+aux;
            aux=(courir[i].mat*mat)/100;
            postulante=postulante+aux;
            aux=(courir[i].hist*hist)/100;
            postulante=postulante+aux;
            aux=(courir[i].cs*cs)/100;
            postulante=postulante+aux;
            printf("|||||");
            if (postulante>=)
            return;
        }
        i++;
    }
    printf("|||||No se encontraron coincidencias\n");*/
}
void mostrarFacultad(struct facultades faculte[]){
    printf("Prueba\n");
}
