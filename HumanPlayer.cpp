#include "HumanPlayer.h"
#include "Chessboard.h"
#include "Game.h"
#include "Judge.h"
#include <limits>
#include <iostream>
#undef max
using namespace std;

HumanPlayer::HumanPlayer()
{
}


HumanPlayer::~HumanPlayer()
{
}

int HumanPlayer::play()
{
	Judge* judge = new Judge;
	player_start = time(0);
	ChessBoard::DrawBoard(Game::getChessBoard()->getQp());
	if (Game::getGameModel()==2) {
		printf("  轮到玩家下，请输入坐标(eg:H5):");
		if (Game::getNow() != Game::getIsFirst())printf("输入'?0'举报禁手");
		printf("\n");
	}
	else {
		if (Game::getNow() == 1) {
			printf("  轮到player1下，请输入坐标(eg:H5):");
		}
		else {
			printf("  轮到player2下，请输入坐标(eg:H5):");
		}
		if (Game::getNow() != Game::getIsFirst())cout << "输入'?0'举报禁手" << endl;
	}
	
	
	char c;
	int row = 0, col = 0;
while (true)
{
	c = '\n';
	cin >> c >> row;
	if (c == '?') {
		if (Game::getNow() == Game::getIsFirst()) {
			cout << "不能举报自己,请重新输入" << endl;
			continue;
		}
		if (Game::getIsBan()) {
			cout << "禁手举报成功!YOU WIN!!!" << endl;
			return -1;
		}
		else {
			cout << "没有禁手!!!输入坐标:" << endl;
			continue;
		}
	}

	if (c < 'a')col = c - 'A' + 1;
	else col = c - 'a' + 1;
	if (!judge->ok(row, col))
	{
		printf("此处不能下");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		Sleep(1000);
		continue;
	}
	else
	{
		break;
	}
}
	player_end = time(0);
	if (player_end - player_start > 30) {
		cout << "超时!!!YOU LOSE" << endl;
		return -1;
	}
	return judge->go(row, col);
	return 0;
}