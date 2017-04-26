#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <string.h>

// Se definen las variables constantes a utilizar
#define Puntaje_Ganador 21
#define Largo_Matriz_Cartas 4
#define Ancho_Matriz_Cartas 14
#define Largo_Matriz_Cartas_Valores 4
#define Ancho_Matriz_Cartas_Valores 13
#define Maximo_Numero_Aleatorio_Fila 4
#define Maximo_Numero_Aleatorio_Columna 13

// Funcion para obtener el tamano de un arreglo
#define LargoArreglo(x)(sizeof(x) / sizeof((x)[0]))

// Se definen los prototipos de los metodos a utilizar
void menu_principal(void);
void inicializar_arreglos(void);
void parametros_juego(void);
void tabla_posiciones(void);
void datos_jugadores(void);
void usuario_vs_maquina(void);
void jugadores(void);
void instrucciones(void);
bool validar_nicknames_ingresados(void);
void empezar_juego(void);
void inicializando_juego(void);
bool validar_ganador(int jugador);
bool validar_perdedor(int jugador);
void inicializar_matrices_cartas(void);
void quitar_carta_baraja(int i, int j);
int numero_aleatorio_fila(void);
int numero_aleatorio_columna(void);
bool validar_si_hay_carta(int i, int j);
void juez_final_juego(void);
void reiniciar_puntos_jugadores(void);

// Se definen las variables necesarias
int numero=1;
int opcion=0;

// Arreglo para almacenar los nicknames de los jugadores
char* arregloNicknameJugadores[2];

// Arreglo para almacenar los puntajes para la tabla de posiciones de los jugadores
int arregloPuntajeTablaJugadores[2];

// Matriz para almacenar las cartas
char matrizCartas[Largo_Matriz_Cartas][Ancho_Matriz_Cartas];

// Matriz para almacenar los valores de las cartas
int matrizCartasValores[Largo_Matriz_Cartas_Valores][Ancho_Matriz_Cartas_Valores];

// Arreglo para almacenar los puntos obtenidos durante el juego
int arregloPuntosJugadores[2];

// Metodo principal
main()
{
	int espera=1;
	
	while(espera<4)
	{
		if(espera==1)
		{
			printf("Bienvenido(a) a Juego 21 - Blackjack\n\n");
	
			printf("Cargando.");
			espera++;
			Sleep(600);
			system("cls");
		}
		
		if(espera==2)
		{
			printf("Bienvenido(a) a Juego 21 - Blackjack\n\n");
			
			printf("Cargando..");
			espera++;
			Sleep(600);
			system("cls");
		}
		
		if(espera==3)
		{
			printf("Bienvenido(a) a Juego 21 - Blackjack\n\n");
			
			printf("Cargando...");
			espera++;
			Sleep(600);
			system("cls");
		}
	}
	
	system("cls");
	
	// Se inicializan los arreglos de nicknames y puntajes
	inicializar_arreglos();
	
	// Se inicializan las matrices de las cartas y de los valores de las cartas
	inicializar_matrices_cartas();
	
	// Se muestra el menu principal
	menu_principal();
}

// Metodo que permite mostrar el menu principal
void menu_principal()
{
	while (opcion!=5)
	{
		printf("Bienvenido(a) a Juego 21 - Blackjack\n\n");
		
		printf("Menu de opciones:\n\n");
		printf(" 1.Parametros de juego\n");
		printf(" 2.Iniciar juego\n");
		printf(" 3.Tabla de posiciones\n");
		printf(" 4.Instrucciones\n");
		printf(" 5.Salir\n\n");
		printf("Digite una opcion del menu: ");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 1:
			{
				system("cls");
				
				parametros_juego();
				
				break;
			}
			case 2:
			{
				system("cls");
				
				reiniciar_puntos_jugadores();
				
				inicializando_juego();
				
				break;
			}
			case 3:
			{
				system("cls");
				
				tabla_posiciones();
				
				break;
			}
			case 4:
			{
				system("cls");
				
				instrucciones();
				
				break;
			}
			case 5:
			{	
				printf("\nGracias por jugar, vuelva pronto.\n");
				
				// Con el exit(0) se indica que el programa finalizo satisfactoriamente
				exit(0);
				
				break;
			}
			default:
				system("cls");
				
				printf("Aviso: La opcion ingresada no es valida.\n\n");
				
				break;
		}
	}
}

