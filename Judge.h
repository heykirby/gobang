#pragma once
#include "Chessboard.h"
#include "Judge.h"
#include "ChessModel.h"
#include"Point.h"
class Judge
{
private:
	int directionRow[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }; //flat技术
	int directionCol[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };//（dx,dy）是8个方向向量
public:
	Judge();
	~Judge();
	bool chessOver(int row, int col);
	int go(int row, int col);
	bool ok(int row, int col);
	bool inChessBoard(int row, int col);
	int same(int row, int col, int key);
	int num(int row, int col, int u);
	bool ban(int row, int col);
	int liveFour(int row, int col);
	int reachFour(int row, int col);
	int liveThree(int row, int col);
	bool overline(int row, int col);
	int getDxOf(int pos);
	int getDyOf(int pos);
	static int judgeForbiddenMove(Point point, ChessBoard * chessBoard, string& info);

	static void caculateModel(Point point, int direction, ChessBoard * chessBoard, ChessModel & chessModel);

	static int frontPoint(int i, int j, int direction, Point& next);

	static int nextPoint(Point current, int direction, Point& next);

	static int nextPoint(int& i, int& j, int direction, Point& next);

	static int caculateLength(Point A, Point B, int direction);

	static int abs(int A, int B);

	static int abs(int A);
	
};