#pragma once
#include <iostream>
#include <string>
#include<tchar.h>

using namespace std;
class Chessboard
{
//©°©Ð©Ð
private:
	wchar_t board[15][17] = {
		L"¡ñ¡ñ¡ñ©Ð©Ð©Ð©Ð©Ð©Ð©Ð©Ð©Ð©Ð©Ð©´\n",
		L"©À©à©à¡ñ©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à¡ñ©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à¡ñ©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©À©à©à©à©à©à©à©à©à©à©à©à©à©à©È\n",
		L"©¸©Ø©Ø©Ø©Ø©Ø©Ø©Ø©Ø©Ø©Ø©Ø©Ø©Ø©¼\n" };
	wchar_t chessman[5] = { L"¡ð¡÷¡ñ¡ø" };
	int blank = 225;
public:
	Chessboard();
	~Chessboard();
	void draw();
	void setof(int i, int j, int type);
	void setof(int i, int j, wchar_t type);
	wchar_t getof(int i, int j);
	wchar_t getChessman(int i);
	bool allow(int i, int j);
	int checkType(int i, int j);
	int getBlank();
	bool validPosition(int i, int j);
};
