#include <stdio.h>
#include <stdlib.h>
#define columna 8
#define renglon 8

void reyna(int x, int y);
void rey(int x, int y);

int main (){

 int opcion = 0, a, b, c, d;

 while(1){
  printf("\n\t*** Tablero de ajedrez ***\t\n");
  printf("Elije entre las siguientes opciones y presiona enter\n");
  printf("1)Reyna.\n");
  printf("2)Rey.\n");
  printf("3)Salir.\n");
  scanf("%d",&opcion);

   switch(opcion){

    case 1:
     printf("Ingresa coordenada para [X] del 0 al 7 y presiona enter\n");
     scanf("%d",&a);
      while(a<0||a>7){
       printf("Número no válido\n");
       printf("Ingresa coordenada para [X] del 0 al 7 y presiona enter\n");
       scanf("%d", &a);
      }
     printf("Ingresa coordenada para [Y] del 0 al 7 y presiona enter\n");
     scanf("%d",&b);
      while(b<0||b>7){
       printf("Número no válido\n");
       printf("Ingresa coordenada para [Y] del 0 al 7 y presiona enter\n");
       scanf("%d", &b);
      }

     reyna(a, b);
     break;

    case 2:
     printf("Ingresa coordenada para [X] del 0 al 7 y presiona enter\n");
     scanf("%d",&c);
      while(c<0||c>7){
       printf("Número no válido\n");
       printf("Ingresa coordenada para [X] del 0 al 7 y presiona enter\n");
       scanf("%d", &c);
      }
     printf("Ingresa coordenada para [Y] del 0 al 7 y presiona enter\n");
     scanf("%d",&d);
      while(d<0||d>7){
       printf("Número no válido\n");
       printf("Ingresa coordenada para [Y] del 0 al 7 y presiona enter\n");
       scanf("%d", &d);
      }

     rey(c, d);
     break;

    case 3:
     return 0;
    default:
     printf("Opción no válida.\n");
   }
 }
return 0;
}

void reyna(int x, int y) {
  char arr[columna][renglon];
  char *Arr = &arr[0][0];

  // inicializar la matriz con 'X'
  for (int i = 0; i < columna * renglon; i++) {
    *(Arr + i) = 'X';
  }

  // colocar la reina
  *(Arr + x * renglon + y) = 'Q';

  // colocar posibles movimientos
  for (int i = 0; i < columna; i++) {
    for (int j = 0; j < renglon; j++) {
      if (abs(i - x) == abs(j - y)) {
        *(Arr + i * renglon + j) = '-';
      } else if (i == x || j == y) {
        *(Arr + i * renglon + j) = '|';
      }
    }
  }
  *(Arr + x * renglon + y) = 'Q';

  // imprimir la matriz
  for (int i = 0; i < columna; i++) {
    printf("\n");
    for (int j = 0; j < renglon; j++) {
      printf("%c  ", *(Arr + i * renglon + j));
    }
  }
}



void rey(int x, int y){

 char arr[columna][renglon];
 int i, j;

// inicializar la matriz con 'X'
 for(i=0;i<columna;i++){
  for(j=0;j<renglon;j++){
   arr[i][j] = 'X';
  }
 }
// colocar al rey 
 arr[x][y] = 'R';

// colocar posibles movimientos
 for(i=0;i<columna;i++){
  for(j=0;j<renglon;j++){
   if(i==x && y-1!=-1){
    arr[i][y-1] = '-';
   }
    if(i==x && y+1!=8){
     arr[i][y+1] = '-';
    }
     if(x-1!=-1 && j==y){
      arr[x-1][j] = '|';
     }
      if(x+1!=8 && j==y){
       arr[x+1][j] = '|';
      }
       if(abs(i-x)==1 && abs(j-y)==1){
        arr[i][j]= '-';
       }
  }
 }

 arr[x][y] = 'R';

// imprimir la matriz
 for(i=0;i<columna;i++){
  printf("\n"); 
  for(j=0;j<renglon;j++){
   printf("%c  ",arr[i][j]); 
  }
 }
}
