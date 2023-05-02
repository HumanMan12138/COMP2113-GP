#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "head.h"
using namespace std;

int riddles(int coins) {
	ifstream fin;
	fin.open("riddles.txt");
	string question[1000];
	string line;
	int i = 0;
	while (getline(fin, line)) {
		question[i] = line;
		i = i + 1;
	}
	cout << endl;
	cout << "==================================================================================" << endl;
	cout << "Welcome to guess the riddle, you will read the questions and give one word answer." << endl;
	cout << "There are five questions, if you get one correct answer, you will get 100 points." << endl;
	cout << "You can spend 100 coins to get a hint." << endl;
	cout << "Now you have " << coins << " coins." << endl;
	cout << "You need to get 300 points to win this game." << endl;
	cout << "==================================================================================" << endl;
	cout << endl;
	int a;
	int q = 0;
	int points = 0;
	string input;
	string answer;
	while (a != 5) {
		unsigned seed = time(0);
		srand(seed);
		int n =  q + rand() % 16;
		q = q + 16;
		if (n % 2 != 0) {
			n = n - 1;
		}
		sleep(1);
		cout << endl;
		cout << "==================================================================================" << endl;
		cout << "-> Current coins: " << coins << endl;
		cout << "-> Current points: " << points << endl;
		cout << "-> Target points: 300" << endl;
		cout << endl;
		cout << "Question" << " " << a + 1 << ": " << endl;
		cout << question[n] <<endl;
		cout << "----------------------------------------------------------------------------------" << endl;
		string yn;
		char y = 'y';
		string yes;
		yes += y;
		answer = question[n+1];
		cout << "You can spend 100 coins to get a hint (please type y/n)." << endl;
		cin >> yn;
		if (yn == yes and coins >= 100) {
			string f;
			int l = answer.length();
			cout << "----------------------------------------------------------------------------------" << endl;
			cout << "Hint: The first letter is: " << answer.substr(0,1) << ", and there are " << l << " letters in this word." << endl;
			cout << "----------------------------------------------------------------------------------" << endl;
			coins = coins - 100;
		}
		else if (yn == yes and coins < 100) {
			cout << "You do not have enough coins to get a hint." << endl;
		}
		
		cout << "Your answer(type a lowercase word): " << endl;
		cin >> input;
		if (input == answer) {
			cout << "----------------------------------------------------------------------------------" << endl;
			cout << "You are right!" << endl;
			cout << "Points + 100" << endl;
			cout << "==================================================================================" << endl;
			cout << endl;
			points = points + 100;
		}
		else {
			cout << "----------------------------------------------------------------------------------" << endl;
			cout << "You are wrong." << endl;
			cout << "==================================================================================" << endl;
			cout << endl;
		}
		a = a + 1;
	}
	sleep(1);
	cout << "==================================================================================" << endl;
	cout << "The game is over." << endl;
	cout << "Your final points are: " << points << endl;
	cout << "==================================================================================" << endl;
	fin.close();
	if (points < 300) {
		cout << "You Lose." << endl;
		return 0;
	}
	else {
		cout << "You Win." << endl;
		return 1;
	}
}