// Metodo que permite mostrar los parametros de juego
void parametros_juego()
{
	int opcion=0;
	
	while(opcion!=2)
	{
		printf("Juego 21 - Blackjack\n\n");
		
		printf("Parametros\n\n");
		printf(" 1.Usuario vs Usuario\n\n");
		printf(" 2.Regresar\n\n");
		printf("Digite una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 1:
			{
				system("cls");
				
				datos_jugadores();
				
				system("pause");
				system("cls");
				
				break;
			}
			case 2:
			{
				system("cls");
				
				printf("Informacion: Regresando al menu principal...\n\n");
				
				menu_principal();
				
				break;
			}
			default:
				system("cls");
				
				printf("Aviso: La opcion ingresada no es valida.\n\n");
				
				break;
		}
	}
}

// Metodo que permite ingresar los nicknames de los jugadores
void datos_jugadores()
{
	char opcion=0;
	
	// Variables para almacenar los nicknames de los usuarios, los cuales posteriormente se almacenaran en un arreglo
	char jugador1[10];
	char jugador2[10];
	
	printf("Juego 21 - Blackjack\n\n");
	
	printf("Datos de jugadores\n\n");
	
	// Se obtienen los nombres de los jugadores
	printf("Digite el nickname del jugador 1 (maximo 10 caracteres): ");
	scanf("%s", &jugador1);
	
	// Si el nickname del jugador 2 es igual al nickname del jugador 1, se realiza un ciclo do while hasta que el nickname del jugador 2 sea distinto al nickname del jugador 1 
	do{
		printf("Digite el nickname del jugador 2 (maximo 10 caracteres): ");
		scanf("%s", &jugador2);
		
		// Si strcmp retorna 0 quiere decir que el nickname del jugador 2 es igual al nickname del jugador 1, por lo que se le muestra un mensaje al usuario
		// para este enterado que el nickname esta repetido, y que ingrese otro distinto
		if(strcmp(jugador1, jugador2) == 0){
			printf("\nAviso: El nickname del jugador 2, es igual al nickname del jugador 1, por favor ingrese un nickname distinto.\n\n");
		}
		
	} while(strcmp(jugador1, jugador2) == 0);
	
	// Se almacenan los nombres de los jugadores en el arreglo de nicknames
	arregloNicknameJugadores[0] = jugador1;
	arregloNicknameJugadores[1] = jugador2;
	
	// Se inicializan/reinician los puntajes de los jugadores en 0 en el arreglo de puntajes
	arregloPuntajeTablaJugadores[0] = 0;
	arregloPuntajeTablaJugadores[1] = 0;
	
	printf("\nLos jugadores ingresados son los siguientes: \n\n");
	printf("Jugador 1: %s\n", arregloNicknameJugadores[0]);
	printf("Jugador 2: %s\n\n", arregloNicknameJugadores[1]);
	
	system("pause");
	system("cls");
	
	while(opcion!=2)
	{
		printf("Juego 21 - Blackjack\n\n");
		
		printf("Opciones usuarios\n\n");
		printf(" 1.Volver a ingresar los jugadores\n\n");
		printf(" 2.Regresar al menu principal\n\n");
		printf("Digite una opcion: ");
		scanf("%d", &opcion);
		printf("\n");
		
		switch(opcion)
		{
			case 1:
			{
				system("cls");
				
				datos_jugadores();
				
				break;
			}
			case 2:
			{
				system("cls");
				
				printf("Informacion: Regresando al menu principal...\n\n");
				
				menu_principal();
				
				break;
			}
			default:
				system("cls");
				
				printf("Aviso: La opcion ingresada no es valida.\n\n");
				
				break;
		}
	}
	
}

