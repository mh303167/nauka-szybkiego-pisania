/*
	Program do nauki szybkiego pisania na klawiaturze
	main.cpp
	@author Marcin Hajdecki
*/

#include <iostream> //u�ywam, by korzysta� ze standardowego wej�cia-wyj�cia
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
	cin >> wordNumber; //pobiera od u�ytkownika ilo�� s��w w tek�cie do wygenerowania
	cout << "Wprowadz dlugosc slowa: ";
	cin >> wordLength; //pobiera od u�ytkownika d�ugo�� s�owa w tek�cie do wygenerowania
	int textLength = (wordLength + 1) * wordNumber - 1; //oblicza d�ugo�� tekstu do wygenerowania
	int maxLessonScore{};
	bool nextLesson{};
	cout << "============================================================" << endl;
	do
	{
		char* lessonText = new char[textLength]; //tablica do przechowywania wygenerowanego tekstu
		char* userInput = new char[textLength]; //tablica do przechowywania tekstu wprowadzonego przez u�ytkownika
		cout << "Przepisz ponizszy tekst: " << endl;
		generateText(lessonText, textLength, wordLength); //generuje tekst na podstawie zadanych parametr�w
		double typingSpeed = getUserInput(userInput, textLength); //zwraca pr�dko�� pisania w znakach na minut�
		int errorCounter = correctErrors(lessonText, userInput, textLength); //zwraca liczb� b��d�w w tek�cie wprowadzonym przez u�ytkownika
		cout << "Predkosc pisania: " << typingSpeed << " znakow na minute" << endl;
		cout << "Liczba popelnionych bledow: " << errorCounter << endl;
		int lessonScore = 1000 * typingSpeed * ((double)textLength - errorCounter) / textLength; //oblicza wynik u�ytkownika w taki spos�b, �e u�ytkownikowi bardziej op�aca si� pisa� powoli, lecz starannie ni� szybko i z b��dami
		cout << "WYNIK: " << lessonScore << endl;
		if (lessonScore > maxLessonScore)
			maxLessonScore = lessonScore; //je�li nowy wynik jest najlepszy, nadpisuje najlepszy wynik
		cout << "NAJLEPSZY WYNIK : " << maxLessonScore << endl;
		delete[] lessonText, userInput;
		lessonText = nullptr;
		userInput = nullptr;
		cout << "============================================================" << endl;
		char tmp;
		while (true) //wykonuje si� dop�ki u�ytkownik nie wpisze "y" lub "n"
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
	} while (nextLesson); //sprawdza, co wybra� u�ytkownik
	cout << "Do zobaczenia!" << endl;
	system("pause");
}