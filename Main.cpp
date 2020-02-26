#include<iostream>
#include<windows.h>
#include "Game.h"
int main()
{
	system("color f0");
	Game* game = new Game;
loop1:
	system("cls");
	game->introduction();
	char c;
	cin >> c;
	switch (c)
	{
		//开始游戏
	case '1':
		game->startGame();
		break;
		//打印游戏规则
	case '2':
		game->regulation();
		cout << "任意键返回主菜单" << endl;
		cin >> c;
		goto loop1;
		break;
		//退出游戏
	case '3':
		cout << "游戏结束!!!" << endl;
		return 0;
		system("pause");
		break;
	default:
		goto loop1;
		break;
	}
}
