#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <map>
#include <fstream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameLoop = true;
bool isGuessed;

int mistakes = 3;

string word[10] = {"copil" , "munte", "floare", "culoare", "carte", "vis", "fruct", "apa", "arbore", "stea"};
string wordchecker;

void resetConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void SetColor(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

int main() {
	SetColor(13, 0);

	srand((unsigned)time(NULL));
	int random = rand() % 10;
	cout << random;

	/**/
	wordchecker = "|";
	for (int i = 0; i < word[random].length(); i++)
		wordchecker += "*";
	wordchecker += "|";
	cout << wordchecker;

	while (gameLoop) {
		
		//Resetare Consola
		resetConsole();
		///////
		cout << wordchecker << endl;
		
		char guess;
		cout << "Introduceti o litera: " << endl;
		cout << "Mai aveti " << mistakes << " greseli";
		guess = _getch();

		bool charFound = false;
		for (int i = 0; i < word[random].length(); i++)
			if (word[random][i] == guess) {
				wordchecker[i + 1] = guess;
				charFound = true;
			}

		if (!charFound) {
			mistakes--;
		}

		isGuessed = true;
		for (int i = 1; i <= word[random].length(); i++)
			if (wordchecker[i] == '*') {
				isGuessed = false;
				break;
			}

		if (isGuessed) {
			gameLoop = false;
			resetConsole();
			cout << wordchecker << endl;
			cout << "Ai castigat! Cuvantul era: " << word[random] << endl;
		}

		if (mistakes == 0) {
			gameLoop = false;
			resetConsole();
			cout << wordchecker << endl;
			cout << "Ai pierdut! Cuvantul era: " << word[random] << endl;
		}

	}
}


