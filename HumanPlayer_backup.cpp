#include "HumanPlayer.h"
#include "Chessboard.h"
#include "Game.h"
#include "Judge.h"
#include<string>
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
	
	int row, col;
	char c;
loop1:
	c = '\n';
	row = 0;
	col = 0;
	cin >> c >> row;
	if (c == '?') {
		if (Game::getNow() == Game::getIsFirst()) {
			cout << "不能举报自己,请重新输入" << endl;
			goto loop1;
		}
		if (Game::getIsBan()) {
			cout << "禁手举报成功!YOU WIN!!!" << endl;
			return -1;
		}
		else {
			cout << "没有禁手!!!输入坐标:" << endl;
			goto loop1;
		}
	}
	if (!(((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')) && (row > 0 && row <= 15))){
		cout << "输入错误，请重新输入:" << endl;
		
		cin.clear();
		cin.ignore(INT_MAX);
		cin.clear();
		goto loop1;
	}

	if (c <='Z'&&c>='A')col = c - 'A' + 1;
	else if(c<='z'&&c>='a') col = c - 'a' + 1;
	
	if (!judge->ok(row, col))
	{
		printf("此处不能下");
		Sleep(1000);
		goto loop1;
	}
	player_end = time(0);
	if (player_end - player_start > 15) {
		cout << "超时!!!YOU LOSE" << endl;
		return -1;
	}
	return judge->go(row, col);
	//return 0;
}