// Metodo que permite visualizar la tabla de posiciones
void tabla_posiciones()
{
	int opcion=1;
	
	while(opcion!=0)
	{
		printf("Juego 21 - Blackjack\n\n");
		
		printf("Tabla de posiciones\n\n");
		
		// Si el puntaje del jugador 2 'arregloPuntajeTablaJugadores[1]' es mayor al puntaje del jugador 1 'arregloPuntajeTablaJugadores[0]'
		// entonces se coloca el jugador 2 como primero en la tabla de posiciones
		if(arregloPuntajeTablaJugadores[0] < arregloPuntajeTablaJugadores[1]){
			printf(" 1: %s | Puntaje: %d\n", arregloNicknameJugadores[1], arregloPuntajeTablaJugadores[1]);
			printf(" 2: %s | Puntaje: %d\n\n", arregloNicknameJugadores[0], arregloPuntajeTablaJugadores[0]);
		}else{
			// Si lo anterior no se cumple, quiere decir que el puntaje del jugador 1 es mayor, o que los puntajes son iguales,
			// en ambos casos entonces se coloca el jugaodr 1 como primero en la tabla de posiciones
			printf(" 1: %s | Puntaje: %d\n", arregloNicknameJugadores[0], arregloPuntajeTablaJugadores[0]);
			printf(" 2: %s | Puntaje: %d\n\n", arregloNicknameJugadores[1], arregloPuntajeTablaJugadores[1]);
		}
		
		printf(" 0.Regresar\n\n");
		printf("Digite una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 0:
			{
				system("cls");
		
				printf("Informacion: Regresando al menu principal...\n\n");
				
				break;
			}
			default:
				system("cls");
				
				printf("Aviso: La opcion ingresada no es valida.\n\n");
				
				break;
		}
	}
}

// Metodo que permite visualizar las intrucciones del juego
void instrucciones(){
	printf("Juego 21 - Blackjack\n\n");
	
	printf("Las instrucciones para poder jugar el juego son las siguientes:\n\n");
	printf("Gana el jugador que llegue primero a 21, o el que mas se le acerque.\n");
	printf("Sin embargo, aquel jugador que se pase de 21, pierde.\n\n");
	
	system("pause");
	
	system("cls");
	
	printf("Informacion: Regresando al menu principal...\n\n");
	
	menu_principal();
}

// Metodo que permite inicializar los arreglos de nicknames y de puntajes
void inicializar_arreglos(){
	int i, j;
	
	// Se inicializa el arreglo de nicknames con un string "Vacio", el cual se tiene que convertir a (char*)
	for(i=0; i<LargoArreglo(arregloNicknameJugadores); i++){
		arregloNicknameJugadores[i] = (char*)"Vacio";
	}
	
	// Se inicializa el arreglo de puntajes de la tabla de posiciones en 0
	for(j=0; i<LargoArreglo(arregloPuntajeTablaJugadores); j++){
		arregloPuntajeTablaJugadores[i] = 0;
	}
}

// Metodo que retorna true en caso de que se hayan ingresado los nicknames de los jugadores, false en caso contrario
bool validar_nicknames_ingresados(){
	char* jugador1;
	char* jugador2;
	
	jugador1 = arregloNicknameJugadores[0];
	jugador2 = arregloNicknameJugadores[1];
	
	// Se consulta si el nickname del jugador 1 esta "Vacio", y si el nickname del jugador 2 esta "Vacio",
	// si estan vacio ambos, quiere decir de que el usuario no ha ingresado los nicknames para ambos jugadores
	if((strcmp(jugador1, "Vacio") == 0) and (strcmp(jugador2, "Vacio") == 0)){
		return true;
	}
	else{
		return false;
	}
}

