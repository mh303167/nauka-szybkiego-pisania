/*
	Program do nauki szybkiego pisania na klawiaturze
	generateText.cpp
	@author Marcin Hajdecki
*/

#include <iostream> //u¿ywam, by korzystaæ ze standardowego wejœcia-wyjœcia
using namespace std;

void generateText(char* lessonText, int textLength, int wordLength)
{
	srand((unsigned)time(0));
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < textLength; i++) //generuje tekst skladajacy sie z slow oddzielonych spacjami
	{
		if (i % (wordLength + 1) == wordLength)
			lessonText[i] = ' ';
		else
			lessonText[i] = alphabet[rand() % 26]; //slowa skladaja sie z losowych znakow z tablicy alphabet[]
		cout << lessonText[i];
	}
	cout << endl;
}