#ifndef TICTACTOE
#define TICTACTOE

class Tictactoe
{
	public:
	
	Tictactoe();
	~Tictactoe();
	
	void play();
	void turn();
	bool multi();
	void AI();
	int win();
	
	private:
	
	char map[3][3];
	int playerTurn;
};

#endif
