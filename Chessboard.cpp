#include "ChessBoard.h"
#include "Game.h"
#include<iostream>
//°´ÕÕ¼ÆËã»ú´æ´¢µÄgetof
int ChessBoard::getof(int x, int y)
{
	return qp[x][y];
}
//°´ÕÕÆåÅÌÂß¼­µÄgetof
int ChessBoard::getof(Point p)
{
	return qp[16 - p.getY()][p.getX()];
}
//°´ÕÕ¼ÆËã»ú´æ´¢µÄsetof
bool ChessBoard::setof(int x, int y, int value)
{
	if (x < 0 || x > 17 || y < 0 || y > 17)
	{
		return false;
	}
	qp[x][y] = value;
	return true;
}
//°´ÕÕÆåÅÌÂß¼­µÄsetof
bool ChessBoard::setof(Point p, int value)
{
	int x = p.getX();
	int y = p.getY();
	if (x < 1 || x > 15 || y < 1 || y > 15)
	{
		return false;
	}
	qp[16 - y][x] = value;
	return true;
}
int ** ChessBoard::getQp()
{
	return qp;
}
ChessBoard::ChessBoard() {
	qp = new int* [17];
	for (int i = 0; i < 17; i++)qp[i] = new int[17];
	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 17; j++)
			qp[i][j] = 0;
}

ChessBoard::~ChessBoard() {

}
int ChessBoard::out(int i,int j,int **p)
{
	if (p[i][j] == 1)return printf("¡ñ");
	if (p[i][j] == 2)return printf("¡ğ");
	if (p[i][j] == -1)return printf("¡ø");
	if (p[i][j] == -2)return printf("¡÷");
	if (i == 15)
	{
		if (j == 1)return printf("©³");
		if (j == 15)return printf("©·");
		return printf("©Ó");
	}
	if (i == 1)
	{
		if (j == 1)return printf("©»");
		if (j == 15)return printf("©¿");
		return printf("©Û");
	}
	if (j == 1)return printf("©Ä");
	if (j == 15)return printf("©Ì");
	return printf("©à");
}
void ChessBoard::DrawBoard(int **p)//»­ÆåÅÌ
{
	system("cls");
	int row = 0, col = 0, keyr = 0, keyc = 0;
	char alpha = 'A';
	printf("\n\n\n     ");
	for (col = 1; col <= 15; col++)printf("%c ", alpha++);
	for (row = 15; row >= 1; row--)
	{
		printf("\n   %2d", row);
		for (col = 1; col <= 15; col++)
		{
			out(row, col,p);
			if (p[row][col] < 0)keyr = row, keyc = col;
		}
		printf("%d", row);
	}
	alpha = 'A';
	printf("\n     ");
	for (col = 1; col <= 15; col++)printf("%c ", alpha++);
	printf("\n\n");
	if (Game::getGameModel()==1) {
		if (Game::getIsFirst() == 1)printf("  player1Ö´ºÚ,player2Ö´°×\n");
		else printf("  player1Ö´°×£¬player2Ö´ºÚ\n");
	}
	else {
		if (Game::getIsFirst() ==2)printf("  AIÖ´ºÚ£¬Íæ¼ÒÖ´°×\n");
		else printf("  AIÖ´°×£¬Íæ¼ÒÖ´ºÚ\n");
	}
	
	alpha = 'A';
	if (keyr)printf("  ×îºóÂä×ÓÎ»ÖÃ£º%c%d\n", alpha + keyc - 1, keyr);
}