#include "Strategy.h"
#include "Chessboard.h"
#include "Game.h"
#include "Judge.h"
using namespace std;
Strategy::Strategy() {
}
Strategy::~Strategy() {

}


int Strategy::point(int row, int col)//非负分值
{
	Judge* judge = new Judge;
	if (judge->ban(row, col))return 0;//禁手0分
	if (judge->chessOver(row, col))
	{
		//Game::isEnd = false;
		return 10000;
	}
	int ret = judge->liveFour(row, col) * 1000 + (judge->reachFour(row, col) + judge->liveThree(row, col)) * 100;
	int u;
	for (u = 0; u < 8; u++)if (Game::getChessBoard()->getof(row + judge->getDxOf(u),col + judge->getDyOf(u)))ret++;//无效点0分
	return ret;
}
int Strategy::Level3(int p2)
{
	int i, j;
	Judge* judge = new Judge;
	int keyp = -100000, tempp;
	for (i = 1; i <= 15; i++)for (j = 1; j <= 15; j++)
	{
		if (!judge->ok(i, j))continue;
		Game::getChessBoard()->setof(i,j,3 - Game::getIsFirst());
		tempp = point(i, j);
		if (tempp == 0) { Game::getChessBoard()->setof(i,j,0); continue; }
		if (tempp == 10000)
		{
			Game::getChessBoard()->setof(i,j,0);
			return 10000;
		}
		Game::getChessBoard()->setof(i,j,0);
		if (tempp - p2 * 2 > keyp)keyp = tempp - p2 * 2;//第三层取极大
	}
	return keyp;
}
int Strategy::Level2()
{
	int i, j;
	Judge* judge = new Judge;
	int keyp = 100000, tempp;
	for (i = 1; i <= 15; i++)
		for (j = 1; j <= 15; j++)
	{
		if (!judge->ok(i, j))continue;
		Game::getChessBoard()->setof(i,j, Game::getIsFirst());
		tempp = point(i, j);
		if (tempp == 0) { Game::getChessBoard()->setof(i, j, 0); continue; }
		if (tempp == 10000)
		{
			Game::getChessBoard()->setof(i, j, 0);
			return -10000;
		}
		tempp = Level3(tempp);
		Game::getChessBoard()->setof(i, j, 0);
		if (tempp < keyp)keyp = tempp;//第二层取极小
	}
	return keyp;
}
int Strategy::AI()
{
	Judge* judge = new Judge;
	ChessBoard::DrawBoard(Game::getChessBoard()->getQp());
	printf("  轮到AI下，请稍候： ");
	if (Game::getChessBoard()->getof(8,8) == 0)return judge->go(8, 8);
	int i, j;
	int keyp = -100000, keyi, keyj, tempp;
	for (i = 1; i <= 15; i++)
	{
		for (j = 1; j <= 15; j++)
		{
			if (!judge->ok(i, j))continue;
			Game::getChessBoard()->setof(i,j, 3-Game::getIsFirst());
			tempp = point(i, j);
			if (tempp == 0) { Game::getChessBoard()->setof(i,j,0); continue; }//高效剪枝，避开了禁手点和无效点
			if (tempp == 10000)return judge->go(i, j);
			tempp = Level2();
			Game::getChessBoard()->setof(i,j,0);
			if (tempp > keyp)keyp = tempp, keyi = i, keyj = j;//第一层取极大
		}
	}
	return judge->go(keyi, keyj);
}
