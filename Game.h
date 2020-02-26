#pragma once
#include <time.h>
#include <Windows.h>
#include "Chessboard.h"
using namespace std;
class Game
{
private:
	static ChessBoard* board;
	static int Game::gameModel;//1->玩家VS玩家;2->玩家VS电脑
	static int Game::isFirst;//1->玩家先手;2->电脑先手
	static int Game::now;//1->当前玩家下;2->当前电脑下;now==first时,为黑棋
	static bool Game::isEnd;//是否结束
	static bool Game::isBan;//是否被禁
	static int Game::total;//局数
	static int Game::score1;//分数，>0玩家赢，否则AI赢，
	static int Game::score2;
	static int Game::steps;
public:
	Game();
	~Game();
	static ChessBoard* getChessBoard();
	static int getGameModel();
	static int getIsFirst();
	static int getNow();
	static bool getIsEnd();
	static void setIsBan(bool ban);
	static bool getIsBan();
	static int getTotal();
	static int getScore1();
	static int getScore2();
	static int getSteps();
	static void addSteps();
	/*
	int getModel();
	void setModel(int tmp);
	int getFirst();
	void setFirst(int tmp);
	int getNow();
	void setNow (int tmp);
	bool getEnd();
	void setEnd(bool tmp);
	*/
	

	void introduction();
	void regulation();
	void startGame();
	
	void ai();
	void people();

};

