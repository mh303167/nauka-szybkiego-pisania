/*
	Program do nauki szybkiego pisania na klawiaturze
	correctErrors.cpp
	@author Marcin Hajdecki
*/

#include <iostream> //u¿ywam, by korzystaæ ze standardowego wejœcia-wyjœcia
#include <windows.h> //u¿ywam, by móc zmieniæ kolor tekstu w konsoli
using namespace std;

int correctErrors(char* lessonText, char* userInput, int textLength)
{
	int errorCounter = 0;
	for (int i = 0; i < textLength; i++)
	{
		if (lessonText[i] != userInput[i]) //sprawdza, czy u¿ytkownik pope³ni³ b³¹d
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 4); //zmienia kolor wypisywanego tekstu w konsoli na czerwony
			if (lessonText[i] == ' ')
				cout << "~"; //oznacza b³¹d przy wprowadzeniu spacji jako "~"
			else
				cout << lessonText[i];
			errorCounter++; //zwiêksza licznik o 1
			SetConsoleTextAttribute(hConsole, 7); //zmienia kolor wypisywanego tekstu w konsoli na bia³y
		}
		else
			cout << lessonText[i];
	}
	cout << endl;
	return errorCounter;
}