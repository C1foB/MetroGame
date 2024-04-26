// Metro.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Metro.h"
#include <thread>
#include <chrono>
#include <Windows.h>
using namespace std;



void clrscr()
{
	std::cout << "\033[2J";     // очистка экрана
	std::cout << "\033[0;0f";   // перемещение курсора в верхний левый угол
}

int consolex = 120;
int consoley = 28;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	setlocale(LC_ALL,"Russian");
	int w;
	Metro Mtr1;
	std::cout << "Введите количество станций " << endl;
	cin >> Mtr1.station;
	Mtr1.station = Mtr1.station - 1;
	for (int g = 0; g <= Mtr1.station; g++) {
		std::cout << "Введите позицию станции номер " << g << endl;
		cin >> Mtr1.stations[g];
	}
	Mtr1.speed = 1;
	Mtr1.head_x = 8;
	std::cout << "Введите количество вагонов ";
	cin >> Mtr1.length_of_train;
	Mtr1.length_of_train += 1;
	std::cout << "Введите номер пути поезда метро ";
	cin >> Mtr1.path;
	Mtr1.path -= 1;
	consoley = Mtr1.path + 1;
	std::cout << "Введите сложность(1 - 20) ";
	bool is_initialistet;
	is_initialistet = 0;
	system("cls");
	Mtr1.people = 999;
	bool ih;
	ih = false;
	int LiveTick = 0;
	while(ih != true){
		system("cls");
		std::cout << Mtr1.people << " чел." << endl;
		for (int cmdy = 0; cmdy < consoley; cmdy++) {
			for (int cmdx = 0; cmdx < consolex; cmdx++) {
				int trfl = Mtr1.is_it_train(cmdx, cmdy);
				if (trfl == 1) {
					SetConsoleTextAttribute(hConsole, 159);
					std::cout << "=";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (trfl != 1 && cmdy == Mtr1.path) {
					SetConsoleTextAttribute(hConsole, 135);
					std::cout << "-";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (trfl == 2) {
					SetConsoleTextAttribute(hConsole, 176);
					std::cout << "H";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (trfl == 200) {
					SetConsoleTextAttribute(hConsole, 255);
					std::cout << "#";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else { 
					SetConsoleTextAttribute(hConsole, 132);
					std::cout << " ";
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			std::cout << endl;
		}
		
		
		if (GetKeyState('S')) {
			Mtr1.speed = 0;
		}
		else if (GetKeyState('P')) {
			Mtr1.speed = 1;
		}
		else {
			w = 1;
		}
		if (Mtr1.head_x > 127)
			Mtr1.head_x = 1;
		else if (Mtr1.head_x < 2)
			Mtr1.head_x = 120;
		else w = 0;
		Mtr1.move();
		Sleep(100);
		if (Mtr1.isStation() == 1&&GetKeyState('O')) {
			Mtr1.inorout();
		}
		LiveTick++;
		if (LiveTick == 150) {
			ih = true;
		}
	}
	system("cls");
	cout << "Вы выйграли: " << 999 - Mtr1.people<<"!!!";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
