#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "Console.h"

#include "jogo.h"
#include "gameOver.h"

#include <Windows.h>

#define DIREITA 0
#define ESQUERDA 1

#define ZUMBIDIREITA 0
#define ZUMBIESQUERDA 1

#define ZUMBIDIREITA2 0
#define ZUMBIESQUERDA2 1

int modoJogo = 1;

jogo::jogo()
{
	init();
}

void jogo::init()
{
	acaoSamurai = DIREITA;
	acaZumbi = ZUMBIESQUERDA;
	acaZumbi2 = ZUMBIESQUERDA;

	do
	{
		update();
		if (modoJogo == 1) draw();
		Sleep(100);
	} while (inicioJogo);
}

void jogo::update()
{
	if (atacando)
	{
		atacando = false;
		draw();

	}
	if (kbhit())
	{
		teclaJogo = getch();
		if (teclaJogo == 27)
		{
			inicioJogo = false;
		}

		if (teclaJogo == 97)
		{
			if (posicaoSamuraiX + 10 > 15)
			{
				acaoSamurai = ESQUERDA;
				posicaoSamuraiX -= velocidadeSamurai;
			}
			

		}

		if (teclaJogo == 100)
		{
			if (posicaoSamuraiX + 10 < (90 - 10))
			{
				acaoSamurai = DIREITA;
				posicaoSamuraiX += velocidadeSamurai;

			}

		}

		if (teclaJogo == 32 && !atacando)
		{
			
			parado = false;
			atacando = true;
			if (posicaoSamuraiX + 10 >= zumbiX)
			{
				zumbiVida -= 1;
				if (zumbiVida <= 0)
				{
					corZumbi = FOREGROUND_RED;
				}
				draw();

			}
			else 
			{
				draw();
			}
				
				
			if(posicaoSamuraiX + 10 >= zumbi2X)
			{
				zumbi2Vida -= 1;
				if (zumbi2Vida <= 0)
				{
					corZumbi2 = FOREGROUND_RED;
				}
				draw();
			}
			else
			{
				draw();
			}
			parado = true;
		}

		if (teclaJogo == 119 && !saltou)
		{
			saltou = true;
			if (posicaoSamuraiX + 10 >= floor2X && posicaoSamuraiY + 8 == floor2Y)
			{
				posicaoSamuraiY -= 8;
				
			}
			else
			{
				posicaoSamuraiY -= 14;

			}
		}



	}


	if (zumbiVida > 0)
	{

		if (zumbiX + 10 <= 50 && andando == 0)
		{
			zumbiX += velocidadezumbi;
			acaZumbi = ZUMBIDIREITA;

			if (zumbiX + 10 >= 50)
			{
				andando = 1;
			}
		}

		if (zumbiX + 10 >= 35 && andando == 1)
		{
			zumbiX -= velocidadezumbi;
			acaZumbi = ZUMBIESQUERDA;

			if (zumbiX + 10 <= 35)
			{
				andando = 0;
			}

		}

		if (!atacando && posicaoSamuraiX + 5 >= zumbiX && posicaoSamuraiY + 5 >= zumbiY)
		{
			samuraiVida -= 1;

			posicaoSamuraiX -= 7;
			draw();


		}

	}
	else
	{
		if (posicaoSamuraiX + 5 >= zumbiX && posicaoSamuraiY == zumbiY && countZ1 == 0)
		{
			countZ1++;
			countS += 10;
		}

	}

	if (zumbi2Vida > 0)
	{

		if (zumbi2X + 10 <= 82 && andando2 == 0)
		{
			zumbi2X += velocidadezumbi2;
			acaZumbi2 = ZUMBIDIREITA2;

			if (zumbi2X + 10 >= 82)
			{
				andando2 = 1;
			}
		}

		if (zumbi2X + 10 >= 60 && andando2 == 1)
		{
			zumbi2X -= velocidadezumbi2;
			acaZumbi2 = ZUMBIESQUERDA2;

			if (zumbi2X + 10 <= 60)
			{
				andando2 = 0;
			}

		}

		if (!atacando && posicaoSamuraiX + 5 >= zumbi2X && posicaoSamuraiY + 5 >= zumbi2Y)
		{
			samuraiVida -= 1;

			posicaoSamuraiX -= 7;
			draw();


		}

	}
	else
	{
		if (posicaoSamuraiX + 5 >= zumbi2X && posicaoSamuraiY == zumbi2Y && countZ2 == 0)
		{
			countZ2++;
			countS += 10;
		}

	}

	if (posicaoSamuraiX + 7 >= floor2X)
	{
		if (posicaoSamuraiY + 8 < floor2Y)
		{
			posicaoSamuraiY++;
		}
		else
		{
			saltou = false;
		}

	}
	else
	{

		if (posicaoSamuraiY + 8 < floor)
		{
			posicaoSamuraiY++;

		}
		else
		{
			saltou = false;
		}
	}

	if (samuraiVida <= 0)
	{
		modoJogo = 3;
		gameOver gameOverInit(countS);

	}

	if (posicaoSamuraiX + 5 >= portaX && posicaoSamuraiY == portaY)
	{
		modoJogo = 3;
		gameOver gameOverInit(countS);

	}
}

