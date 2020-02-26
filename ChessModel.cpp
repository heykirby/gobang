#include "ChessModel.h"

ChessModel::ChessModel()
{
	this->five = 0;
	this->liveFour = 0; 
	this->four = 0;
	this->liveThree = 0;
	this->three = 0;
	this->liveTwo = 0;
	this->two = 0;
	this->liveOne = 0;
	this->one = 0;
	this->longConnection = 0;
}


ChessModel::~ChessModel()
{
}

int ChessModel::getFive()
{
	return this->five;
}

int ChessModel::getLiveThree()
{
	return this->liveThree;
}

int ChessModel::getThree()
{
	return this->three;
}

int ChessModel::getLiveFour()
{
	return this->liveFour;
}

int ChessModel::getFour()
{
	return this->four;
}

int ChessModel::getLiveTwo()
{
	return this->liveTwo;
}

int ChessModel::getTwo()
{
	return this->two;
}

int ChessModel::getLiveOne()
{
	return this->liveOne;
}

int ChessModel::getOne()
{
	return this->one;
}

int ChessModel::getLongConnection()
{
	return this->longConnection;
}

void ChessModel::setFive(int num)
{
	this->five = num;
}

void ChessModel::setLiveThree(int num)
{
	this->liveThree = num;
}

void ChessModel::setThree(int num) 
{
	this->three = num;
}

void ChessModel::setLiveFour(int num)
{
	this->liveFour = num;
}

void ChessModel::setFour(int num)
{
	this->four = num;
}

void ChessModel::setLiveTwo(int num)
{
	this->liveTwo = num;
}

void ChessModel::setTwo(int num)
{
	this->two = num;
}

void ChessModel::setLiveOne(int num)
{
	this->liveOne = num;
}

void ChessModel::setOne(int num)
{
	this->one = num;
}

void ChessModel::setLongConnection(int num)
{
	this->longConnection = num;
}

void ChessModel::addFive(int num) 
{
	this->five += num;
}

void ChessModel::addLiveThree(int num)
{
	this->liveThree += num;
}

void ChessModel::addThree(int num)
{
	this->three += num;
}

void ChessModel::addLiveFour(int num)
{
	this->liveFour += num;
}

void ChessModel::addFour(int num)
{
	this->four += num;
}

void ChessModel::addLiveTwo(int num)
{
	this->liveTwo += num;
}

void ChessModel::addTwo(int num)
{
	this->two += num;
}
void ChessModel::addLiveOne(int num)
{
	this->liveOne += num;
}

void ChessModel::addOne(int num)
{
	this->one += num;
}

void ChessModel::addLongConnection(int num)
{
	this->longConnection += num;
}
