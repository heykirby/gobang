#pragma once
class ChessModel
{
private:
	//必胜五
	int five;
	//活四数量
	int liveFour;
	//冲四数量
	int four;
	//活三数量
	int liveThree;
	//冲三数量
	int three;
	//活二数量
	int liveTwo;
	//冲二数量
	int two;
	//活一数量
	int liveOne;
	//冲一数量
	int one;
	//长连数量
	int longConnection;
public:
	ChessModel();
	~ChessModel();
	int getFive();
	int getLiveThree();
	int getThree();
	int getLiveFour();
	int getFour();
	int getLiveTwo();
	int getTwo();
	int getLiveOne();
	int getOne();
	int getLongConnection();
	void setFive(int num);
	void setLiveThree(int num);
	void setThree(int num);
	void setLiveFour(int num);
	void setFour(int num);
	void setLiveTwo(int num);
	void setTwo(int num);
	void setLiveOne(int num);
	void setOne(int num);
	void setLongConnection(int num);
	void addFive(int num);
	void addLiveThree(int num);
	void addThree(int num);
	void addLiveFour(int num);
	void addFour(int num);
	void addLiveTwo(int num);
	void addTwo(int num);
	void addLiveOne(int num);
	void addOne(int num);
	void addLongConnection(int num);
};