void jogo::draw()
{
	clrscr();

	char ** samurai;
	samurai = (char **)malloc(sizeof(char *) * 8);

	for (int i = 0; i < 8; i++) {
		samurai[i] = (char *)malloc(sizeof(char) * 10);
	}

	if (parado && acaoSamurai == DIREITA)
	{
		samurai[0] = "    #@#  ";
		samurai[1] = "  #@@@@@#";
		samurai[2] = "    @@$  ";
		samurai[3] = "   @@@@  ";
		samurai[4] = "   @@@@@@";
		samurai[5] = "$@@@@@@  ";
		samurai[6] = "   @@@@  ";
		samurai[7] = "  @@@@@@#";
	}

	if (parado && acaoSamurai == ESQUERDA)
	{
		samurai[0] = "  #@#    ";
		samurai[1] = "#@@@@@#  ";
		samurai[2] = "  $@@    ";
		samurai[3] = "  @@@@   ";
		samurai[4] = "@@@@@@   ";
		samurai[5] = "  @@@@@@$";
		samurai[6] = "  @@@@   ";
		samurai[7] = "#@@@@@@  ";
	}


	if (atacando && acaoSamurai == DIREITA)
	{
		samurai[0] = "  #@#    ";
		samurai[1] = "#@@@@@#  ";
		samurai[2] = "  @@$   @";
		samurai[3] = " @@@@  @ ";
		samurai[4] = " @@@@@@  ";
		samurai[5] = " @@@@    ";
		samurai[6] = " @@@@    ";
		samurai[7] = "@@@@@@#  ";
	}

	if (atacando && acaoSamurai == ESQUERDA)
	{
		samurai[0] = "    #@#  ";
		samurai[1] = "  #@@@@@#";
		samurai[2] = "@   $@@  ";
		samurai[3] = " @  @@@@ ";
		samurai[4] = "  @@@@@@ ";
		samurai[5] = "    @@@@ ";
		samurai[6] = "    @@@@ ";
		samurai[7] = "  #@@@@@@";
	}

	char especialChS = ' ';

	for (int i = 0; i < 8; i++) {
		for (int a = 0; a < 10; a++) {
			especialChS = samurai[i][a];
			if (especialChS == '@') {
				especialChS = 219;
			}
			else if (especialChS == '#') {
				especialChS = 220;
			}
			else if (especialChS == '$') {
				especialChS = 223;
			}
			if (especialChS != ' ') {
				char str[2] = { especialChS, 0 };
				mostrar(posicaoSamuraiX + a, posicaoSamuraiY + i, FOREGROUND_YELLOW, str);
			}
		}
	}

	char ** zumbi;
	zumbi = (char **)malloc(sizeof(char *) * 8);

	for (int i = 0; i < 8; i++) {
		zumbi[i] = (char *)malloc(sizeof(char) * 10);
	}

	if (zumbiVida > 0)
	{
		if (acaZumbi == ZUMBIESQUERDA)
		{
			zumbi[0] = "   @@@@  ";
			zumbi[1] = " #@@@@@  ";
			zumbi[2] = "   @@@@  ";
			zumbi[3] = "    @@   ";
			zumbi[4] = "@@@@@@@  ";
			zumbi[5] = "    @@@  ";
			zumbi[6] = "    @@@  ";
			zumbi[7] = " #@@@@@  ";

		}
		else
		{
			zumbi[0] = "  @@@@   ";
			zumbi[1] = "  @@@@@# ";
			zumbi[2] = "  @@@@   ";
			zumbi[3] = "   @@    ";
			zumbi[4] = "  @@@@@@@";
			zumbi[5] = "  @@@    ";
			zumbi[6] = "  @@@    ";
			zumbi[7] = "  @@@@@# ";
		}


	}
	else
	{
		if (countZ1 == 0)
		{
			zumbi[0] = "         ";
			zumbi[1] = "         ";
			zumbi[2] = "         ";
			zumbi[3] = "         ";
			zumbi[4] = "    @    ";
			zumbi[5] = "  @@@@@  ";
			zumbi[6] = "    @    ";
			zumbi[7] = "    @    ";
		}
		
	}
	
	if (countZ1 == 0)
	{
		char especialChZ = ' ';

		for (int i = 0; i < 8; i++) {
			for (int a = 0; a < 10; a++) {
				especialChZ = zumbi[i][a];
				if (especialChZ == '@') {
					especialChZ = 219;
				}
				else if (especialChZ == '#') {
					especialChZ = 220;
				}
				else if (especialChZ == '$') {
					especialChZ = 223;
				}
				if (especialChZ != ' ') {
					char str[2] = { especialChZ, 0 };
					mostrar(zumbiX + a, zumbiY + i, corZumbi, str);
				}
			}
		}

	}


	char ** zumbi2;
	zumbi2 = (char **)malloc(sizeof(char *) * 8);

	for (int i = 0; i < 8; i++) {
		zumbi2[i] = (char *)malloc(sizeof(char) * 10);
	}



	if (zumbi2Vida > 0)
	{
		if (acaZumbi2 == ZUMBIESQUERDA2)
		{
			zumbi2[0] = "   @@@@  ";
			zumbi2[1] = " #@@@@@  ";
			zumbi2[2] = "   @@@@  ";
			zumbi2[3] = "    @@   ";
			zumbi2[4] = "@@@@@@@  ";
			zumbi2[5] = "    @@@  ";
			zumbi2[6] = "    @@@  ";
			zumbi2[7] = " #@@@@@  ";

		}
		else
		{
			zumbi2[0] = "  @@@@   ";
			zumbi2[1] = "  @@@@@# ";
			zumbi2[2] = "  @@@@   ";
			zumbi2[3] = "   @@    ";
			zumbi2[4] = "  @@@@@@@";
			zumbi2[5] = "  @@@    ";
			zumbi2[6] = "  @@@    ";
			zumbi2[7] = "  @@@@@# ";
		}


	}
	else
	{
		if (countZ2 == 0)
		{
			zumbi2[0] = "         ";
			zumbi2[1] = "         ";
			zumbi2[2] = "         ";
			zumbi2[3] = "         ";
			zumbi2[4] = "    @    ";
			zumbi2[5] = "  @@@@@  ";
			zumbi2[6] = "    @    ";
			zumbi2[7] = "    @    ";
		}

	}

	if (countZ2 == 0)
	{
		char especialChZ2 = ' ';

		for (int i = 0; i < 8; i++) {
			for (int a = 0; a < 10; a++) {
				especialChZ2 = zumbi2[i][a];
				if (especialChZ2 == '@') {
					especialChZ2 = 219;
				}
				else if (especialChZ2 == '#') {
					especialChZ2 = 220;
				}
				else if (especialChZ2 == '$') {
					especialChZ2 = 223;
				}
				if (especialChZ2 != ' ') {
					char str[2] = { especialChZ2, 0 };
					mostrar(zumbi2X + a, zumbi2Y + i, corZumbi2, str);
				}
			}
		}
	}

	char ** porta;
	porta = (char **)malloc(sizeof(char *) * 8);

	for (int i = 0; i < 8; i++) {
		porta[i] = (char *)malloc(sizeof(char) * 10);
	}

	if (zumbiVida <= 0 && zumbi2Vida <= 0)
	{

		porta[0] = "@@@@@@@@@";
		porta[1] = "@  @@@  @";
		porta[2] = "@   @   @";
		porta[3] = "@  #@#  @";
		porta[4] = "@   @   @";
		porta[5] = "@   @   @";
		porta[6] = "@   @   @";
		porta[7] = "@@@@@@@@@";

		char especialChP = ' ';

		for (int i = 0; i < 8; i++) {
			for (int a = 0; a < 10; a++) {
				especialChP = porta[i][a];
				if (especialChP == '@') {
					especialChP = 219;
				}
				else if (especialChP == '#') {
					especialChP = 220;
				}
				else if (especialChP == '$') {
					especialChP = 223;
				}
				if (especialChP != ' ') {
					char str[2] = { especialChP, 0 };
					mostrar(portaX + a, portaY + i, corPorta, str);
				}
			}
		}

	}

	for (int a = 0; a < 79; a++) {
		char str[2] = { 219, 0 };
		mostrar(0 + a, floor, FOREGROUND_INTENSITY, str);
	}

	for (int a = 0; a < 79-floor2X; a++) {
		char str[2] = { 219, 0 };
		mostrar(floor2X + a, floor2Y, FOREGROUND_INTENSITY, str);
	}

	mostrar(60, 1, FOREGROUND_YELLOW, "Pontos: ");
	mostrar(70, 1, FOREGROUND_RED, countS);

	if (samuraiVida == 3)
	{
		mostrar(1, 1, FOREGROUND_RED, "Vida: &&&");

	}

	if (samuraiVida == 2)
	{
		mostrar(1, 1, FOREGROUND_RED, "Vida: &&");

	}

	if (samuraiVida == 1)
	{
		mostrar(1, 1, FOREGROUND_RED, "Vida: &");

	}


}
