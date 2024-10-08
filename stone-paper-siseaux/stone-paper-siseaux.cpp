#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

enum enChooseOfPlayer { stone = 1, paper = 2, scissor = 3 };
enum enChooseOfComputer { stones = 1 , papers = 2 , scissors = 3 };

struct stGame {

	short int NumberOfrounds = 1;
	short int NumberOfGames;
	short int NumberOfPlayerWin = 0;
	short int NumberOfComputerWin = 0;
	short int NumberOfDraw = 0;

	string PlayerChoose;
	string ComputerChoose;
	string TheWinner;

	enChooseOfComputer ChooseOfComputer;
	enChooseOfPlayer ChooseOfPlayer;

};

void TheWinnerOfround(stGame& Game) {
	cout << "\t_______________ Round[" << Game.NumberOfrounds << "] _______________\n";
	cout << "\t|\tPlayer choose : "<<Game.PlayerChoose<<"\t\t | \n";
	cout << "\t|\tPc choose : "<<Game.ComputerChoose<<"\t\t | \n";
	cout << "\t|\tRound Winner : "<<Game.TheWinner<<"\t | \n";
	cout << "\t----------------------------------------" << endl;
	Game.NumberOfrounds++;
}

void TheWinner(stGame& Game , int PcShoose, int PlayerShoose) {

	if (PcShoose == enChooseOfComputer::stones) {
		Game.ComputerChoose = "stone";
		if (PlayerShoose == enChooseOfPlayer::stone) {
			Game.PlayerChoose = "stone";
			Game.TheWinner = "[ No Winner ]";
			TheWinnerOfround(Game);
			Game.NumberOfDraw++;
		}
		else if (PlayerShoose == enChooseOfPlayer::paper) {
			Game.PlayerChoose = "paper";
			Game.TheWinner = "[ Player ]";
			TheWinnerOfround(Game);
			Game.NumberOfPlayerWin++;
		}
		else if (PlayerShoose == enChooseOfPlayer::scissor) {
			Game.PlayerChoose = "scissor";
			Game.TheWinner = "[ Computer ]";
			TheWinnerOfround(Game);
			Game.NumberOfComputerWin++;
			
		}
	}

	if (PcShoose == enChooseOfComputer::papers) {
		Game.ComputerChoose = "paper";
		if (PlayerShoose == enChooseOfPlayer::stone) {
			Game.PlayerChoose = "stone";
			Game.TheWinner = "[ Computer ]";
			TheWinnerOfround(Game);
			Game.NumberOfComputerWin++;
		}
		else if (PlayerShoose == enChooseOfPlayer::paper) {
			Game.PlayerChoose = "paper";
			Game.TheWinner = "[ No Winner ]";
			TheWinnerOfround(Game);
			Game.NumberOfDraw++;
		}
		else if (PlayerShoose == enChooseOfPlayer::scissor) {
			Game.PlayerChoose = "scissor";
			Game.TheWinner = "[ Player ]";
			TheWinnerOfround(Game);
			Game.NumberOfPlayerWin++;

		}
	}

	if (PcShoose == enChooseOfComputer::scissors) {
		Game.ComputerChoose = "scissor";
		if (PlayerShoose == enChooseOfPlayer::stone) {
			Game.PlayerChoose = "stone";
			Game.TheWinner = "[ Player ]";
			TheWinnerOfround(Game);
			Game.NumberOfPlayerWin++;
		}
		else if (PlayerShoose == enChooseOfPlayer::paper) {
			Game.PlayerChoose = "paper";
			Game.TheWinner = "[ Computer ]";
			TheWinnerOfround(Game);
			Game.NumberOfComputerWin++;
		}
		else if (PlayerShoose == enChooseOfPlayer::scissor) {
			Game.PlayerChoose = "scissor";
			Game.TheWinner = "[ No Winner ]";
			TheWinnerOfround(Game);
			Game.NumberOfDraw++;

		}
	}

}

void round(stGame& Game) {
	srand(time(0));
	short int PlayerChoose;
	short int PcChooose = 1 + rand() % 3;
	Game.ChooseOfComputer = (enChooseOfComputer)PcChooose;
	cout << "\nChoose :\tStone[1]\tPaper[2]\tscissor[3]\t:\t";
	cin >> PlayerChoose;
	cout << endl << endl;
	while (PlayerChoose < 1 || PlayerChoose > 3) {
		cout << "Your Number is Out of Range !!\n\n";
		cout << "\nChoose :\tStone[1]\tPaper[2]\tscissor[3]\t:\t";
		cin >> PlayerChoose;
		cout << endl << endl;
	}
	Game.ChooseOfPlayer = (enChooseOfPlayer)PlayerChoose;
	cout << endl << endl;
	TheWinner(Game ,Game.ChooseOfComputer, Game.ChooseOfPlayer);
}

int main() {

	stGame Game;

	cout << "How many rounds of game ? ";
	cin >> Game.NumberOfGames;
	cout << endl;
	for (int i = 0; i < Game.NumberOfGames; i++)
	{
		round(Game);
		cout << "\n\n\n";
	}
	cout << "\n\n\n\n";
	cout << "\t\t\t================================================\n\n\t\t\t\t\tGame Over\n\n\t\t\t================================================\n\n";
	cout << "\t\t\t\t*************************" << endl;
	cout << "\t\t\t\t|\tYou :\t" << Game.NumberOfPlayerWin << "\t|" << endl;
	cout << "\t\t\t\t|\tPc :\t" << Game.NumberOfComputerWin << "\t|" << endl;
	cout << "\t\t\t\t|\tDraw :\t" << Game.NumberOfDraw << "\t|" << endl;
	cout << "\t\t\t\t*************************";
	cout << endl;
	cout << endl;
	if (Game.NumberOfPlayerWin > Game.NumberOfComputerWin) {
		cout << "\t\t\t\tThe Player is the winner";
	}
	else if (Game.NumberOfComputerWin > Game.NumberOfPlayerWin) {
		cout << "\t\t\t\tThe Pc is the winner";
	}
	else {
		cout << "\t\t\t\t\tIts Draw";
	}
	cout << endl << endl;
	system("pause");
	return 0;

}