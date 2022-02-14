/*
	Program do nauki szybkiego pisania na klawiaturze
	getUserInput.cpp
	@author Marcin Hajdecki
*/

#include <iostream> //u¿ywam, by korzystaæ ze standardowego wejœcia-wyjœcia
#include <chrono> //u¿ywam do pomiaru czasu
using namespace std;

double getUserInput(char* userInput, int textLength)
{
	cin.ignore(10000, '\n');
	char tmp{};
	auto start = chrono::high_resolution_clock::now(); //dokonuje pomiaru czasu
	for (int i = 0; i < textLength; i++) //pobiera tekst od u¿ytkownika znak po znaku
	{
		cin.get(tmp);
		userInput[i] = tmp;
	}
	auto finish = chrono::high_resolution_clock::now(); //dokonuje pomiaru czasu
	chrono::duration<double> elapsed = finish - start; //oblicza czas wpisywania tekstu przez u¿ytkownika
	double typingSpeed = textLength / elapsed.count() * 60; //oblicza prêdkoœæ wpisywania tekstu w znakach na minutê
	return typingSpeed;
}