// Metodo que permite validar el inicio del juego, para ver si es posible iniciar
void inicializando_juego(){
	bool validacion_nicknames = validar_nicknames_ingresados();
	
	system("cls");
	
	printf("Juego 21 - Blackjack\n\n");
	
	// Se valida si los nicknames de los usuarios fueron ingresados, de no ser asi, entonces se le muestra un mensaje la usuario
	if(validacion_nicknames == true){
		printf("Aviso: Aun no se han ingresado los nicknames de los jugadores, debe ingresarlos para poder iniciar el juego.\n\n");
		
		system("pause");
		
		system("cls");
		
		printf("Informacion: Regresando al menu principal...\n\n");
		
		menu_principal();
	}
	else{
		system("cls");
		
		empezar_juego();
	}
}

// Metodo que permite empezar a jugar
void empezar_juego(){
	char* jugador1;
	char* jugador2;
	jugador1 = arregloNicknameJugadores[0];
	jugador2 = arregloNicknameJugadores[1];
	
	char* cartasJugador1;
	char* cartasJugador2;
	
	bool jugador1SeQuedo = false;
	bool jugador2SeQuedo = false;
	
	int i, j;
	int numeroAleatorioFila, numeroAleatorioColumna, codigoSimboloCarta;
	
	int turno = 1;
	
	int opcionJugador1 = 0;
	int opcionJugador2 = 0;
	
	printf("Juego 21 - Blackjack\n\n");
	
	printf("Jugadores: %s vs %s\n\n", jugador1, jugador2);
	
	printf("----------------- Turno %d -----------------\n\n", turno);
	
	printf("Jugador 1: %s\n\n", arregloNicknameJugadores[0]);
	printf("Cartas: ");
	
	// Se reparten dos cartas inicialmente al jugador 1
	for(i=0; i<2; i++){
		// Se obtiene el numero aleatorio de fila y de columna
		numeroAleatorioFila = numero_aleatorio_fila();
		numeroAleatorioColumna = numero_aleatorio_columna();
		
		// Mientras no haya una carta en la fila y de columna obtenidas aleatoriamente, volver a solicitar otro numero fila y de columna aleatoriamente
		while(validar_si_hay_carta(numeroAleatorioFila, numeroAleatorioColumna) != true){
			numeroAleatorioFila = numero_aleatorio_fila();
			numeroAleatorioColumna = numero_aleatorio_columna();
		}
		
		// Se obtiene el simbolo de la carta
		codigoSimboloCarta = numeroAleatorioFila + 3;
		
		// Se suman los puntos al arreglo de puntos del jugador 1
		arregloPuntosJugadores[0] += matrizCartasValores[numeroAleatorioFila][numeroAleatorioColumna];
		
		// Se muestra la carta en pantalla
		
		// Si la carta 'matrizCartas[numeroAleatorioFila][numeroAleatorioColumna]' es un '0', quiere decir que es un '10', por lo que se le concatena un '1' al inicio
		if(matrizCartas[numeroAleatorioFila][numeroAleatorioColumna] == '0'){
			printf("1%c%c", matrizCartas[numeroAleatorioFila][numeroAleatorioColumna], codigoSimboloCarta);
		}else{
			printf("%c%c", matrizCartas[numeroAleatorioFila][numeroAleatorioColumna], codigoSimboloCarta);
		}
		
		// Se quita la carta de la baraja para no volverla a tomar en cuenta
		quitar_carta_baraja(numeroAleatorioFila, numeroAleatorioColumna);
		
		// Se agrega un espacio entre la primera y la segunda carta
		printf(" ");
	}
	
	// Se muestra en pantalla el puntaje para el jugador 1, de las dos primeras cartas
	printf("\nPuntaje total: %d\n\n", arregloPuntosJugadores[0]);
	
	printf("Jugador 2: %s\n\n", arregloNicknameJugadores[1]);
	printf("Cartas: ");
	
	// Se reparten dos cartas inicialmente al jugador 2
	for(i=0; i<2; i++){
		// Se obtiene el numero aleatorio de fila y de columna
		numeroAleatorioFila = numero_aleatorio_fila();
		numeroAleatorioColumna = numero_aleatorio_columna();
		
		// Mientras no haya una carta en la fila y de columna obtenidas aleatoriamente, volver a solicitar otro numero fila y de columna aleatoriamente
		while(validar_si_hay_carta(numeroAleatorioFila, numeroAleatorioColumna) != true){
			numeroAleatorioFila = numero_aleatorio_fila();
			numeroAleatorioColumna = numero_aleatorio_columna();
		}
		
		// Se obtiene el simbolo de la carta
		codigoSimboloCarta = numeroAleatorioFila + 3;
		
		// Se suman los puntos al arreglo de puntos del jugador 2
		arregloPuntosJugadores[1] += matrizCartasValores[numeroAleatorioFila][numeroAleatorioColumna];
		
		// Se muestra la carta en pantalla
		
		// Si la carta 'matrizCartas[numeroAleatorioFila][numeroAleatorioColumna]' es un '0', quiere decir que es un '10', por lo que se le concatena un '1' al inicio
		if(matrizCartas[numeroAleatorioFila][numeroAleatorioColumna] == '0'){
			printf("1%c%c", matrizCartas[numeroAleatorioFila][numeroAleatorioColumna], codigoSimboloCarta);
		}else{
			printf("%c%c", matrizCartas[numeroAleatorioFila][numeroAleatorioColumna], codigoSimboloCarta);
		}
		
		// Se quita la carta de la baraja para no volverla a tomar en cuenta
		quitar_carta_baraja(numeroAleatorioFila, numeroAleatorioColumna);
		
		// Se agrega un espacio entre la primera y la segunda carta
		printf(" ");
	}
	
	// Se aumenta el contador del turno
	turno++;
	
	// Se muestra en pantalla el puntaje para el jugador 1, de las dos primeras cartas
	printf("\nPuntaje total: %d\n\n", arregloPuntosJugadores[1]);
	
	// Se inicia el ciclo de do while
	do{
		printf("----------------- Turno %d -----------------\n\n", turno);
		
		// Si el jugador 1 no se ha "quedado", entonces se le presenta el menu para que seleccione si quiere otra carta, o desearse con las que tiene
		if(jugador1SeQuedo == false){
			printf("Jugador 1: %s\n\n", arregloNicknameJugadores[0]);
			printf(" 1.Desea otra carta?\n\n");
			printf(" 2.Desea quedarse?\n\n");
			printf("Digite una opcion: ");
			scanf("%d", &opcionJugador1);
			
			switch(opcionJugador1)
			{
				case 1:
				{
					// Se obtiene el numero aleatorio de fila y de columna
					numeroAleatorioFila = numero_aleatorio_fila();
					numeroAleatorioColumna = numero_aleatorio_columna();
					
					// Mientras no haya una carta en la fila y de columna obtenidas aleatoriamente, volver a solicitar otro numero fila y de columna aleatoriamente
					while(validar_si_hay_carta(numeroAleatorioFila, numeroAleatorioColumna) != true){
						numeroAleatorioFila = numero_aleatorio_fila();
						numeroAleatorioColumna = numero_aleatorio_columna();
					}
					
					// Se obtiene el simbolo de la carta
					codigoSimboloCarta = numeroAleatorioFila + 3;
					
					// Se suman los puntos al arreglo de puntos del jugador 1
					arregloPuntosJugadores[0] += matrizCartasValores[numeroAleatorioFila][numeroAleatorioColumna];
					
					// Se muestra la carta en pantalla
		
					// Si la carta 'matrizCartas[numeroAleatorioFila][numeroAleatorioColumna]' es un '0', quiere decir que es un '10', por lo que se le concatena un '1' al inicio
					if(matrizCartas[numeroAleatorioFila][numeroAleatorioColumna] == '0'){
						printf("\nCarta: 1%c%c\n", matrizCartas[numeroAleatorioFila][numeroAleatorioColumna], codigoSimboloCarta);
					}else{
						printf("\nCarta: %c%c\n", matrizCartas[numeroAleatorioFila][numeroAleatorioColumna], codigoSimboloCarta);
					}
					
					// Se quita la carta de la baraja para no volverla a tomar en cuenta
					quitar_carta_baraja(numeroAleatorioFila, numeroAleatorioColumna);
	
					// Se muestra en pantalla el puntaje para el jugador 1, de las dos primeras cartas
					printf("Puntaje total: %d\n\n", arregloPuntosJugadores[0]);
					
					break;
				}
				case 2:
				{
					jugador1SeQuedo = true;
					
					// Si el jugador 2 no se ha quedado, entonces se le presenta el siguiente mensaje al jugador 1
					if((jugador2SeQuedo == false) and (arregloPuntosJugadores[1] < 21)){
						printf("\nInformacion: Debe esperar a que el jugador 2 termine de jugar.\n\n");
					}
					
					break;
				}
				default:
					printf("\n\nAviso: La opcion ingresada no es valida.\n\n");
					
					break;
			}
		}
		
		// Si el jugador 2 no se ha "quedado", entonces se le presenta el menu para que seleccione si quiere otra carta, o desearse con las que tiene
		if(jugador2SeQuedo == false){
			printf("Jugador 2: %s\n\n", arregloNicknameJugadores[1]);
			printf(" 1.Desea otra carta?\n\n");
			printf(" 2.Desea quedarse?\n\n");
			printf("Digite una opcion: ");
			scanf("%d", &opcionJugador2);
			
			switch(opcionJugador2)
			{
				case 1:
				{
					// Se obtiene el numero aleatorio de fila y de columna
					numeroAleatorioFila = numero_aleatorio_fila();
					numeroAleatorioColumna = numero_aleatorio_columna();
					
					// Mientras no haya una carta en la fila y de columna obtenidas aleatoriamente, volver a solicitar otro numero fila y de columna aleatoriamente
					while(validar_si_hay_carta(numeroAleatorioFila, numeroAleatorioColumna) != true){
						numeroAleatorioFila = numero_aleatorio_fila();
						numeroAleatorioColumna = numero_aleatorio_columna();
					}
					
					// Se obtiene el simbolo de la carta
					codigoSimboloCarta = numeroAleatorioFila + 3;
					
					// Se suman los puntos al arreglo de puntos del jugador 2
					arregloPuntosJugadores[1] += matrizCartasValores[numeroAleatorioFila][numeroAleatorioColumna];
					
					// Se muestra la carta en pantalla
		
					// Si la carta 'matrizCartas[numeroAleatorioFila][numeroAleatorioColumna]' es un '0', quiere decir que es un '10', por lo que se le concatena un '1' al inicio
					if(matrizCartas[numeroAleatorioFila][numeroAleatorioColumna] == '0'){
						printf("\nCarta: 1%c%c\n", matrizCartas[numeroAleatorioFila][numeroAleatorioColumna], codigoSimboloCarta);
					}else{
						printf("\nCarta: %c%c\n", matrizCartas[numeroAleatorioFila][numeroAleatorioColumna], codigoSimboloCarta);
					}
					
					// Se quita la carta de la baraja para no volverla a tomar en cuenta
					quitar_carta_baraja(numeroAleatorioFila, numeroAleatorioColumna);
	
					// Se muestra en pantalla el puntaje para el jugador 1, de las dos primeras cartas
					printf("Puntaje total: %d\n\n", arregloPuntosJugadores[1]);
					
					break;
				}
				case 2:
				{
					jugador2SeQuedo = true;
					
					// Si el jugador 1 no se ha quedado, entonces se le presenta el siguiente mensaje al jugador 1
					if((jugador1SeQuedo == false) and (arregloPuntosJugadores[0] < 21)){
						printf("\nInformacion: Debe esperar a que el jugador 1 termine de jugar.\n\n");
					}
					
					break;
				}
				default:
					printf("\n\nAviso: La opcion ingresada no es valida.\n\n");
					
					break;
			}
		}
		
		// Se reinician las opciones de los jugadores
		opcionJugador1 = 0;
		opcionJugador2 = 0;
		
		// Se valida si alguno de los dos jugadores ganaron
		if(validar_ganador(1) || validar_ganador(2)){
			juez_final_juego();
			
			break;
		}
		
		// Se valida si alguno de los dos jugadores perdieron
		if(validar_perdedor(1) || validar_perdedor(2)){
			juez_final_juego();
			
			break;
		}
		
		// Se aumenta el contador del turno
		turno++;
		
	}while(jugador1SeQuedo == false || jugador2SeQuedo == false); // Este ciclo do while se ejecuta mientras que alguno de los dos jugadores no se haya quedado 'bandera', si ambos se quedaron finaliza
	
	// Al finalizar el ciclo do while, se muestra el metodo de juez, el cual muestra el resultado final
	juez_final_juego();
}

