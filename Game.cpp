#include "Game.h"
#include "Strategy.h"
#include "HumanPlayer.h"
#include "Chessboard.h"

ChessBoard* Game::board = new ChessBoard;
int Game::gameModel = 0;//1->玩家VS玩家;2->玩家VS电脑
int Game::isFirst = 0;//1->玩家先手;2->电脑先手
int Game::now = 0;//1->当前玩家下;2->当前电脑下;now==first时,为黑棋
bool Game::isEnd = false;//是否结束
bool Game::isBan = false;//是否被禁
int Game::total = 0;//局数
int Game::score1 = 0;//分数
int Game::score2 = 0;//分数
int Game::steps = 0;//步数,判断和棋
Game::Game()
{
	
}


Game::~Game()
{
	delete board;
}

ChessBoard * Game::getChessBoard()
{
	return board;
}

int Game::getGameModel()
{
	return gameModel;
}

int Game::getIsFirst()
{
	return isFirst;
}

int Game::getNow()
{
	return now;
}

bool Game::getIsEnd()
{
	return isEnd;
}

void Game::setIsBan(bool ban)
{
	isBan = ban;
}

bool Game::getIsBan()
{
	return isBan;
}

int Game::getTotal()
{
	return total;
}

int Game::getScore1()
{
	return score1;
}
int Game::getScore2()
{
	return score2;
}
int Game::getSteps() {
	return steps;
}
void Game::addSteps() {
	steps += 1;
}
void Game::introduction()
{
	cout << "╓┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄╖" << endl;
	cout << "║         ~~~~~~欢迎来到五子棋游戏~~~~~~         ║" << endl;
	cout << "║         1 开始游戏                             ║" << endl;
	cout << "║         2 规则介绍                             ║" << endl;
	cout << "║         3 退出                                 ║" << endl;
	cout << "╙┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄╜" << endl;
}

