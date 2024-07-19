#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <conio.h>

using namespace std;

bool gameLoop = true;
bool isGuessed;

int mistakes = 3;

string word = "dark";
string wordchecker;

void resetConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int main() {

	wordchecker = "|";
	for (int i = 0; i < word.length(); i++)
		wordchecker += "*";
	wordchecker += "|";
	cout << wordchecker;


	/**/while (gameLoop) {
		//Resetare Consola
		resetConsole();
		///////
		cout << wordchecker << endl;
		
		char guess;
		cout << "Introduceți o literă: ";
		guess = _getch();

		bool charFound = false;
		for (int i = 0; i < word.length(); i++)
			if (word[i] == guess) {
				wordchecker[i + 1] = guess;
				charFound = true;
			}

		if (!charFound) {
			mistakes--;
			cout << "Mai aveti " << mistakes << "greseli";
		}

		isGuessed = true;
		for (int i = 1; i <= word.length(); i++)
			if (wordchecker[i] == '*') {
				isGuessed = false;
				break;
			}

		if (isGuessed) {
			gameLoop = false;
			resetConsole();
			cout << wordchecker << endl;
			cout << "Ai câștigat! Cuvântul era: " << word << endl;
		}

		if (mistakes == 0) {
			gameLoop = false;
			resetConsole();
			cout << wordchecker << endl;
			cout << "Ai pierdut! Cuvântul era: " << word << endl;
		}

	}
}