// Metodo que valida si un jugador logro obtener 21 en el juego
bool validar_ganador(int jugador){
	bool gano = false;
	
	// Como el indice inicia en 0, entonces se le tiene que restar 1 al jugador que se recibe como parametro
	int indiceRealJugador = jugador - 1;
	
	// Se consulta si los puntos del jugador son iguales a 21
	if(arregloPuntosJugadores[indiceRealJugador] == Puntaje_Ganador){
		return true;
	}
	else{
		return false;
	}
}

// Metodo que valida si un jugador se paso de 21 en el juego
bool validar_perdedor(int jugador){
	bool gano = false;
	
	// Como el indice inicia en 0, entonces se le tiene que restar 1 al jugador que se recibe como parametro
	int indiceRealJugador = jugador - 1;
	
	// Se consulta si los puntos del jugador son mayores a 21
	if(arregloPuntosJugadores[indiceRealJugador] > Puntaje_Ganador){
		return true;
	}
	else{
		return false;
	}
}

// Metodo que inicializa las matrices de las cartas
void inicializar_matrices_cartas(){
	// Se crea un char con los valores de las cartas, el '0' posteriormente se interpretara como '10'
	char mazoCartas[] = "A234567890JQK";
	int i, j;
	
	// Se inicializa la matriz que contiene las cartas con su simbolo
	for(i=0; i<Largo_Matriz_Cartas; i++)
	{
		for(j=0; j<Ancho_Matriz_Cartas; j++)
		{
			// En la posicion 'i,j' de la matriz se asigna la letra en la posicion 'j' de la variable 'mazoCartas'
			matrizCartas[i][j] = mazoCartas[j];
		}
	}
	
	// Se agregan las iniciales de los simbolos de las cartas a cada fila
	matrizCartas[0][13] = 'C'; // Corazones
	matrizCartas[1][13] = 'D'; // Diamantes
	matrizCartas[2][13] = 'T'; // Treboles
	matrizCartas[3][13] = 'B'; // Basto
	
	// Se crea un arreglo en donde se almacenan los valores de las cartas para posteriormente agregar los valores a la matriz
	int valoresCartas[Ancho_Matriz_Cartas_Valores] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
	
	// Se inicializa la matriz espejo que contiene el valor de cada carta
	for(i=0; i<Largo_Matriz_Cartas_Valores; i++)
	{
		for(j=0; j<Ancho_Matriz_Cartas_Valores; j++)
		{
			matrizCartasValores[i][j] = valoresCartas[j];
		}
	}
}

