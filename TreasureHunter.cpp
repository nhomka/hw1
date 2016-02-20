#include "TreasureHunter.h"
#include "GameBoard.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int totalPoints = 50;
int x = 0;
int y = 0;
bool konamiCode;


TreasureHunter::TreasureHunter(int x, int y, GameBoard& board){
    cout << x << " " << y << endl;
	if (board.isTreasure(Location(x,y)) == true){
		board.removeTreasure(Location(x,y));
		totalPoints += 10;
		cout << totalPoints << "after Treasure" << endl;
	}
	else if(Location(x,y) == board.getGoalLocation()){
		totalPoints += 100;
		int score = totalPoints;
		cout << totalPoints << "after Goal" << endl;
		//Game over!
	}
}

TreasureHunter::~TreasureHunter(){
    // TODO
}

void TreasureHunter::changeBoard(GameBoard& newBoard){
    // TODO
}
void TreasureHunter::changeBoard(GameBoard* newBoard){
    // TODO
}
int TreasureHunter::computeScore(std::string inputString){
	Location goalLocation(5, 7);
    GameBoard board(goalLocation);
	// int totalPoints = 50;
	//int goalLocation = GameBoard::getGoalLocation();
	int moveLength = inputString.size();
	int i = 0;
	// int x = 0;
	// int y = 0;
	// bool konamiCode;
	for ( i ; i <= moveLength ; i+=1 ){
		cout << inputString[i] << endl;
		if (inputString[i] == 'u'){
			y += 1;
			cout << x << '  ' << y << endl;
			cout << inputString[i] << endl;
			
			if (abs((y) - goalLocation.getY()) < abs((y-1) - goalLocation.getY())){
				totalPoints += 2;
				cout << totalPoints << " after good direction" << endl;

			}

			else{
				totalPoints -= 1;
				cout << totalPoints << " after bad direction" << endl;
			}

			TreasureHunter(x, y,  board);

		}
		else if (inputString[i] == 'd'){
			y -= 1;
			cout << x << y << endl;
			cout << inputString[i] << endl;

			if (abs((y) - goalLocation.getY()) < abs((y+1) - goalLocation.getY())){
				totalPoints += 2;
				cout << totalPoints << " after good direction" << endl;

			}

			else{
				totalPoints -= 1;
				cout << totalPoints << " after bad direction" << endl;
			}

			TreasureHunter(x, y, board);

		}
		else if (inputString[i] == 'l'){
			x -= 1;
			cout << x << y << endl;
			cout << inputString[i] << endl;

			if (abs((x) - goalLocation.getX()) < abs((x+1) - goalLocation.getX())){
				totalPoints += 2;
				cout << totalPoints << " after good direction" << endl;

			}

			else{
				totalPoints -= 1;
				cout << totalPoints << " after bad direction" << endl;
			}

			TreasureHunter(x, y, board);

		}
		else if (inputString[i] == 'r'){
			x += 1;
			cout << x << y << endl;
			cout << inputString[i] << endl;

			if (abs((x) - goalLocation.getX()) < abs((x-1) - goalLocation.getX())){
				totalPoints += 2;
				cout << totalPoints << " after good direction" << endl;

			}

			else{
				totalPoints -= 1;
				cout << totalPoints << " after bad direction" << endl;
			}

			TreasureHunter(x, y, board);

		}
		else if (inputString[i] == 'a'){
			if (i >= 9){
				if (inputString.substr(i-9, i-1) == "uuddlrlrb"){
				konamiCode = true;
				}
			}

			while(board.isEnemy(Location(x,y)) == true){
				if (konamiCode == true){
					board.killEnemy(Location(x,y));
				}
				else if (konamiCode == false){
					if (inputString[i+1] == 'a'){
					board.killEnemy(Location(x,y));
					i += 1;
					cout << "you killed an enemy" << endl;
					}
					else if(inputString[i+1] != 'a'){
					i += 1;
					cout << "you did nothing" << endl;
					}
				}
			}

		}

		else if (inputString[i] == 'b'){

		}
		else {
			totalPoints -= 2;
			cout << "You did something real dumb and lost 2 points " << totalPoints << " " << endl;
		}
	}
    return totalPoints;
}