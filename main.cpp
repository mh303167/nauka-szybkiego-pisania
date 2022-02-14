/*
	Program do nauki szybkiego pisania na klawiaturze
	main.cpp
	@author Marcin Hajdecki
*/

#include <iostream> //u¿ywam, by korzystaæ ze standardowego wejœcia-wyjœcia
using namespace std;

void generateText(char*, int, int);
double getUserInput(char*, int);
int correctErrors(char*, char*, int);

int main()
{
	cout << "============================================================" << endl; 
	cout << "Witaj w programie do nauki szybkiego pisania na klawiaturze!" << endl; 
	cout << "============================================================" << endl;
	int wordNumber{}, wordLength{};
	cout << "Wprowadz liczbe slow: ";
	cin >> wordNumber; //pobiera od u¿ytkownika iloœæ s³ów w tekœcie do wygenerowania
	cout << "Wprowadz dlugosc slowa: ";
	cin >> wordLength; //pobiera od u¿ytkownika d³ugoœæ s³owa w tekœcie do wygenerowania
	int textLength = (wordLength + 1) * wordNumber - 1; //oblicza d³ugoœæ tekstu do wygenerowania
	int maxLessonScore{};
	bool nextLesson{};
	cout << "============================================================" << endl;
	do
	{
		char* lessonText = new char[textLength]; //tablica do przechowywania wygenerowanego tekstu
		char* userInput = new char[textLength]; //tablica do przechowywania tekstu wprowadzonego przez u¿ytkownika
		cout << "Przepisz ponizszy tekst: " << endl;
		generateText(lessonText, textLength, wordLength); //generuje tekst na podstawie zadanych parametrów
		double typingSpeed = getUserInput(userInput, textLength); //zwraca prêdkoœæ pisania w znakach na minutê
		int errorCounter = correctErrors(lessonText, userInput, textLength); //zwraca liczbê b³êdów w tekœcie wprowadzonym przez u¿ytkownika
		cout << "Predkosc pisania: " << typingSpeed << " znakow na minute" << endl;
		cout << "Liczba popelnionych bledow: " << errorCounter << endl;
		int lessonScore = 1000 * typingSpeed * ((double)textLength - errorCounter) / textLength; //oblicza wynik u¿ytkownika w taki sposób, ¿e u¿ytkownikowi bardziej op³aca siê pisaæ powoli, lecz starannie ni¿ szybko i z b³êdami
		cout << "WYNIK: " << lessonScore << endl;
		if (lessonScore > maxLessonScore)
			maxLessonScore = lessonScore; //jeœli nowy wynik jest najlepszy, nadpisuje najlepszy wynik
		cout << "NAJLEPSZY WYNIK : " << maxLessonScore << endl;
		delete[] lessonText, userInput;
		lessonText = nullptr;
		userInput = nullptr;
		cout << "============================================================" << endl;
		char tmp;
		while (true) //wykonuje siê dopóki u¿ytkownik nie wpisze "y" lub "n"
		{
			cin.ignore(10000, '\n');
			cout << "Czy chcesz kontynuowac? (y/n)" << endl;
			cin.get(tmp);
			if (tmp == 'y')
			{
				nextLesson = true; 
				break;
			}
			else if (tmp == 'n')
			{
				nextLesson = false;
				break;
			}
		}
		cout << "============================================================" << endl;
	} while (nextLesson); //sprawdza, co wybra³ u¿ytkownik
	cout << "Do zobaczenia!" << endl;
	system("pause");
}