// Metodo que quita una carta dada de la baraja
void quitar_carta_baraja(int i, int j){
	// El guion bajo representa que no hay carta en esa posicion
	matrizCartas[i][j] = '_';
}

// Metodo que devuelve un numero aleatorio de fila, entre 0 y 3
int numero_aleatorio_fila(){
	// Se genera un numero aleatorio entre 0 y 3, el cual sera para las filas
	int numeroGenerado = rand() % Maximo_Numero_Aleatorio_Fila;
	return numeroGenerado;
}

// Metodo que devuelve un numero aleatorio de columna, entre 0 y 13
int numero_aleatorio_columna(){
	// Se genera un numero aleatorio entre 0 y 13, el cual sera para las columnas
	int numeroGenerado = rand() % Maximo_Numero_Aleatorio_Columna;
	return numeroGenerado;
}

// Metodo que retorna true si hay carta en la posicion indicada, false en caso contrario
bool validar_si_hay_carta(int i, int j){
	// Se consulta el valor de la matriz para la posicion 'i' y posicion 'j', si es un guion bajo el valor obtenido,
	// quiere decir de que ya esa carta fue tomada, por lo que ya no hay una carta en esa posicion
	if(matrizCartas[i][j] == '_'){
		return false;
	}
	else{
		return true;
	}
}

