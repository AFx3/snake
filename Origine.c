#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //scanf, prinf
#include <conio.h> //kbhit, system 
#include <stdlib.h> //rand
int larghezza = 20, altezza = 20; //variabili campo da gioco
int x, y, fruttoX, fruttoY,punteggio, gameover,casistica; //variabili per il setup del gioco
int contaCoda=0;
int codaX[100]; //strutture dati utilizzati per unire + dati semplici dello stesso tipo, ogni elemento è identificato da un indice, numero elem=dimensione
int codaY[100]; //l'allocazione in memoria avviene nello heap, dimensione di esso definita a runtime
void impostazioni() //procedura per il setup del gioco 22222
{
	x = larghezza / 2; //x e y vengono assegnate a metà altezza e larghezza per far si che compaiano le variabi correttamente nel campo di gioco
	y = altezza / 2;
	gameover = 0; //per poter giocare nuovamente

	do {
		fruttoX = rand() % 20;//dentro il campo da gioco
	} while (fruttoX == 0);
	

	do { 
		fruttoY = rand() % 20;
	} while (fruttoY == 0);
		
}	
void campo()  //definisco procedura per il gioco 111111111
{
	int i, j,k;  // i= larghezza, j = altezza, k indice per array
	system("cls");
	for (i = 0; i < larghezza; i++)
	{
		for (j = 0; j < altezza; j++) 
		{
			if (i==0 || i==altezza-1 ||j==0 || j==larghezza-1) //-1 per far vedere i bordi del campo correttamente
			{
				printf("*");
			}
			else
			{
				if (i == x && j == y) //testa del serpente
					printf("O");
				else if (i == fruttoX && j == fruttoY)
					printf("@");

				else 
				{
					int ch = 0;
					for (k = 0; k < contaCoda; k++) //i,j  cotacona inizializzato a zero
					{
						if (i == codaX[k] && j == codaY[k]) 
						{
							printf("o"); //codina del serpente
							ch = 1;
						}
					}
					if (ch == 0)
						printf(" "); //spazio vuoto
				}
			}
		}
		printf("\n");
	}
	printf("--------------------\n");
	printf("\nPUNTEGGIO=%d", punteggio);
}

void input() // movimento
{
	if (_kbhit())
	{
		switch (getch()) //permette di ottenere il codice ascii associato all pressione del tasto
		{
		case 'a': //aswd
			casistica = 1;
			break;
		case 's':
			casistica = 2;
			break;
		case 'w':
			casistica = 3;
			break;
		case 'd':
			casistica = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}
void logicaArray()
{
	int i;
	int prevX = codaX[0];
	int prevY = codaY[0];
	int prev2X, prev2Y;
	codaX[0] = x;
	codaY[0] = y;

	for (i = 1; i < contaCoda; i++)
	{
		prev2X = codaX[i];
		prev2Y = codaY[i];
		codaX[i] = prevX;
		codaY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (casistica)
	{
	case 1: //a sx
		y--;
		break;
	case 2: //s giu
		x++;
		break;
	case 3: // w su
		x--;
		break;
	case 4: //d dx
		y++;
		break;
	default:
		break;
	}
	if (x<0 || x>larghezza || y<0 || y>altezza) //fine gioco quando tocco il bordo
		gameover = 1;
	for (i = 0; i < contaCoda; i++) //fine gioco quando si tocca la coda da solo
	{
		if (x == codaX[i] && y == codaY[i])
			gameover = 1;
	}
	if (x == fruttoX && y == fruttoY) //fa ricomparire un frutto random quando viene mangiato incrementando punteggio e coda
	{
		do {
			fruttoX = rand() % 20;
		} while (fruttoX == 0);
		do {
			fruttoY = rand() % 20;
		} while (fruttoY == 0);
		punteggio =punteggio + 10;
		contaCoda++;
	}
	
}
int main() 
{
	int m, n;
	char rigioca;
	
		do {
			impostazioni();
			while (!gameover)
			{
				campo();
				input();
				logicaArray();
				for (m = 0; m < 1000; m++)
				{
					for (n = 0; n < 10000; n++)
					{
					}
				}
				for (m = 0; m < 1000; m++)
				{
					for (n = 0; n < 10000; n++)
					{
					}
				}

			}
			printf("\nPremi la spacebar se vuoi giocare ancora :)");
			scanf("%c", &rigioca);
			punteggio = 0;
			contaCoda = 0;

		} while (rigioca == ' ');
		return 0;
}
