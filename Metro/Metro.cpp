// Metro.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include "Metro.h"
#include <thread>
#include <chrono>
#include <Windows.h>

const int consolex = 120;
const int consoley = 29;

int main()
{
	int w;
	Metro Mtr1;
	Mtr1.speed = 1;
	Mtr1.head_x = 8;
	cout << "Enter the length of train >>";
	cin >> Mtr1.length_of_train;
	Mtr1.length_of_train += 1;
	cout << "Enter number of the path for train>>";
	cin >> Mtr1.path;
	Mtr1.path -= 1;
	system("cls");
	while(true){
		system("cls");
		for (int cmdy = 0; cmdy < consoley; cmdy++) {
			for (int cmdx = 0; cmdx < consolex; cmdx++) {
				int trfl = Mtr1.is_it_train(cmdx, cmdy);
				if (trfl == 1) {
					cout << "@";
				}
				else if (trfl != 1 && cmdy == Mtr1.path) {
					cout << "=";
				}
				else { cout << " ";}
			}
			cout << endl;
		}
		Mtr1.move();
		if (Mtr1.head_x < 2)
			Mtr1.head_x = 120;
		if (GetKeyState('P'))
			Mtr1.speed = 1;
		if (GetKeyState('S'))
			Mtr1.speed = 0;
		if (Mtr1.head_x > 127)
			Mtr1.head_x = 1;
		Sleep(300);
	}
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