// Metodo que muestra el mensaje final a los jugadores, donde indica quien gano la partida
void juez_final_juego(){
	int puntajeJugador1 = arregloPuntosJugadores[0];
	int puntajeJugador2 = arregloPuntosJugadores[1];
	char* jugador1 = arregloNicknameJugadores[0];
	char* jugador2 = arregloNicknameJugadores[1];

	printf("\n-------------- Fin del juego --------------\n\n");
	
	// Si el puntaje del jugador 1 es menor o igual a 21, pero es mayor al puntaje del jugador 2, entonces se le asignan los 10 puntos
	if((puntajeJugador1 <= Puntaje_Ganador) && puntajeJugador1 > puntajeJugador2){
		printf("Felicidades %s, usted ha sido el ganador.\n\n", jugador1);
		
		arregloPuntajeTablaJugadores[0] += 10;
		
	// Si el puntaje del jugador 2 es menor o igual a 21, pero es mayor al puntaje del jugador 1, entonces se le asignan los 10 puntos
	} else if((puntajeJugador2 <= Puntaje_Ganador) && puntajeJugador2 > puntajeJugador1){
		printf("Felicidades %s, usted ha sido el ganador.\n\n", jugador2);
		
		arregloPuntajeTablaJugadores[1] += 10;
		
	// Si el puntaje del jugador 1 es menor o igual a 21, y si el puntaje del jugador 2 es menor o igual a 21, y ademas ambos puntajes son
	// iguales, entonces se le asignan los 5 puntos a ambos
	} else if((puntajeJugador1 <= Puntaje_Ganador && puntajeJugador2 <= Puntaje_Ganador) && puntajeJugador1 == puntajeJugador2){
		printf("Bien jugado %s y %s, ha sido un empate.\n\n", jugador1, jugador2);
		
		arregloPuntajeTablaJugadores[0] += 5;
		arregloPuntajeTablaJugadores[1] += 5;
		
	// Si el puntaje del jugador 1 es mayor a 21, y el puntaje del jugador 2 es menor o igual a 21, entonces se le asignan los 10 puntos al jugador 2
	} else if((puntajeJugador1 > Puntaje_Ganador) && (puntajeJugador2 <= Puntaje_Ganador)){
		printf("Felicidades %s, usted ha sido el ganador.\n\n", jugador2);
		
		arregloPuntajeTablaJugadores[1] += 10;
		
	// Si el puntaje del jugador 2 es mayor a 21, y el puntaje del jugador 1 es menor o igual a 21, entonces se le asignan los 10 puntos al jugador 1
	} else if((puntajeJugador2 > Puntaje_Ganador) && (puntajeJugador1 <= Puntaje_Ganador)){
		printf("Felicidades %s, usted ha sido el ganador.\n\n", jugador1);
		
		arregloPuntajeTablaJugadores[0] += 10;
		
	// Si el puntaje del jugador 1 es mayor a 21, y si el puntaje del jugador 2 es mayor a 21, entonces han jugadores han perdido
	} else if((puntajeJugador1 > Puntaje_Ganador) && (puntajeJugador2 > Puntaje_Ganador)){
		printf("Lo sentimos %s y %s, ambos han perdido.\n\n", jugador1, jugador2);
	}
	
	system("pause");
	
	system("cls");
	
	// Se reinician las matrices de las cartas y de los valores de las cartas
	inicializar_matrices_cartas();
	
	// Se regresa al menu principal
	menu_principal();
}

// Metodo que reinicia los puntajes de los jugadores a 0
void reiniciar_puntos_jugadores(){
	arregloPuntosJugadores[0] = 0;
	arregloPuntosJugadores[1] = 0;
}

