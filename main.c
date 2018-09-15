#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define TAM_MATRIZ 5
#define NUM_BARCOS 8
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define ESPACIO 32
#define AMARILLO 14
#define ROJO 4
#define VERDE 3
#define BLANCO 7
int main(int argc, char *argv[]) {
	int tabla1[TAM_MATRIZ][TAM_MATRIZ],tabla2[TAM_MATRIZ][TAM_MATRIZ];
	int i,j,posI,posJ,cursor_i = 0,cursor_j = 0,destru_i,destru_j,destruir = 0, turno = 1,fin = 0;
	char opcion;
	char tecla = 0;
	
	srand(time(0));//iniciar el rand
	do{
		system("cls");
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),BLANCO);
		printf("\n");
		printf("\n");
		printf("----Bienvenido a BATALLA NAVAL-----\n");
		printf("------------1. Jugar---------------\n");
		printf("--------2. Instrucciones-----------\n");
		printf("------------3. Salir---------------\n");
		fflush(stdin);
		opcion = getch();
		if(opcion == '1'){
			system("cls");
			//llenar matriz con 0
			for(i=0;i<TAM_MATRIZ;i++){
				for(j=0;j<TAM_MATRIZ;j++){
				 tabla1[i][j]=0;
				 tabla2[i][j]=0;
				}
			}
			
			//llenar matriz 1 con barcos
			for(i=0;i<NUM_BARCOS;i++){
				do{
					//generar posiciones aleatorias
					posI = rand()%(TAM_MATRIZ-1+1);
					posJ = rand()%(TAM_MATRIZ-1+1);
				}while(tabla1[posI][posJ] == 3);
				
				tabla1[posI][posJ] = 3;
			}
			//llenar matriz 2 con barcos
			for(i=0;i<NUM_BARCOS;i++){
				do{
					//generar posiciones aleatorias
					posI = rand()%(TAM_MATRIZ-1+1);
					posJ = rand()%(TAM_MATRIZ-1+1);
				}while(tabla2[posI][posJ] == 3);
				
				tabla2[posI][posJ] = 3;
			}
			
			//imprimir matriz 1
			for(i=0;i<TAM_MATRIZ;i++){
			 	for(j=0;j<TAM_MATRIZ;j++){
			 		if(i == cursor_i && j == cursor_j){
			 			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),AMARILLO);
			 			printf(" I ");
					 }
					 else{
					 	if(tabla1[i][j] == 0){
					 		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),BLANCO);
			 				printf(" - ");
						}
						if(tabla1[i][j] == 3){
							SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),VERDE);
							printf(" X ");
						}
					 }
			 		
				}
				printf("\n\n");
			}
		
			//juego
			tecla = 0;
			while(tecla != 'X' && fin != 1){
				fflush(stdin);
				tecla = getch();
				tecla = toupper(tecla);
				if(destruir == 1){
					destruir = 0;
					tecla = 0;
				}
				if(tecla == ARRIBA){
					if(cursor_i != 0){
						cursor_i--;
					}
				}
				if(tecla == ABAJO){
					if(cursor_i != TAM_MATRIZ-1){
						cursor_i++;
					}
				}
				if(tecla == DERECHA){
					if(cursor_j != TAM_MATRIZ-1){
						cursor_j++;
					}
				
				}
				if(tecla == IZQUIERDA){
					if(cursor_j != 0){
						cursor_j--;
					}
				
				}
				if(tecla == ESPACIO){
					destruir = 1;
					destru_i = cursor_i;
					destru_j = cursor_j;
				}
				system("cls");//limpia la pantalla
				if(turno == 1){
					//imprimir matriz 1
					for(i=0;i<TAM_MATRIZ;i++){
					 	for(j=0;j<TAM_MATRIZ;j++){
					 		if(i == cursor_i && j == cursor_j){
					 			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),AMARILLO);
					 			printf(" I ");
							 }
							 else{
							 	if(tabla1[i][j] == 0){
							 		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),BLANCO);
					 				printf(" - ");
								}
								if(tabla1[i][j] == 3){
									SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),VERDE);
									printf(" X ");
								}
								if(tabla1[i][j] == 4){
									SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),ROJO);
									printf(" X ");
								}
							 }
					 		
						}
						printf("\n\n");
					}
				}
				if(turno == 2){
					//imprimir matriz 2
					for(i=0;i<TAM_MATRIZ;i++){
					 	for(j=0;j<TAM_MATRIZ;j++){
					 		if(i == cursor_i && j == cursor_j){
					 			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),AMARILLO);
					 			printf(" I ");
							 }
							 else{
							 	if(tabla2[i][j] == 0){
							 		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),BLANCO);
					 				printf(" - ");
								}
								if(tabla2[i][j] == 3){
									SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),VERDE);
									printf(" Y ");
								}
								if(tabla2[i][j] == 4){
									SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),ROJO);
									printf(" Y ");
								}
							 }
					 		
						}
						printf("\n\n");
					}
				}
				if(destruir == 1){
						if(turno == 1){
							if(tabla2[cursor_i][cursor_j] == 3){
								tabla2[cursor_i][cursor_j] = 4;
								fin = 1;
								for(i=0;i<TAM_MATRIZ;i++){
									for(j=0;j<TAM_MATRIZ;j++){
										if(tabla2[i][j] == 3){
											fin = 0;
											i = TAM_MATRIZ;
											j = TAM_MATRIZ;
										}
									}
								}
								printf("Barco destruido en la posicion:(%d, %d)\n ",destru_i,destru_j);
								if(fin == 1){
									printf("Haz ganado jugador 1!!\n");
								}
							}
							else{
								printf("No destruyo ningun barco\n ");
							}
						}
						if(turno == 2){
							if(tabla1[cursor_i][cursor_j] == 3){
								tabla1[cursor_i][cursor_j] = 4;
								fin = 1;
								for(i=0;i<TAM_MATRIZ;i++){
									for(j=0;j<TAM_MATRIZ;j++){
										if(tabla1[i][j] == 3){
											fin = 0;
											i = TAM_MATRIZ;
											j = TAM_MATRIZ;
										}
									}
								}
								printf("Barco destruido en la posicion:(%d, %d)\n ",destru_i,destru_j);
								if(fin == 1){
									printf("Haz ganado jugador 2!!\n");
								}
							}
							else{
								printf("No destruyo ningun barco\n ");
							}
						}
						printf("presione una tecla para continuar");
						if(turno == 1){
							turno = 2;
						}
						else{
							turno = 1;
						}
						cursor_i = 0;
						cursor_j = 0;
						
				}
			
				
			}
		}
		if(opcion == '2'){
			system("cls");
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),BLANCO);
			printf("-Para moverse a traves del tablero use las flechas\n");
			printf("-Para escoger la posicion de destruir el barco enemigo presione la barra espaciadora\n");
			printf("-Para salirse del juego en cualquier momento presione la tecla X\n");
			printf("-Los barcos del jugador 1 estan representados por 'X' verde vivo, rojo muerto\n");
			printf("-Los barcos del jugador 2 estan representados por 'Y' verde vivo, rojo muerto\n");
			system("pause");
		}
		
	}while(opcion != '3');
	
	return 0;
}
