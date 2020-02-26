#pragma once
#include<time.h>
#include<ctime>
class HumanPlayer
{
public:

	HumanPlayer();
	~HumanPlayer();

	int play();
	time_t player_start;
	time_t player_end;
};

