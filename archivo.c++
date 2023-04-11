#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
struct datos{
   int hora;
   char tratamiento[25];
   float precio;
}datos[100];
struct cliente{
   char nombre[25];
   int edad,telefono;
   struct datos tratamiento;
}cliente[100];
int main(){
   char auxiliarnom[20],auxiliartratamiento[20],maynom[25];
   int opcion,cant,categoria,finalrecaudado,precioalto,i,k,contadorpelu,contadorfacial,contadormanos,contadorpies,contadorcorpo,totaltratamientos,buscado,auxiliartel,auxiliaredad,flag;
   float auxiliarprecio;
   contadorpelu = 0;
   totaltratamientos = 0;
   contadorfacial = 0;
   contadormanos = 0;
   contadorpies = 0;
   categoria = 0;
   finalrecaudado = 0;
   contadorcorpo = 0;
   precioalto = 0;
   printf("ingrese la cantidad de clientes: ");
   scanf("%d",&cant);
   for(i = 0;i<cant;i++){
   printf("\nIngrese nombre:");
   scanf("%s",&cliente[i].nombre);
   fflush(stdin);
   printf("ingrese la edad: ");
   scanf("%d",&cliente[i].edad);
   printf("Ingrese su telefono: ");
   scanf("%d",&cliente[i].telefono);
   printf("\n1- Facial $5000\n");
   printf("2- Manos $1500\n");
   printf("3- Pies $2500\n");
   printf("4- Corporal $4400\n");
   printf("5- Peluqueria $1000\n");
   printf("ingrese el tratamiento a aplicar: ");
   scanf("%d",&categoria);
   switch(categoria){
      case 1:
         strcpy(cliente[i].tratamiento.tratamiento,"Facial");
         datos[i].precio = 5000;
         contadorfacial += 1;
         finalrecaudado +=5000;
         break;
      case 2:
         strcpy(cliente[i].tratamiento.tratamiento,"Manos");
         contadormanos += 1;
         datos[i].precio = 1500;
         finalrecaudado +=1500;

         break;
      case 3:
         strcpy(cliente[i].tratamiento.tratamiento,"Pies");
         contadorpies += 1;
         datos[i].precio = 2500;
         finalrecaudado +=2500;
         break;
      case 4:
         strcpy(cliente[i].tratamiento.tratamiento,"Corporal");
         contadorcorpo += 1;
         datos[i].precio = 4400;
         finalrecaudado +=4400;
         break;
      case 5:
         strcpy(cliente[i].tratamiento.tratamiento,"Peluqueria");
         contadorpelu += 1;
         datos[i].precio = 1000;
         finalrecaudado +=1000;
         break;
      default:
            break;
   }
   if(datos[i].precio > precioalto){
      precioalto = datos[i].precio;
      strcpy(maynom, cliente[i].nombre);
   }
   printf("Seleccione uno de los siguientes horarios: ");

   printf("\n1- 15hs\n");
   printf("2- 16hs\n");
   printf("3- 17hs\n");
   printf("4- 18hs\n");
   scanf("%d",&opcion);
   switch(opcion){
      case 1:
      datos[i].hora = 15;
      break;
      case 2:
      datos[i].hora = 16;
      break;
      case 3:
      datos[i].hora = 17;
      break;
      case 4:
      datos[i].hora = 18;
      break;
      default:
         break;
   }
   }
   printf("\nListado descendente por costo del tratamiento: ");
   for(i=0;i<cant;i++){
      for(k=0;k<cant;k++){
         if(datos[i].precio>datos[k].precio){
            strcpy(auxiliartratamiento,cliente[i].tratamiento.tratamiento);
            strcpy(cliente[i].tratamiento.tratamiento,cliente[k].tratamiento.tratamiento);
            strcpy(cliente[k].tratamiento.tratamiento,auxiliartratamiento);
            auxiliarprecio = datos[i].precio;
            datos[i].precio = datos[k].precio;
            datos[k].precio = auxiliarprecio;
            strcpy(auxiliarnom,cliente[i].nombre);
            strcpy(cliente[i].nombre,cliente[k].nombre);
            strcpy(cliente[k].nombre,auxiliarnom);
            auxiliaredad = cliente[i].edad;
            cliente[i].edad = cliente[k].edad;
            cliente[k].edad = auxiliaredad;
            auxiliartel = cliente[i].telefono;
            cliente[i].telefono = cliente[k].telefono;
            cliente[k].telefono = auxiliartel;
         }
      }
   }
   for(i=0;i<cant;i++){
      printf("\nNombre: %s  Edad: %d  Telefono: %d Tratamiento: %s  precio: %.2f\n",cliente[i].nombre,cliente[i].edad, cliente[i].telefono, cliente[i].tratamiento.tratamiento ,datos[i].precio);
   }

printf("\ningrese el horario a buscar: ");
scanf("%d",&buscado);
for(int i=0;i<cant;i++){
	if(buscado==datos[i].hora){
		printf("\nEl tratamiento a hacer es: %s de precio %.2f a la persona %s con edad %d con telefono: %d\n\n",cliente[i].tratamiento.tratamiento,datos[i].precio,cliente[i].nombre,cliente[i].edad,cliente[i].telefono);
      flag = 1;
	}
}
if(flag == 0){
   printf("NO hay tratamiento en la hora buscada\n");
}
   totaltratamientos = cant;
   printf("Cantidad de tratamientos en facial: %d\n",contadorfacial);
   printf("Cantidad de tratamientos en manos: %d\n",contadormanos);
   printf("Cantidad de tratamientos en Pies: %d\n",contadorpies);
   printf("Cantidad de tratamientos en Corporal: %d\n",contadorcorpo);
   printf("Cantidad de tratamientos en Peluqueria: %d\n",contadorpelu);
   printf("cantidad de tratamientos en el dia: %d\n",totaltratamientos);
   printf("Total recaudado en el dia: %d\n",finalrecaudado);
   printf("El tratamiento mas caro es: %d del cliente %s\n",precioalto,maynom);
   return 0;
}
 