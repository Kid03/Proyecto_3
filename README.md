# Proyecto_3
Proyecto 3 de Programacion 1

### 01 ###

## Inicio ##
Es programa que permite trabajar con un archivo que entrega facultades de una universidad (Por ahora con memoria estatica) para mostrar por pantalla una carrera y sus ponderados, hacer simulaciones de ingreso y mostrar las carreras y sus datos dentro de una misma facultad.
### Archivo de datos ###
El programa pide al usuaria ingresar el nombre del archivo con los datos, los cuales se deben presentar de la siguiente manera:

*Nombre_Facultad1
-Nombre_carrera0;ID;Nem;Rank;Leng;Mat;Hist;CS;Pond;PSU;Primo;Finale;C_PSU;C_Bea
-Nombre_carrera1;ID;Nem;Rank;Leng;Mat;Hist;CS;Pond;PSU;Primo;Finale;C_PSU;C_Bea
-Nombre_carrera2;ID;Nem;Rank;Leng;Mat;Hist;CS;Pond;PSU;Primo;Finale;C_PSU;C_Bea
-Nombre_carrera3;ID;Nem;Rank;Leng;Mat;Hist;CS;Pond;PSU;Primo;Finale;C_PSU;C_Bea
-Nombre_carrera4;ID;Nem;Rank;Leng;Mat;Hist;CS;Pond;PSU;Primo;Finale;C_PSU;C_Bea
*Nombre_Facultad2
-Nombre_carrera5;ID;Nem;Rank;Leng;Mat;Hist;CS;Pond;PSU;Primo;Finale;C_PSU;C_Bea
-Nombre_carrera6;ID;Nem;Rank;Leng;Mat;Hist;CS;Pond;PSU;Primo;Finale;C_PSU;C_Bea

Teniendo como objetivo que cada uno sea de los siguientes tipos:

*char[1024]
-char[1024];int;int;int;int;int;int;int;int;int;float;float;int;int

El "*" Señala el inicio de una facultad y el comienzo de otra facultad o el termino de archivo señala el termino de la facultad, mientras que "-" denota a las carreras y las carreras que esten bajo un "*" de facultad se dice que es parte de aquella facultad.

Los parametros tienes que ser cumplidos y no pueden aumentarse o disminuirse por no tener uso de memoria dinamica para ello.

Tienen un maximo de 20 facultades y 100 carreras, luego de esto el programa sera incapas de procesarlo por el uso de memoria  estatica.

### El programa ### 

El programa inicia creando un arreglo de "facultades" y "carreras" y luego dentro de una funcion los inicializa (colocar todos los parametros en valores que dentro de el programa se estimaran como nulos.
Pasan de esto, otra funcion se encargara de procesar el archivo de texto y rellenar los arreglos (Mientras que el archivo cumpla con los requicitos previamente especificados).
Para luego llegar al menu, y desplegar 4 opciones:

1.- Consultar ponderacion de una carrera
2.- Simular postulacion a una carrera
3.- Mostrar ponderaciones de una facultad
4.- Salir

Para cualquier otro ingreso (vease: "10","asdas","ad2342") en las opciones, el programa tendra error.

Las funciones de el menu aun estan en proceso de ser ideadas y seran actualizadas en la brevedad.

Por ahora el codigo solo tiene la base y servira como boseto o guia para el proceso.