void Game::regulation()
{
	cout << "黑先、白后，从天元开始相互顺序落子" << endl;
	cout << "超时时间为15s,超时判输" << endl;
	cout << "最先在棋盘横向、竖向、斜向形成连续的相同色五个棋子的一方为胜" << endl;
	cout << "五连与禁手同时形成，先五为胜。" << endl;
	cout << "黑方禁手形成时，白方的程序应立即指出。若白方未发现或发现后未指明而继续应子，则不能判黑方负。" << endl;
	cout << "每对选手比赛两局，轮流执黑先行，胜一局记2分，负一局记0分，和棋各记1分。" << endl;

}
void Game::startGame()
{
loop1:
	system("cls");
	char tmpModel;
	char tmpFirst;
	cout << "请选择玩法:" << endl;
	cout << "People VS People (1)" << endl;
	cout << "People VS Computer (2)" << endl;
	cin >> tmpModel;
	switch (tmpModel)
	{
	case '1':
		cout << "OK! you choose People VS People.Good Game!" << endl;
		Game::gameModel=1;
		break;
	case '2':
		cout << "OK! you choose People VS Computer.Good Game!" << endl;
		Game::gameModel = 2;
		break;
	default:
		cout << "请重新输入" << endl;
		goto loop1;
		break;
	}
loop2:
	cout << "请选择:先手(1)后手(2):" << endl;
	cin >> tmpFirst;
	switch (tmpFirst)
	{
	case '1':
		cout << "YOU choose First" << endl;
		Game::isFirst = 1;
		Game::now = 1;
		break;
	case '2':
		cout << "YOU choose Second" << endl;
		Game::isFirst = 2;
		Game::now = 2;
		break;
	default:
		cout << "请重新输入" << endl;
		goto loop2;
		break;
	}
	switch (Game::gameModel){
		case 1:
			people();
			break;
		case 2:
			ai();
			break;
	}
}
//控制台消息响应
void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	if (1 == idEvent)
	{//如果是定时器1
		::MessageBeep(0);//Beep叫
	}

}
void Game::people() {
	HumanPlayer* player1 = new HumanPlayer;
	HumanPlayer* player2 = new HumanPlayer;
	while (!Game::isEnd)
	{
		int result = 0;
		if (now == 2) {
			result =player2->play();
			Game::addSteps();
		}
		else {
			result = player1->play();
			Game::addSteps();
		}
		switch (result) {
		case 0:
			break;
		case 2:
			cout << "和棋" << endl;
			Game::total += 1;
			Game::score1 += 1;
			Game::score2 += 1;
			Game::isEnd = true;
			Sleep(2000);
			break;
		case 1:
			cout << "本局玩家1胜" << endl;
			Game::total += 1;
			Game::score1 += 2;
			Game::isEnd = true;
			Sleep(2000);
			break;
		case -1:
			cout << "本局玩家2胜" << endl;
			Game::total += 1;
			Game::score2 += 2;
			Game::isEnd = true;
			Sleep(2000);
			break;
		default:
			break;
		}
		if (result != 0) {
			if (Game::total < 2) {
				Game::isFirst = 3-isFirst;
				Game::now = Game::isFirst;
				Game::isEnd = false;//是否结束
				Game::isBan = false;//是否被禁
				Game::board = new ChessBoard;
				Game::steps = 0;//清空步数
				return people();
			}
			else {
				if (Game::score1 > Game::score2) {
					cout << "玩家一胜利，得分:" << Game::score1 << endl;
					system("pause");
					return;
				}
				else if (Game::score2 > Game::score1) {
					cout << "玩家二胜利，得分:" << Game::score2 << endl;
					system("pause");
					return;
				}
				else {
					cout << "平局" << endl;
					cout << "玩家一得分"<<Game::score1<<"玩家二得分:"<<Game::score2<<endl;
					system("pause");
					return;
				}
			}
		}
		Game::now = (3 - Game::now);//换下棋方
	}
}
void Game::ai() {
	Strategy* stra= new Strategy;
	HumanPlayer* player = new HumanPlayer;

	while (!Game::isEnd)
	{
		int result=0;
		if (now == 2) {
			result=stra->AI();
			Game::addSteps();
		}
		else {
			result=player->play();
			Game::addSteps();
		}
		//没有发现禁手,则不判输
		if (now != isFirst)Game::isBan = false;
		switch (result) {
		case 0:
			break;
		case 2:
			cout << "和棋" << endl;
			Game::total += 1;
			Game::score1 += 1;
			Game::score2 += 1;
			Game::isEnd = true;
			Sleep(2000);
			break;
		case 1:
			cout << "本局玩家胜" << endl;
			Game::total += 1;
			Game::score1 += 2;
			Game::isEnd = true;
			Sleep(2000);
			break;
		case -1:
			cout << "本局电脑胜" << endl;
			Game::total += 1;
			Game::score2 += 2;
			Game::isEnd = true;
			Sleep(2000);
			break;
		default:
			break;
		}
		if (result != 0) {
			if (Game::total < 2) {
				Game::isFirst = 3 - Game::isFirst;
				Game::now = Game::isFirst;
				Game::isEnd = false;//是否结束
				Game::isBan = false;//是否被禁
				Game::board = new ChessBoard;
				Game::steps = 0;
				return ai();
			}
			else {
				if (Game::score1 > Game::score2) {
					cout << "玩家胜利，得分:" << Game::score1 << endl;
					system("pause");
					return;
				}
				else if (Game::score2 > Game::score1) {
					cout << "电脑胜利，得分:" << Game::score2 << endl;
					system("pause");
					return;
				}
				else {
					cout << "平局" << endl;
					cout << "玩家得分" << Game::score1 << "电脑得分:" << Game::score2 << endl;
					system("pause");
					return;
				}
			}
		}
		Game::now=(3-Game::now);//换下棋方
		
	}
}
/*
int Game::getModel() {
	return Game::gameModel;
}
int Game::getFirst() {
	return Game::isFirst;
}
void Game::setModel(int tmp) {
	Game::gameModel = tmp;
}
void Game::setFirst(int tmp) {
	Game::isFirst = tmp;
}
ChessBoard* Game::getChessBoard() {
	return board;
}
int Game::getNow() {
	return now;
}
void Game::setNow(int tmp) {
	now = tmp;
}
bool Game::getEnd() {
	return isEnd;
}
void Game::setEnd(bool tmp) {
	isEnd= tmp;
}
*/