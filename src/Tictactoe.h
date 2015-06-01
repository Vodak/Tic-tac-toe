/**
 * ========================
 * 
 * Filename: Tictactoe.h
 * 
 * Author: Ceytix <ceytix@mailoo.org>
 * 
 * Description: Tictactoe class
 * 
 * Created: 29/04/15
 * =========================
 **/
 
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
	void print();
	
	private:
	
	char map[3][3];
	int playerTurn;
};

#endif
