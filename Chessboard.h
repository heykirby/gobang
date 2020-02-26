#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include"Point.h"
using namespace std;
class ChessBoard{
private:
	int **qp;
public:
	int getof(int x,int y);
	int getof(Point p);
	bool setof(int x, int y, int value);
	bool setof(Point p, int value);
	int** getQp();
	ChessBoard();
	~ChessBoard();
	static int out(int i,int j,int **qp);
	static void DrawBoard(int **qp);
};